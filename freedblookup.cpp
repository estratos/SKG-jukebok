#include "freedblookup.h"
//#include <QApplication>
#include <QEventLoop>

FreeDBLookup::FreeDBLookup(QObject *parent) :
    QObject(parent)
{
    Socket = new QTcpSocket(this);

    QObject::connect(Socket,SIGNAL(connected()),this,SIGNAL(Connected()));
    QObject::connect(Socket,SIGNAL(readyRead()),this,SLOT(DataReady()));
    QObject::connect(Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(SocketError(QAbstractSocket::SocketError)));
    QObject::connect(Socket,SIGNAL(disconnected()),this,SIGNAL(Disconnected()));
}

int FreeDBLookup::FreeDBSum(int runningtime)
{
    int ret = 0;

    while (runningtime > 0) {
        ret = ret + (runningtime % 10);
        runningtime = runningtime / 10;
    }
    return (ret);
}

int FreeDBLookup::CalculateDiscID(QList <int> offsets,int totaltime)
{
    int n = 0;

    for (int i = 0;i < offsets.count();i++) {
        n = n + FreeDBSum(offsets.at(i) / cFRAMES_PER_SECOND);
    }
    return ((n % 0xff) << 24 | totaltime << 8 | offsets.count());
}

void FreeDBLookup::Clear()
{
    Artist = "";
    Album = "";
    Genre = "";
    Year = 0;
    Tracks.clear();
    TotalRunningTime = 0;
}

void FreeDBLookup::Lookup(QList <int> offsets,int totaltime)
{
    Clear();
    Offsets = offsets;
    TotalTime = totaltime;
    DiscID = CalculateDiscID(offsets,totaltime);
    currStage = fdbsInit;
    ConnectToFreeDB();
}

void FreeDBLookup::ConnectToFreeDB()
{
    QEventLoop evloop;
    Socket->connectToHost("freedb.freedb.org",8880,QIODevice::ReadWrite);

    while(!(Socket->state() == QAbstractSocket::ConnectedState))
    {
        evloop.processEvents();
    }
    //SendHello();
}

void FreeDBLookup::SendHello()
{
    int x;
    bool y;
    currStage = fdbsHello;
    QString hellostr = "cddb hello anonymous localhost SKG_Jukebox 0.7\n";
    //Socket->readAll();
    y = (Socket->state() == QAbstractSocket::ConnectedState);
    x = Socket->write(hellostr.toAscii());
    //Socket->waitForReadyRead(-1);
}

void FreeDBLookup::SendQuery()
{
    QString query = "cddb query ";

    query += QString("%1 %2 ").arg(DiscID,0,16).arg(Offsets.count());
    for(int i = 0;i < Offsets.count();i++)
    {
        query += QString::number(Offsets.at(i)) + " ";
    }
    query += QString::number(TotalTime);
    query +="\n";

    QueryResult.clear();
    currStage = fdbsQuery;
    bool x = (Socket->state() == QAbstractSocket::ConnectedState);
    Socket->write(query.toAscii());
}

void FreeDBLookup::SendRead(QString category,QString id)
{
    QString readstr = QString("cddb read %1 %2\n").arg(category).arg(id);
    currStage = fdbsRead;
    Socket->write(readstr.toAscii());
}

void FreeDBLookup::ReadDiscInfo(QString readstr)
{
    QStringList readresult = readstr.split("\n",QString::SkipEmptyParts);
    QString xmcd = readresult.at(1);
    bool validread = (xmcd.left(6) == "# xmcd");
    if (validread)
    {
        QString nextline;
        int i;
        QStringList tracktitles;
        int posequals;
        int runningtime;
        QString runningtimestr;

        for (i = 0;i < readresult.count();i++)
        //while ((nextline = readresult.at(++i)) != NULL)
        {
            nextline = readresult.at(i);
            if (nextline == NULL)
                return;

            if (nextline.toLower().contains("disc length"))
            {
                int poscolon = nextline.indexOf(":");
                nextline = nextline.mid(poscolon + 1);
                int posseconds = nextline.indexOf("seconds");
                nextline = nextline.left(posseconds - 1);
                TotalRunningTime = nextline.trimmed().toInt();
            }
            else if(nextline.left(7) == "DTITLE=")
            {
                nextline = nextline.mid(7);
                QStringList artistalbum = nextline.split("/");
                Artist = artistalbum.at(0).trimmed();
                Album = artistalbum.at(1).trimmed();
            }
            else if (nextline.contains("DGENRE="))
            {
                Genre = nextline.mid(6).trimmed();
            }
            else if (nextline.contains("DYEAR="))
            {
                Year = nextline.mid(5).trimmed().toInt();
            }
            else if (nextline.contains("TTITLE"))
            {
                posequals = nextline.indexOf("=");
                nextline = nextline.mid(posequals + 1);
                nextline = nextline.replace("/","-");
                tracktitles.append(nextline.trimmed());
            }
        }
        for (i = 0;i < tracktitles.count();i++)
        {
            Tracks.append(QString("%1 %2").arg(tracktitles.at(i)).arg(runningtimestr));
        }
        Socket->close();
        LookupFinished();
    }
    else
    {
        LookupError(readstr);
    }
}

void FreeDBLookup::DataReady()
{
    QByteArray resp = Socket->readAll();
    QString respstr = QString(resp);
    int respcode = respstr.left(3).toInt();
    static QString readstr;

    if (currStage == fdbsInit)
    {
        if (respcode == 200)
        {
            LookupMessage(respstr);
            SendHello();
        }
        else if (respcode == 201)
        {
            LookupMessage(respstr);
            SendHello();
        }
    }
    else if (currStage == fdbsHello)
    {
        LookupMessage(respstr);

        if (respcode == 200)
        {
            //SendQuery();
            SendCalcDiscId();
        }
    }
    else if (currStage == fdbsDiscId)
    {
        LookupMessage(respstr);
        if (respcode == 200)
        {
            QStringList l = respstr.split(" ");
            bool ok;
            DiscID = l.at(l.count() - 1).toULong(&ok,16);
            SendQuery();
        }

    }
    else if(currStage == fdbsQuery)
    {
        LookupMessage(respstr);
        readstr = "";

        if(respcode == 200) // Perfect match found
        {
            QueryResult = respstr.split(" ");
            SendRead(QueryResult.at(1),QueryResult.at(2));
            //SendRead(QueryResult.at(QueryResult.count() - 2),QueryResult.at(QueryResult.count() - 1));
        }
        else if((respcode == 211) || (respcode == 210))
        {
            QueryResult = respstr.split("\n");
            QString firstresult = QueryResult.at(1);
            QStringList firstresultlist = firstresult.split(" ");
            SendRead(firstresultlist.at(0),firstresultlist.at(1));
        }

    }
    else if (currStage == fdbsRead)
    {
        readstr += respstr;
        readstr = readstr.trimmed();
        //hLookupMessage(respstr);
        if (readstr.right(1) == ".")
            ReadDiscInfo(readstr.trimmed());
    }
}

void FreeDBLookup::SocketError(QAbstractSocket::SocketError socketError )
{
    LookupError(Socket->errorString());
}

void FreeDBLookup::SendCalcDiscId()
{
    QString discquery = "discid ";

    discquery += QString("%1 ").arg(Offsets.count());
    for(int i = 0;i < Offsets.count();i++)
    {
        discquery += QString::number(Offsets.at(i)) + " ";
    }
    discquery += QString::number(TotalTime);
    discquery +="\n";

    currStage = fdbsDiscId;
    Socket->write(discquery.toAscii());
}
