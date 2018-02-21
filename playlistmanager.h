#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <QObject>
#include "playlist.h"
#include "lib/skglib.h"
#include <QDomDocument>
#include <QDomElement>

class PlaylistManager : public QObject
{
Q_OBJECT
public:
    explicit PlaylistManager(QObject *parent = 0);

public:
    QList <Playlist*> GetPlaylists();

    void AddList(Playlist *list){Playlists.append(list);}
    void RemoveList(int listindex);
    void SavePlaylistFile();
    void SetLibrary(SKG_MusicLibrary *lib);
    Playlist* RetrieveListByName(QString listname);
    int ListCount(){return Playlists.count();}

private:
   QList <Playlist*> Playlists;
   QString PlaylistFile;
   SKG_MusicLibrary *Library;

   void LoadPlaylistFile();
   void Sort();
   void CreateTestList();

};

#endif // PLAYLISTMANAGER_H
