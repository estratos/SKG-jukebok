#include <QDir>
#include <QString>
#include <QFileDialog>
#include <QPixmap>
#include <QDesktopServices>
#include <QtGui>
#include "skg_albumwidget.h"
//#include "skg_albumframe.h"
//#include "skglib.h"

SKG_AlbumWidget::SKG_AlbumWidget(QWidget *parent)
    :QFrame(parent)
{
   albumframe = new SKG_AlbumFrame(this);
   QObject::connect(albumframe->listTracks(),SIGNAL(clicked(QModelIndex)),this,SIGNAL(SelectedTrackChanged()));
   QObject::connect(albumframe->listTracks(),SIGNAL(itemChanged(QListWidgetItem*)),this,SIGNAL(SelectedTrackChanged()));
   QObject::connect(albumframe->listTracks(),SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SIGNAL(DoubleClicked()));
   albumframe->showNormal();
}

void SKG_AlbumWidget::LoadAlbum(SKG_Album *album,bool largealbumnumbers)
{
    LoadedAlbum=album;
    if (album != NULL)
        albumframe->LoadAlbum(album,largealbumnumbers);
}

//Resize Widget while enabling internal controls
void SKG_AlbumWidget::Expand(int newtop,int newleft,int newwidth,int newheight)
{
    albumframe->setGeometry(newtop,newleft,newwidth,newheight);
    albumframe->EnableControls();
}

//Resize Widget while disabling internal controls
void SKG_AlbumWidget::Contract(int newtop,int newleft,int newwidth,int newheight)
{
    albumframe->setGeometry(newtop,newleft,newwidth,newheight);
    albumframe->DisableControls();
}

void SKG_AlbumWidget::resizeEvent(QResizeEvent *event)
{
    albumframe->resize(event->size());
}

QString SKG_AlbumWidget::AlbumName()
{
    return LoadedAlbum->GetAlbumName();
}

QString SKG_AlbumWidget::ArtistName()
{
    return LoadedAlbum->GetArtistName();
}

// Returns the track object represented by the highlighted item in the list box
SKG_Track* SKG_AlbumWidget::GetSelectedTrack()
{
    if (albumframe->listTracks()->currentItem()==NULL)
    {
        return NULL;
    }
    else
    {
        return LoadedAlbum->GetTracks().at(albumframe->listTracks()->currentRow());
    }
}

QString SKG_AlbumWidget::AlbumArt()
{
    return LoadedAlbum->GetCoverArt();
}

// If user clicks within the album art, raise Album Art Clicked event
// Otherwise, just raise clicked event
void SKG_AlbumWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (albumframe->AlbumArtClicked(event))
            AlbumArtClicked();
        else
            clicked();
    }
}

// Returns the 5 digit track id, consisting of the 3 digit album number followed
// by the 2 digit track number
QString SKG_AlbumWidget::SelectedTrackID()
{
    long tracknum;
    QString strtracknum;

    tracknum = (LoadedAlbum->GetAlbumNumber() * 100) + GetSelectedTrack()->GetTrackNumber();
    strtracknum = QString::number(tracknum);
    return QString("%1").arg(strtracknum,5,'0');
}

void SKG_AlbumWidget::DisableControls()
{
    albumframe->DisableControls();
}

void SKG_AlbumWidget::Clear()
{
    albumframe->Clear();
}

void SKG_AlbumWidget::SetSelectedTrack(int tracknum)
{
    if (tracknum < albumframe->listTracks()->count())
        albumframe->listTracks()->setCurrentRow(tracknum);
}

void SKG_AlbumWidget::SetFontSize(int fontsize)
{
    QFont fnt = albumframe->listTracks()->font();
    fnt.setPointSize(12);
    albumframe->listTracks()->setFont(fnt);
}
