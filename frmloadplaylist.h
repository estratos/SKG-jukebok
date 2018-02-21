#ifndef FRMLOADPLAYLIST_H
#define FRMLOADPLAYLIST_H

#include <QDialog>
#include "playlist.h"
#include "playlistmanager.h"
#include "lib/skglib.h"

namespace Ui {
    class frmLoadPlaylist;
}

class frmLoadPlaylist : public QDialog {
    Q_OBJECT
public:
    frmLoadPlaylist(QWidget *parent = 0);
    ~frmLoadPlaylist();
    QList <int> *GetTrackNumbers();
    void Initialize(PlaylistManager *pmanager,
                    SKG_MusicLibrary *lib);
    Playlist *GetSelectedList(){return SelectedList;}
    bool RandomOrder();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmLoadPlaylist *ui;
    PlaylistManager *Manager;
    Playlist *SelectedList;
    SKG_MusicLibrary *Library;

private slots:
    void ComboBoxItemChanged(int newindex);
};

#endif // FRMLOADPLAYLIST_H
