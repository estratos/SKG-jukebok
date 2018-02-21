#ifndef FRMALBUMARTDIALOG_H
#define FRMALBUMARTDIALOG_H

#include <QDialog>

enum ArtDialogOption
{
    ArtOptionDownload,
    ArtOptionFromFile
};

namespace Ui {
    class frmAlbumArtDialog;
}

class frmAlbumArtDialog : public QDialog {
    Q_OBJECT
public:
    frmAlbumArtDialog(QWidget *parent = 0);
    ~frmAlbumArtDialog();

    ArtDialogOption Option();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmAlbumArtDialog *ui;
};

#endif // FRMALBUMARTDIALOG_H
