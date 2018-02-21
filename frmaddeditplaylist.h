#ifndef FRMADDEDITPLAYLIST_H
#define FRMADDEDITPLAYLIST_H

#include <QDialog>
#include <QSet>
#include <QTreeWidgetItem>
#include "lib/skglib.h"
#include "customalbumlist.h"
#include "playlist.h"

namespace Ui {
    class frmAddEditPlaylist;
}

class frmAddEditPlaylist : public QDialog {
    Q_OBJECT
public:
    frmAddEditPlaylist(QWidget *parent = 0);
    ~frmAddEditPlaylist();
    Playlist* GetPlaylist();
    void ProcessAddList(SKG_MusicLibrary *lib,CustomAlbumList *list = NULL);
    void ProcessEditList(SKG_MusicLibrary *lib, Playlist *plist,CustomAlbumList *list = NULL);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmAddEditPlaylist *ui;
    Playlist *List;
    SKG_MusicLibrary *Library;
    QList <long> *TracksToAdd;
    CustomAlbumList *CustomList;

    void DisplayAvailableTracks();
    void DisplayTracksInList();
    void RefreshLists();

    SKG_Artist *ArtistByName(QList <SKG_Artist*> artistlist,QString artistname);
    SKG_Album *AlbumByName(QList <SKG_Album*> albumlist,QString artistname,QString albumname);

private slots:
    void AddTracksToList();
    void RemoveTracksFromList();
    void ProcessItemChecked(QTreeWidgetItem *item, int column);
    void btnSaveClicked();
    void MoveTrackUp();
    void MoveTrackDown();
    void KeyPressed(int keycode,bool shift);
    void ShowKeyboard();
};

#endif // FRMADDEDITPLAYLIST_H
