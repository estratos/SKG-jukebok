#include <QDesktopServices>
#include <QtGui>
#include "skg_albumpanelsmall.h"

SKG_AlbumPanelSmall::SKG_AlbumPanelSmall(QWidget *parent) :
    QFrame(parent)
{
    panelframe = new SKG_AlbumPanelFrameSmall(this);
    panelframe->AlbumWidget1()->DisableControls();
    panelframe->AlbumWidget2()->DisableControls();
    panelframe->showNormal();
    QObject::connect(panelframe->AlbumWidget1(),SIGNAL(clicked()),this,SIGNAL(Album1Clicked()));
    QObject::connect(panelframe->AlbumWidget2(),SIGNAL(clicked()),this,SIGNAL(Album2Clicked()));
}

void SKG_AlbumPanelSmall::LoadAlbums(SKG_Album *album1,SKG_Album *album2,bool largealbumnumbers)
{
    //if (album1 != NULL)
        panelframe->LoadAlbum1(album1,largealbumnumbers);
    //if (album2 != NULL)
        panelframe->LoadAlbum2(album2,largealbumnumbers);
}

SKG_AlbumPanelSmall* SKG_AlbumPanelSmall::operator =(const SKG_AlbumPanelSmall* other)
{
    this->LoadAlbums(other->panelframe->AlbumWidget1()->LoadedAlbum,other->panelframe->AlbumWidget2()->LoadedAlbum);
    return this;
}

SKG_Album* SKG_AlbumPanelSmall::Album1()
{
    return panelframe->AlbumWidget1()->LoadedAlbum;
}

SKG_Album* SKG_AlbumPanelSmall::Album2()
{
    return panelframe->AlbumWidget2()->LoadedAlbum;
}

void SKG_AlbumPanelSmall::mousePressEvent(QMouseEvent *event)
{
    if (panelframe->AlbumWidget1()->rect().contains(event->pos()))
        Album1Clicked();
    else if (panelframe->AlbumWidget2()->rect().contains(event->pos()))
        Album2Clicked();
}

void SKG_AlbumPanelSmall::Clear()
{
    panelframe->AlbumWidget1()->Clear();
    panelframe->AlbumWidget2()->Clear();
}
