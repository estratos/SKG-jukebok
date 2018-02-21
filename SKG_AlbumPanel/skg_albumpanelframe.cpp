#include "skg_albumpanelframe.h"
#include "ui_skg_albumpanelframe.h"

SKG_AlbumPanelFrame::SKG_AlbumPanelFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SKG_AlbumPanelFrame)
{
    ui->setupUi(this);
}

SKG_AlbumPanelFrame::~SKG_AlbumPanelFrame()
{
    delete ui;
}

void SKG_AlbumPanelFrame::changeEvent(QEvent *e)
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

void SKG_AlbumPanelFrame::LoadAlbum1(SKG_Album *album1,bool largealbumnumbers)
{
    ui->AlbumWidget1->LoadAlbum(album1,largealbumnumbers);
}

void SKG_AlbumPanelFrame::LoadAlbum2(SKG_Album *album2,bool largealbumnumbers)
{
    ui->AlbumWidget2->LoadAlbum(album2,largealbumnumbers);
}

void SKG_AlbumPanelFrame::LoadAlbum3(SKG_Album *album3,bool largealbumnumbers)
{
    ui->AlbumWidget3->LoadAlbum(album3,largealbumnumbers);
}


void SKG_AlbumPanelFrame::LoadAlbum4(SKG_Album *album4,bool largealbumnumbers)
{
    ui->AlbumWidget4->LoadAlbum(album4,largealbumnumbers);
}

SKG_AlbumWidget* SKG_AlbumPanelFrame::AlbumWidget1()
{
    return ui->AlbumWidget1;
}

SKG_AlbumWidget* SKG_AlbumPanelFrame::AlbumWidget2()
{
    return ui->AlbumWidget2;
}

SKG_AlbumWidget* SKG_AlbumPanelFrame::AlbumWidget3()
{
    return ui->AlbumWidget3;
}

SKG_AlbumWidget* SKG_AlbumPanelFrame::AlbumWidget4()
{
    return ui->AlbumWidget4;
}
