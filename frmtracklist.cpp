#include "frmtracklist.h"
#include "ui_frmtracklist.h"
#include "jukeboxconfig.h"
#include <QTime>
#include <time.h>

frmTrackList::frmTrackList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmTrackList)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnUp->setPixmap(QPixmap(UpArrow()));
    ui->btnDown->setPixmap(QPixmap(DownArrow()));

    CurrTrackNumber = 0;
    SavedTime = 0;
    LargeTrackNumbers = false;
    MetaDataObject = new Phonon::MediaObject(this);
    QObject::connect(MetaDataObject,SIGNAL(metaDataChanged()),this,SLOT(MetaDataResolved()));
    QObject::connect(ui->btnUp,SIGNAL(clicked()),this,SLOT(btnUp()));
    QObject::connect(ui->btnDown,SIGNAL(clicked()),this,SLOT(btnDown()));
    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(Cancel()));
    QObject::connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(SaveAndExit()));
    QObject::connect(ui->btnMoveTrackUp,SIGNAL(clicked()),this,SLOT(MoveTrackUpList()));
    QObject::connect(ui->btnMoveTrackDown,SIGNAL(clicked()),this,SLOT(MoveTrackDownList()));
    QObject::connect(ui->btmMoveToTop,SIGNAL(clicked()),this,SLOT(MoveToTop()));
    QObject::connect(ui->btnClearList,SIGNAL(clicked()),this,SLOT(ClearList()));
    QObject::connect(ui->btnRemoveTrack,SIGNAL(clicked()),this,SLOT(RemoveTrack()));
    QObject::connect(ui->btnPause,SIGNAL(clicked()),this,SLOT(Pause()));
    QObject::connect(ui->btnPlayNow,SIGNAL(clicked()),this,SLOT(PlayNow()));
    QObject::connect(ui->ListTracks,SIGNAL(currentRowChanged(int)),this,SLOT(SelectedTrackChanged(int)));
    QObject::connect(ui->btnShuffle,SIGNAL(clicked()),this,SLOT(ShuffleTracks()));
}

frmTrackList::~frmTrackList()
{
    delete ui;
}

void frmTrackList::changeEvent(QEvent *e)
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

void frmTrackList::Initialize(QList<SKG_Album*> albumlist,
                              Phonon::MediaObject *musicobj,
                              QList<long> &tracknumlist,
                              SKG_Track *currtrack,
                              bool largetracknums)
{
    LargeTrackNumbers = largetracknums;
    //Library = lib;
    Albums = albumlist;
    MusicObject = musicobj;
    TrackNumbers = tracknumlist;
    OriginalList = tracknumlist;
    CurrTrack = currtrack;
    //CurrTrackNumber = currtrack->GetTrackNumber();
    LoadListTracks();
    ui->ListTracks->setCurrentRow(0);
    //Phonon::MediaSource newsource(SelectedTrack()->GetFileName());
    //MetaDataObject->setCurrentSource(newsource);
}

void frmTrackList::btnUp()
{
    int prevrow = ui->ListTracks->currentRow() - 1;

    if (prevrow >= 0)
    {
        ui->ListTracks->setCurrentRow(prevrow);
    }
}

void frmTrackList::btnDown()
{
    int nextrow = ui->ListTracks->currentRow() + 1;

    if (nextrow <= ui->ListTracks->count() - 1)
    {
        ui->ListTracks->setCurrentRow(nextrow);
    }
}

void frmTrackList::MoveTrackUpList()
{
    int currow = ui->ListTracks->currentRow();

    if(currow >= 1)
    {
        TrackNumbers.swap(currow,currow - 1);
        LoadListTracks();
        ui->ListTracks->setCurrentRow(currow - 1);
        SelectedTrackChanged(ui->ListTracks->currentRow());
    }
}

void frmTrackList::MoveTrackDownList()
{
    int currow = ui->ListTracks->currentRow();

    if(currow <= TrackNumbers.count() - 2)
    {
        TrackNumbers.swap(currow,currow + 1);
        LoadListTracks();
        ui->ListTracks->setCurrentRow(currow + 1);
        SelectedTrackChanged(ui->ListTracks->currentRow());
    }
}

void frmTrackList::MoveToTop()
{
    int currow = ui->ListTracks->currentRow();

    if (currow > 0)
    {
        TrackNumbers.move(currow,0);
        LoadListTracks();
    }
}

void frmTrackList::RemoveTrack()
{
    int currow = ui->ListTracks->currentRow();

    TrackNumbers.removeAt(currow);
    LoadListTracks();
}

void frmTrackList::ClearList()
{
    SavedSource = MusicObject->currentSource();
    SavedTime = MusicObject->currentTime();
    Phonon::MediaSource emptysource("");
    MusicObject->setCurrentSource(emptysource);
    TrackNumbers.clear();
    CurrTrackNumber = 0;
    CurrTrack = NULL;
    ui->ListTracks->clear();
}

void frmTrackList::Pause()
{
    if (MusicObject->state() == Phonon::PlayingState)
    {
        MusicObject->pause();
        ui->btnPause->setText("Resume Current Track");
    }
    else if (MusicObject->state() == Phonon::PausedState)
    {
        MusicObject->play();
        ui->btnPause->setText("Pause Current Track");
    }
}

void frmTrackList::PlayNow()
{
    int currow = ui->ListTracks->currentRow();
    if(currow >= 0)
    {
        SavedSource = MusicObject->currentSource();
        SavedTime = MusicObject->currentTime();
        //SKG_Track *currtrack = Library->GetTrackByNumber(TrackNumbers.at(currow));
        SKG_Track *currtrack = TrackByNumber(TrackNumbers.at(currow));
        CurrTrack = currtrack;
        CurrTrackNumber = TrackNumbers.at(currow);
        TrackNumbers.removeAt(currow);
        LoadListTracks();
        Phonon::MediaSource newsource(currtrack->GetFileName());
        MusicObject->setCurrentSource(newsource);
        MusicObject->play();
    }
}

void frmTrackList::MetaDataResolved()
{
    QStringList metadata;
    QString item;
    int albumnum;
    SKG_Album *album;
    int w,h;

    item = QString("Artist: ");
    //item.append(MetaDataObject->metaData("ARTIST").at(0))
    if (MetaDataObject->metaData(Phonon::ArtistMetaData).count() > 0)
    {
        item.append(MetaDataObject->metaData(Phonon::ArtistMetaData).at(0));
        metadata.append(item);
    }

    item = QString("Title: ");
    if (MetaDataObject->metaData(Phonon::TitleMetaData).count() > 0)
    {
        item.append(MetaDataObject->metaData(Phonon::TitleMetaData).at(0));
        metadata.append(item);
    }

    item = QString("Album: ");
    if (MetaDataObject->metaData(Phonon::AlbumMetaData).count() > 0)
    {
        item.append(MetaDataObject->metaData(Phonon::AlbumMetaData).at(0));
        metadata.append(item);
    }

    item = QString("Date: ");
    if (MetaDataObject->metaData(Phonon::DateMetaData).count() > 0)
    {
        item.append(MetaDataObject->metaData(Phonon::DateMetaData).at(0));
        metadata.append(item);
    }

    item = QString("Playing Time: ");
    QTime playingtime(0,(MetaDataObject->totalTime() / 60000) % 60,(MetaDataObject->totalTime() / 1000) % 60);
    item.append(playingtime.toString("mm:ss"));
    metadata.append(item);

    ui->lblMetaData->setText(metadata.join("\n"));
    albumnum = TrackNumbers.at(ui->ListTracks->currentRow()) / 100;
    //album = Library->GetAlbumByNumber(albumnum);
    album = Albums.at(albumnum - 1);
    w = ui->lblArt->width();
    h = ui->lblArt->height();
    ui->lblArt->clear();
    ui->lblArt->setPixmap(QPixmap(album->GetCoverArt()).scaledToWidth(w).scaledToHeight(h));
    //ui->lblArt->setPixmap(QPixmap(album->GetCoverArt()).scaledToWidth(ui->lblArt->width()).scaledToHeight(ui->lblArt->height()));
}

void frmTrackList::Cancel()
{
    CurrTrackNumber = 0;
    if (SavedSource.fileName() != "")
    {
        MusicObject->setCurrentSource(SavedSource);
        MusicObject->play();
        MusicObject->seek(SavedTime);
    }
    TrackNumbers = OriginalList;
    this->reject();
}

void frmTrackList::SaveAndExit()
{
    this->accept();
}

void frmTrackList::LoadListTracks()
{
    int i;
    SKG_Track *currtrack;

    ui->ListTracks->clear();
    for (i = 0;i < TrackNumbers.count();i++)
    {
        //currtrack = Library->GetTrackByNumber(TrackNumbers.at(i));
        currtrack = TrackByNumber(TrackNumbers.at(i));
        ui->ListTracks->addItem(currtrack->GetTrackNameSansNumber());
    }
}

SKG_Track* frmTrackList::SelectedTrack()
{
    return TrackByNumber(TrackNumbers.at(ui->ListTracks->currentRow()));
}

void frmTrackList::SelectedTrackChanged(int row)
{
    if (row < 0)
        return;

    Phonon::MediaSource newsource(SelectedTrack()->GetFileName());
    MetaDataObject->setCurrentSource(newsource);
}

SKG_Track* frmTrackList::TrackByNumber(long tracknum)
{
    int albumnumber;
    int tracknumber;

    albumnumber = tracknum / 100;
    tracknumber = tracknum % 100;
    return Albums.at(albumnumber - 1)->GetTracks().at(tracknumber);
}

void frmTrackList::ShuffleTracks()
{
    int numtimes = 0;
    int rnd;
    qsrand(time(NULL));
    while (numtimes < 5)
    {
        for (int i = 0;i < TrackNumbers.count();i++)
        {
            rnd = qrand() % TrackNumbers.count();
            TrackNumbers.swap(i,rnd);
        }
        numtimes++;
    }
    LoadListTracks();
}
