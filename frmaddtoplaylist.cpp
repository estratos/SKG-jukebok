#include "frmaddtoplaylist.h"
#include "ui_frmaddtoplaylist.h"
#include <QMessageBox>

FrmAddToPlaylist::FrmAddToPlaylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmAddToPlaylist)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(AddTrack()));
    QObject::connect(ui->chkSelectAll,SIGNAL(stateChanged(int)),this,SLOT(SelectAll(int)));
}

FrmAddToPlaylist::~FrmAddToPlaylist()
{
    delete ui;
}

void FrmAddToPlaylist::changeEvent(QEvent *e)
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

void FrmAddToPlaylist::Initialize(PlaylistManager *manager,
                                  SKG_Track *track,
                                  long tracknum)
{
    QListWidgetItem *item;

    Manager = manager;
    Track = track;
    TrackNumber = tracknum;

    for (int i = 0; i < Manager->ListCount(); i++)
    {
        item = new QListWidgetItem(Manager->GetPlaylists().at(i)->GetName());
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item->setCheckState(Qt::Unchecked);
        ui->listPlaylists->addItem(item);
    }

    ui->lblInstructions->setText("Which playlist(s) would you like to add the current track," +
                                 Track->GetTrackNameSansNumber() + " to?");
}

void FrmAddToPlaylist::AddTrack()
{
    QStringList l;
    Playlist *currlist;

    for (int i = 0; i < Manager->GetPlaylists().count(); i++)
    {
        if (ui->listPlaylists->item(i)->checkState() == Qt::Checked)
        {
            currlist = Manager->GetPlaylists().at(i);
            currlist->AddTrackNumber(TrackNumber);
            l.append(currlist->GetName());
        }
    }
    Manager->SavePlaylistFile();
    QMessageBox box;
    box.setText(Track->GetTrackName() + " added to playlist(s)\n" + l.join("\n"));
    box.exec();
    accept();
}

void FrmAddToPlaylist::SelectAll(int state)
{
    for (int i = 0; i < ui->listPlaylists->count(); i++)
    {
        if (state == Qt::Checked)
        {
            ui->listPlaylists->item(i)->setCheckState(Qt::Checked);
            ui->listPlaylists->setEnabled(false);
        }
        else
        {
            ui->listPlaylists->setEnabled(true);
        }
    }
}
