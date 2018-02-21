#include "frmloadplaylist.h"
#include "ui_frmloadplaylist.h"

frmLoadPlaylist::frmLoadPlaylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmLoadPlaylist)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QObject::connect(ui->btnLoad,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(reject()));
}

frmLoadPlaylist::~frmLoadPlaylist()
{
    delete ui;
}

void frmLoadPlaylist::changeEvent(QEvent *e)
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

QList <int>* frmLoadPlaylist::GetTrackNumbers()
{
    return SelectedList->GetTrackNumbers(ui->chkRandom->isChecked());
}

void frmLoadPlaylist::Initialize(PlaylistManager *pmanager,
                                   SKG_MusicLibrary *lib)
{
    int i;
    int currlistindex;

    Manager = pmanager;
    ui->cmbPlaylists->clear();
    currlistindex = 0;
    for (i = 0; i < Manager->GetPlaylists().count(); i++)
    {
        ui->cmbPlaylists->addItem(Manager->GetPlaylists().at(i)->GetName() + " -- "
                             + QString::number(Manager->GetPlaylists().at(i)->GetTrackNumbers(false)->count())
                              + " Tracks");
    }
    //SelectedList = currlist;
    Library = lib;
    QObject::connect(ui->cmbPlaylists,SIGNAL(currentIndexChanged(int)),this,SLOT(ComboBoxItemChanged(int)));
    ComboBoxItemChanged(0);
}

void frmLoadPlaylist::ComboBoxItemChanged(int newindex)
{
    int i;
    Playlist *currlist;
    QStringList strlist;
    SKG_Track *currtrack;

    if(newindex == -1)
        return;

    ui->txtTracks->clear();
    currlist = Manager->GetPlaylists().at(newindex);

    SelectedList = currlist;
    strlist.clear();
    if (currlist == NULL)
    {
        //strlist.append("");
    }
    else
    {
        for (i = 0; i < currlist->GetTrackNumbers(false)->count(); i++)
        {
            //curralbum = Library->GetAlbumByNumber(currlist->GetAlbumNumbers().at(i));
            currtrack = Library->GetTrackByNumber(currlist->GetTrackNumbers(false)->at(i));
            strlist.append(currtrack->GetTrackName());
        }
    }
    ui->txtTracks->setText(strlist.join("\n"));
}

bool frmLoadPlaylist::RandomOrder()
{
    return (ui->chkRandom->isChecked());
}
