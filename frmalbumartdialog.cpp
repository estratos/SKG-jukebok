#include "frmalbumartdialog.h"
#include "ui_frmalbumartdialog.h"

frmAlbumArtDialog::frmAlbumArtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmAlbumArtDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    //this->windowTitle().remove();

    ui->rbDownload->setChecked(true);
    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(ui->btnOK,SIGNAL(clicked()),this,SLOT(accept()));
}

frmAlbumArtDialog::~frmAlbumArtDialog()
{
    delete ui;
}

void frmAlbumArtDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

ArtDialogOption frmAlbumArtDialog::Option()
{
    if(ui->rbDownload->isChecked())
        return ArtOptionDownload;
    else
        return ArtOptionFromFile;
}
