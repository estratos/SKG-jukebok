#ifndef FRMLOADCUSTOMLIST_H
#define FRMLOADCUSTOMLIST_H

#include <QDialog>
#include "customalbumlist.h"
#include "customlistmanager.h"
#include "lib/skglib.h"

namespace Ui {
    class frmLoadCustomList;
}

class frmLoadCustomList : public QDialog {
    Q_OBJECT
public:
    frmLoadCustomList(QWidget *parent = 0);
    ~frmLoadCustomList();
    CustomAlbumList* GetSelectedList(){return SelectedList;}
    void Initialize(CustomListManager *listmanager,
                    CustomAlbumList *currlist,
                    SKG_MusicLibrary *lib);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmLoadCustomList *ui;
    CustomListManager *Manager;
    CustomAlbumList *SelectedList;
    SKG_MusicLibrary *Library;
    CustomAlbumList *OriginalList;

private slots:
    void ComboBoxItemChanged(int newindex);
    void ShowTrackListWarning();
};

#endif // FRMLOADCUSTOMLIST_H
