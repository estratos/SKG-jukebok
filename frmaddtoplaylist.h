#ifndef FRMADDTOPLAYLIST_H
#define FRMADDTOPLAYLIST_H

#include <QDialog>
#include "playlistmanager.h"
#include "lib/skglib.h"

namespace Ui {
    class FrmAddToPlaylist;
}

class FrmAddToPlaylist : public QDialog {
    Q_OBJECT

private:
    PlaylistManager *Manager;
    SKG_Track *Track;
    long TrackNumber;

public:
    FrmAddToPlaylist(QWidget *parent = 0);
    ~FrmAddToPlaylist();

    void Initialize(PlaylistManager *manager,SKG_Track *track,long tracknum);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FrmAddToPlaylist *ui;

private slots:
    void AddTrack();
    void SelectAll(int state);
};

#endif // FRMADDTOPLAYLIST_H
