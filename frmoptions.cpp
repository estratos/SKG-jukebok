#include "frmoptions.h"
#include "ui_frmoptions.h"

frmOptions::frmOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmOptions)
{
    Option = OptionNone;
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(ui->btnArt,SIGNAL(clicked()),this,SLOT(btnArtPressed()));
    QObject::connect(ui->btnConfig,SIGNAL(clicked()),this,SLOT(btnConfigPressed()));
    QObject::connect(ui->btnRipper,SIGNAL(clicked()),this,SLOT(btnRipPressed()));
    QObject::connect(ui->btnCustomLists,SIGNAL(clicked()),this,SLOT(btnCustomListsPressed()));
    QObject::connect(ui->btnLoadPlaylist,SIGNAL(clicked()),this,SLOT(btnPlaylistPressed()));
    QObject::connect(ui->btnHelp,SIGNAL(clicked()),this,SLOT(btnHelpPressed()));
    QObject::connect(ui->btnSearch,SIGNAL(clicked()),this,SLOT(btnTrackSearchPressed()));
    QObject::connect(ui->btnAddToPlaylist,SIGNAL(clicked()),this,SLOT(btnAddToPlaylistPressed()));
    QObject::connect(ui->btnMinimize,SIGNAL(clicked()),this,SLOT(btnMinimizePressed()));
    QObject::connect(ui->btnAbout,SIGNAL(clicked()),this,SLOT(btnAboutPressed()));
    QObject::connect(ui->btnRescan,SIGNAL(clicked()),this,SLOT(btnRescanPressed()));
    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(btnExitPressed()));
}

frmOptions::~frmOptions()
{
    delete ui;
}

void frmOptions::changeEvent(QEvent *e)
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

void frmOptions::btnArtPressed()
{
    Option = OptionAlbumArt;
    accept();
}

void frmOptions::btnConfigPressed()
{
    Option = OptionConfig;
    accept();
}

void frmOptions::btnRipPressed()
{
    Option = OptionRipper;
    accept();
}

void frmOptions::btnCustomListsPressed()
{
    Option = OptionCustomLists;
    accept();
}

void frmOptions::btnPlaylistPressed()
{
    Option = OptionPlaylist;
    accept();
}

void frmOptions::btnHelpPressed()
{
    Option = OptionHelp;
    accept();
}

void frmOptions::btnTrackSearchPressed()
{
    Option = OptionTrackSearch;
    accept();
}

void frmOptions::btnAddToPlaylistPressed()
{
    Option = OptionAddToPlaylist;
    accept();
}

void frmOptions::btnMinimizePressed()
{
    Option = OptionMinimize;
    accept();
}

void frmOptions::btnExitPressed()
{
    Option = OptionExit;
    accept();
}

void frmOptions::btnAboutPressed()
{
    Option = OptionAbout;
    accept();
}

void frmOptions::btnRescanPressed()
{
    Option = OptionRescan;
    accept();
}
