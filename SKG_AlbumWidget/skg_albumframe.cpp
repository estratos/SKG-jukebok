#include "skg_albumframe.h"
#include "ui_skg_albumframe.h"
#include "../lib/skglib.h"

SKG_AlbumFrame::SKG_AlbumFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SKG_AlbumFrame)
{
    ui->setupUi(this);
}

SKG_AlbumFrame::~SKG_AlbumFrame()
{
    delete ui;
}

void SKG_AlbumFrame::changeEvent(QEvent *e)
{
    QFrame::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

// Loads the album into the widget, displaying the album art, artist name, album name
// and list of tracks in the appropriate contols.
void SKG_AlbumFrame::LoadAlbum(SKG_Album *album,bool largealbumnumbers)
{
    QPixmap albumart;
    QString stralbumnum;
    bool necessary;
    QString strtoadd;

    ui->lblAlbumName->setText(album->GetAlbumName());
    ui->lblArtistName->setText(album->GetArtistName());
    stralbumnum = QString::number(album->GetAlbumNumber());
    if (largealbumnumbers)
        stralbumnum = QString("%1").arg(stralbumnum,4,'0');
    else
        stralbumnum = QString("%1").arg(stralbumnum,3,'0');

    // Convert the 3 digit album number into a string, and disply it in the label above the track list
    ui->lblAlbumNumber->setText(stralbumnum);

    // Create a QPixmap object out of the picture file, and load it into the album cover label
    albumart=QPixmap(album->GetCoverArt());
    ui->lblAlbumCover->setPixmap(album->GetCoverArt());

    necessary = AlbumNumbersNecessary(album);
    ui->listTracks->clear();
    foreach(SKG_Track *currtrack,album->GetTracks())
    {
        ui->listTracks->addItem(currtrack->GetTrackName());
    }
}

void SKG_AlbumFrame::EnableControls()
{
    ui->listTracks->setEnabled(true);
    ui->listTracks->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->listTracks->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void SKG_AlbumFrame::DisableControls()
{
    ui->listTracks->setDisabled(true);
    ui->listTracks->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listTracks->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QListWidget* SKG_AlbumFrame::listTracks()
{
    return ui->listTracks;
}

// When resizing the widget, want to keep the album art label a square, so we set the size
// of the art label to the height of the control minus the 50 pixels, or half the width,
// whichever is less.
void SKG_AlbumFrame::ResizeFrame(QSize newsize)
{
     int coversize;
     int listleft;
     int listwidth;

     if ((newsize.width()/2) < (newsize.height() - 50))
         coversize = newsize.width() / 2;
     else
         coversize = newsize.height() - 50;

     listleft = coversize + 15;
     listwidth = newsize.width() - (coversize + 20);
     ui->lblAlbumCover->setGeometry(5,5,coversize,coversize);
     ui->lblArtistName->setGeometry(5,coversize + 5,coversize,20);
     ui->lblAlbumName->setGeometry(5,coversize + 25,coversize,20);
     ui->lblAlbumNumber->setGeometry(listleft,5,listwidth,20);
     ui->listTracks->setGeometry(listleft,25,listwidth,newsize.height() - 30);
}

void SKG_AlbumFrame::resizeEvent(QResizeEvent *e)
{
    ResizeFrame(e->size());
}

bool SKG_AlbumFrame::AlbumArtClicked(QMouseEvent *event)
{
    if (ui->lblAlbumCover->rect().contains(event->pos()) &&
            (ui->listTracks->isEnabled()))
        return true;
    else
        return false;
}

// Clears all the internal controls so a new album can be loaded
void SKG_AlbumFrame::Clear()
{
    ui->lblAlbumCover->clear();
    ui->lblAlbumName->clear();
    ui->lblAlbumNumber->clear();
    ui->lblArtistName->clear();
    ui->listTracks->clear();
}

bool SKG_AlbumFrame::AlbumNumbersNecessary(SKG_Album *album)
{
    bool necessary = false;
    QString first2;
    int num;
    bool isnumeric;

    for (int i = 1;i < album->GetTracks().count();i++)
    {
        isnumeric = true;
        num = 1;
        first2 = album->GetTracks().at(i)->GetTrackName().trimmed().left(2);
        num = first2.toInt(&isnumeric);
        if (num == 0 && !isnumeric)
        {
            necessary = true;
            break;
        }
    }
    return necessary;
}
