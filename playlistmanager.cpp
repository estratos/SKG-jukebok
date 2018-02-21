#include "playlistmanager.h"
#include "jukeboxconfig.h"
#include <QTextStream>
#include <stdlib.h>
#include <time.h>
#include <QMessageBox>

PlaylistManager::PlaylistManager(QObject *parent) :
    QObject(parent)
{
    PlaylistFile = ResourcesDirectory() + "/playlists.xml";
}


QList <Playlist*> PlaylistManager::GetPlaylists()
{
    Sort();
    return Playlists;
}

void PlaylistManager::RemoveList(int listindex)
{
    if (listindex < Playlists.count())
        Playlists.removeAt(listindex);
}

void PlaylistManager::SavePlaylistFile()
{
    SKG_Album *curralbum;
    Playlist *currlist;
    int tracknum;
    int i,j;
    QDomDocument doc;
    QDomElement mainelement;
    QDomElement countelement;
    QDomElement listelement;
    QDomElement nameelement;
    QDomElement custlistnameelement;
    QDomElement trackelement;

    if(QFile::exists(PlaylistFile))
        QFile::remove(PlaylistFile);

    QFile listfile(PlaylistFile);
    listfile.open(QIODevice::WriteOnly);

    mainelement = doc.createElement("Playlists");
    countelement = doc.createElement("count");
    countelement.setAttribute("count",Playlists.count());
    mainelement.appendChild(countelement);

    for (i = 0; i < Playlists.count(); i++)
    {
        listelement = doc.createElement("list");
        currlist = Playlists.at(i);
        nameelement = doc.createElement("name");
        nameelement.setAttribute("name",currlist->GetName());
        listelement.appendChild(nameelement);
        custlistnameelement = doc.createElement("custlistname");
        custlistnameelement.setAttribute("custlistname",currlist->GetCustomListName());
        listelement.appendChild(custlistnameelement);

        for(j = 0; j < currlist->GetTrackNumbers(false)->count();j++)
        {
            curralbum = Library->GetAlbumByNumber(currlist->GetTrackNumbers(false)->at(j) / 100);
            tracknum = currlist->GetTrackNumbers(false)->at(j) % 100;
            trackelement = doc.createElement("track");
            trackelement.setAttribute("artist",curralbum->GetArtistName());
            trackelement.setAttribute("albumname",curralbum->GetAlbumName());
            trackelement.setAttribute("tracknum",tracknum);
            listelement.appendChild(trackelement);
        }
        //doc.appendChild(listelement);
        mainelement.appendChild(listelement);
    }
    doc.appendChild(mainelement);
    listfile.write(doc.toByteArray());
    listfile.close();
}

void PlaylistManager::LoadPlaylistFile()
{
    QDomDocument doc;
    QDomNodeList listnodes;
    QDomElement listelement;
    QDomElement nameelement;
    QDomElement custlistnameelement;
    QDomNodeList tracknodes;
    QDomElement trackelement;
    QString artistname;
    QString albumname;
    int tracknum;

    bool x;
    QString errmsg;
    int errline;
    Playlist *currlist;
    SKG_Album *curralbum;
    int i,j;

    if (!QFile::exists(PlaylistFile))
        return;

    QFile listfile(PlaylistFile);
    listfile.open(QIODevice::ReadOnly);
    x = doc.setContent(listfile.readAll(),&errmsg,&errline);
    listnodes = doc.elementsByTagName("list");

    for (i = 0; i < listnodes.count(); i++)
    {
        listelement = listnodes.at(i).toElement();
        currlist = new Playlist;
        nameelement = listelement.firstChildElement("");
        currlist->SetName(nameelement.attribute("name",""));
        currlist->SetCustomListName(nameelement.attribute("custlistname",""));

        QList <int> tracknums;
        tracknodes = listelement.elementsByTagName("track");
        for (j = 0; j< tracknodes.length(); j++)
        {
            trackelement = tracknodes.at(j).toElement();
            artistname = trackelement.attribute("artist","");
            albumname = trackelement.attribute("albumname");
            tracknum = trackelement.attribute("tracknum").toInt();
            curralbum = Library->GetAlbumByName(artistname,albumname);
            if (curralbum != NULL)
            {
                currlist->AddTrackNumber((curralbum->GetAlbumNumber() * 100) + tracknum);
            }
        }
        Playlists.append(currlist);
    }
    listfile.close();
}

Playlist* PlaylistManager::RetrieveListByName(QString listname)
{
    foreach (Playlist *list,Playlists)
    {
        if (list->GetName() == listname)
        {
            return list;
            break;
        }
    }
    return NULL;
}

void PlaylistManager::SetLibrary(SKG_MusicLibrary *lib)
{
    Library = lib;
    LoadPlaylistFile();
    //CreateTestList();
    //SavePlaylistFile();
}

void PlaylistManager::CreateTestList()
{
    int i;
    int albumnum;
    int tracknum;
    SKG_Album *album;
    bool exists;
    Playlist *testlist;
    QList<int> list;
    //int x,y;

    srand(time(0));
    testlist = new Playlist;
    testlist->SetName("Test");
    while(list.count() < 20)
    {
        albumnum = (qrand() % Library->GetAlbums().count());
        album = Library->GetAlbumByNumber(albumnum);
        tracknum = (qrand() % (album->GetTracks().count() - 1)) + 1;
        //x=qrand();
        //y=Library->GetAlbums().count();
        //tracknum = (x % album->GetTracks().count());
        tracknum = (albumnum * 100) + tracknum;
        exists = false;
        for(i = 0; i < list.count(); i++)
        {
            if (list.at(i) == tracknum)
                exists = true;
        }
        if (!exists)
        {
            list.append(tracknum);
            testlist->AddTrackNumber(tracknum);
        }
    }
    Playlists.append(testlist);
}

void PlaylistManager::Sort()
{
    int i,j;

    for (i = 0; i < Playlists.count() - 1; i++)
    {
        for (j = i + 1; j < Playlists.count(); j++)
            if (Playlists.at(i)->GetName() < Playlists.at(j)->GetName())
                Playlists.swap(i,j);
    }
}
