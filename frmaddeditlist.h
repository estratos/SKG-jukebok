#ifndef FRMADDEDITLIST_H
#define FRMADDEDITLIST_H

#include <QDialog>
#include <QSet>
#include <QTreeWidgetItem>
#include "lib/skglib.h"
#include "customalbumlist.h"

namespace Ui {
    class frmAddEditList;
}

class frmAddEditList : public QDialog {
    Q_OBJECT
public:
    frmAddEditList(QWidget *parent = 0);
    ~frmAddEditList();
    CustomAlbumList* GetAlbumList(){return AlbumList;}
    void ProcessAddList(SKG_MusicLibrary *lib);
    void ProcessEditList(SKG_MusicLibrary *lib, CustomAlbumList *list);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmAddEditList *ui;
    CustomAlbumList *AlbumList;
    SKG_MusicLibrary *Library;
    QList <SKG_Artist*> AvailableArtists;
    QList <SKG_Artist*> ArtistsInList;
    QList <SKG_Album*> AvailableAlbums;
    QList <SKG_Album*> AlbumsInList;

    void DisplayAvailableAlbums();
    void DisplayAlbumsInList();
    void RefreshLists();

    SKG_Artist *ArtistByName(QList <SKG_Artist*> artistlist,QString artistname);
    SKG_Album *AlbumByName(QList <SKG_Album*> albumlist,QString artistname,QString albumname);

private slots:
    void AddAlbumsToList();
    void RemoveAlbumsFromList();
    void ProcessItemChecked(QTreeWidgetItem *item, int column);
    void btnSaveClicked();
    void KeyPressed(int keycode,bool shift);
    void ShowKeyboard();
};

#endif // FRMADDEDITLIST_H
