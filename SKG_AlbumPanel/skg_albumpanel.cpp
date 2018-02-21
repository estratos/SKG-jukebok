#include "skg_albumpanel.h"

SKG_AlbumPanel::SKG_AlbumPanel(QWidget *parent) :
    QFrame(parent)
{
    panelframe = new SKG_AlbumPanelFrame(this);
    panelframe->AlbumWidget1()->DisableControls();
    panelframe->AlbumWidget2()->DisableControls();
    panelframe->AlbumWidget3()->DisableControls();
    panelframe->AlbumWidget4()->DisableControls();
    panelframe->showNormal();
    QObject::connect(panelframe->AlbumWidget1(),SIGNAL(clicked()),this,SIGNAL(Album1Clicked()));
    QObject::connect(panelframe->AlbumWidget2(),SIGNAL(clicked()),this,SIGNAL(Album2Clicked()));
    QObject::connect(panelframe->AlbumWidget3(),SIGNAL(clicked()),this,SIGNAL(Album3Clicked()));
    QObject::connect(panelframe->AlbumWidget4(),SIGNAL(clicked()),this,SIGNAL(Album4Clicked()));
}

void SKG_AlbumPanel::LoadAlbums(SKG_Album *album1,
                                SKG_Album *album2,
                                SKG_Album *album3,
                                SKG_Album *album4,
                                bool largealbumnumbers)
{
    //if (album1 != NULL)
        panelframe->LoadAlbum1(album1,largealbumnumbers);
    //if (album2 != NULL)
        panelframe->LoadAlbum2(album2,largealbumnumbers);
    //if (album3 != NULL)
        panelframe->LoadAlbum3(album3,largealbumnumbers);
    //if (album4 != NULL)
        panelframe->LoadAlbum4(album4,largealbumnumbers);
}

SKG_AlbumPanel* SKG_AlbumPanel::operator =(const SKG_AlbumPanel* other)
{
    this->LoadAlbums(other->panelframe->AlbumWidget1()->LoadedAlbum,
                     other->panelframe->AlbumWidget2()->LoadedAlbum,
                     other->panelframe->AlbumWidget3()->LoadedAlbum,
                     other->panelframe->AlbumWidget4()->LoadedAlbum);
    return this;
}

SKG_Album* SKG_AlbumPanel::Album1()
{
    return panelframe->AlbumWidget1()->LoadedAlbum;
}

SKG_Album* SKG_AlbumPanel::Album2()
{
    return panelframe->AlbumWidget2()->LoadedAlbum;
}

SKG_Album* SKG_AlbumPanel::Album3()
{
    return panelframe->AlbumWidget3()->LoadedAlbum;
}

SKG_Album* SKG_AlbumPanel::Album4()
{
    return panelframe->AlbumWidget4()->LoadedAlbum;
}

void SKG_AlbumPanel::mousePressEvent(QMouseEvent *event)
{
    if (panelframe->AlbumWidget1()->rect().contains(event->pos()))
        Album1Clicked();
    else if (panelframe->AlbumWidget2()->rect().contains(event->pos()))
        Album2Clicked();
    else if (panelframe->AlbumWidget3()->rect().contains(event->pos()))
        Album3Clicked();
    else if (panelframe->AlbumWidget4()->rect().contains(event->pos()))
        Album4Clicked();
}

void SKG_AlbumPanel::resizeEvent(QResizeEvent *event)
{
    panelframe->resize(event->size().width(),event->size().height());
}

void SKG_AlbumPanel::Clear()
{
    panelframe->AlbumWidget1()->Clear();
    panelframe->AlbumWidget2()->Clear();
    panelframe->AlbumWidget3()->Clear();
    panelframe->AlbumWidget4()->Clear();
}
