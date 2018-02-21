#ifndef FREEDBLOOKUP_H
#define FREEDBLOOKUP_H

#include <QObject>
#include <QTcpSocket>
#include <QStringList>

enum FreeDBStage{
    fdbsInit,
    fdbsConnect,
    fdbsHello,
    fdbsDiscId,
    fdbsQuery,
    fdbsRead
};

const int cFRAMES_PER_SECOND = 75;

class FreeDBLookup : public QObject
{
    Q_OBJECT
public:
    explicit FreeDBLookup(QObject *parent = 0);
    void Lookup(QList <int>,int totaltime);

    QString GetArtist(){return Artist;}
    QString GetAlbum(){return Album;}
    QString GetGenre(){return Genre;}
    int GetYear(){return Year;}
    QStringList GetTracks(){return Tracks;}
    int GetTotalRunningTime(){return TotalRunningTime;}

private:
    QList <int> Offsets;
    int TotalTime;

    FreeDBStage currStage;
    QTcpSocket *Socket;
    unsigned long DiscID;
    QString Artist;
    QString Album;
    QString Genre;
    int Year;
    QStringList Tracks;
    QStringList QueryResult;
    int TotalRunningTime;
    void Clear();

    int CalculateDiscID(QList <int> offsets,int totaltime);
    int FreeDBSum(int runningtime);

    void ConnectToFreeDB();
    void SendHello();
    void SendCalcDiscId();
    void SendQuery();
    void SendRead(QString category,QString id);
    void ReadDiscInfo(QString readstr);

public slots:
    void DataReady();
    void SocketError(QAbstractSocket::SocketError socketError );

signals:
    void Connected();
    void Disconnected();
    void LookupMessage(QString msg);
    void LookupFinished();
    void LookupError(QString errmsg);
};

#endif // FREEDBLOOKUP_H
