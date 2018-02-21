#include "skg_albumpanelframesmall.h"
#include "ui_skg_albumpanelframesmall.h"

SKG_AlbumPanelFrameSmall::SKG_AlbumPanelFrameSmall(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SKG_AlbumPanelFrameSmall)
{
    ui->setupUi(this);
}

SKG_AlbumPanelFrameSmall::~SKG_AlbumPanelFrameSmall()
{
    delete ui;
}

void SKG_AlbumPanelFrameSmall::changeEvent(QEvent *e)
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

void SKG_AlbumPanelFrameSmall::LoadAlbum1(SKG_Album *album1,bool largealbumnumbers)
{
    ui->AlbumWidget1->LoadAlbum(album1,largealbumnumbers);
}


void SKG_AlbumPanelFrameSmall::LoadAlbum2(SKG_Album *album2,bool largealbumnumbers)
{
    ui->AlbumWidget2->LoadAlbum(album2,largealbumnumbers);
}

SKG_AlbumWidget* SKG_AlbumPanelFrameSmall::AlbumWidget1()
{
    return ui->AlbumWidget1;
}

SKG_AlbumWidget* SKG_AlbumPanelFrameSmall::AlbumWidget2()
{
    return ui->AlbumWidget2;
}
