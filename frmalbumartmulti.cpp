#include "frmalbumartmulti.h"
#include "ui_frmalbumartmulti.h"
#include "jukeboxconfig.h"

frmAlbumArtMulti::frmAlbumArtMulti(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmAlbumArtMulti)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    //timer->stop();
    Google = new GoogleImageSearch(this);
    Yahoo = new YahooImageSearch(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(Tick()));

    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnNext->setPixmap(QPixmap(RightArrow()));
    ui->btnPrev->setPixmap(QPixmap(LeftArrow()));
    ui->btnUp->setPixmap(QPixmap(UpArrow()));
    ui->btnDown->setPixmap(QPixmap(DownArrow()));

    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(Google,SIGNAL(Finished()),this,SLOT(GoogleFinished()));
    QObject::connect(Yahoo,SIGNAL(Finished()),this,SLOT(YahooFinished()));
    QObject::connect(ui->btnUp,SIGNAL(clicked()),this,SLOT(Up()));
    QObject::connect(ui->btnDown,SIGNAL(clicked()),this,SLOT(Down()));
    QObject::connect(ui->btnToggle,SIGNAL(clicked()),this,SLOT(Toggle()));
    QObject::connect(ui->btnDownload,SIGNAL(clicked()),this,SLOT(DownloadNow()));
    QObject::connect(ui->listAlbums,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(Toggle(QListWidgetItem*)));
    QObject::connect(ui->rbNoArt,SIGNAL(clicked()),this,SLOT(DisplayAlbumsWithoutArt()));
    QObject::connect(ui->rbShowAll,SIGNAL(clicked()),this,SLOT(DisplayAllAlbums()));
    QObject::connect(ui->listAlbums,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,SLOT(ItemChanged(QListWidgetItem*,QListWidgetItem*)));
}

frmAlbumArtMulti::~frmAlbumArtMulti()
{
    delete ui;
}

void frmAlbumArtMulti::changeEvent(QEvent *e)
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

void frmAlbumArtMulti::Previous()
{
    PicIndex--;
    if(PicIndex < 0)
        PicIndex = PicList.count() - 1;

    DisplayPicture();
}

void frmAlbumArtMulti::Next()
{
    PicIndex++;
    if(PicIndex >= PicList.count())
        PicIndex = 0;

    DisplayPicture();
}

void frmAlbumArtMulti::Save()
{
    QString filename;

    filename = CurrentAlbum->GetAlbumPath() + "/" + "cover.jpg";
    ui->lblArt->pixmap()->save(filename,0,100);
    CurrentAlbum->SetCoverArt(filename);
    ui->lblStatus->setText("Artwork saved for " + CurrentAlbum->GetArtistName()
                           + " " + CurrentAlbum->GetAlbumName());
}

void frmAlbumArtMulti::Tick()
{
    ui->lblStatus->clear();
    ui->lblStatus->setText("Downloading cover art for Artist: " + CurrentAlbum->GetArtistName()
                           + " Album: " + CurrentAlbum->GetAlbumName()
                           + "\n" + QString::number(PercentComplete()) + "\% complete");
    if (boolYahooFinished && boolGoogleFinished)
        Finished();

}

void frmAlbumArtMulti::Search(SKG_Album *album)
{
    CurrentAlbum = album;
    PicIndex = 0;
    PicList.clear();
    boolGoogleFinished =false;
    boolYahooFinished = false;

    QObject::disconnect(ui->btnPrev, 0, 0, 0);
    QObject::disconnect(ui->btnNext, 0, 0, 0);
    QObject::disconnect(ui->btnDownload, 0, 0, 0);
    QObject::disconnect(ui->btnSave, 0, 0, 0);
    QObject::disconnect(ui->btnNextAlbum, 0, 0, 0);

    Google->Search(CurrentAlbum->GetArtistName(),CurrentAlbum->GetAlbumName(),5);
    Yahoo->Search(CurrentAlbum->GetArtistName(),CurrentAlbum->GetAlbumName(),5);
    Tick();
    timer->start();
}

void frmAlbumArtMulti::Finished()
{
    timer->stop();
    PicList.append(Google->GetPicList());
    PicList.append(Yahoo->GetPicList());
    DisplayPicture();
    QObject::connect(ui->btnNext,SIGNAL(clicked()),this,SLOT(Next()));
    QObject::connect(ui->btnPrev,SIGNAL(clicked()),this,SLOT(Previous()));
    QObject::connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(Save()));
    QObject::connect(ui->btnNextAlbum,SIGNAL(clicked()),this,SLOT(NextAlbum()));
    Searching = false;
}

void frmAlbumArtMulti::DisplayPicture()
{
    QPixmap pixmap;

    ui->lblStatus->setText("Artist: " + CurrentAlbum->GetArtistName() + "\n"
                           + "Album: " + CurrentAlbum->GetAlbumName() + "\n"
                           "Displaying picture " +
                           QString::number(PicIndex + 1) +
                           " of" + QString::number(PicList.count()));
    ui->lblArt->clear();
    pixmap = PicList.at(PicIndex);
    ui->lblArt->setPixmap(pixmap);
    ui->lblInfo->setText("Width: " + QString::number(pixmap.width()) + "\n"
                         + "Height: " + QString::number(pixmap.height()));
}

void frmAlbumArtMulti::Up()
{
    int prevrow = ui->listAlbums->currentRow() - 1;

    if(prevrow >= 0)
        ui->listAlbums->setCurrentRow(prevrow);
}

void frmAlbumArtMulti::Down()
{
    int nextrow = ui->listAlbums->currentRow() + 1;

    if(nextrow <= ui->listAlbums->count() - 1)
        ui->listAlbums->setCurrentRow(nextrow);
}

void frmAlbumArtMulti::Toggle()
{
    QListWidgetItem *curritem;

    curritem = ui->listAlbums->currentItem();
    if(curritem->checkState() == Qt::Checked)
    {
        curritem->setCheckState(Qt::Unchecked);
        ui->btnToggle->setText("Check");
    }
    else
    {
        curritem->setCheckState(Qt::Checked);
        ui->btnToggle->setText("Uncheck");
    }
}

void frmAlbumArtMulti::Toggle(QListWidgetItem *item)
{
    if(item->checkState() == Qt::Checked)
    {
        item->setCheckState(Qt::Unchecked);
        ui->btnToggle->setText("Check");
    }
    else
    {
        item->setCheckState(Qt::Checked);
        ui->btnToggle->setText("Uncheck");
    }
}

void frmAlbumArtMulti::DownloadNow()
{
    QListWidgetItem *curritem;

    AlbumIndex = 0;
    curritem = ui->listAlbums->item(AlbumIndex);
    while (curritem->checkState() != Qt::Checked)
    {
        AlbumIndex++;
        if (AlbumIndex >= Albums.count())
            return;

        curritem = ui->listAlbums->item(AlbumIndex);
    }

    Search(Albums.at(AlbumIndex));
    Searching = true;
    while (Searching)
    {
        QApplication::processEvents();
    }
}

void frmAlbumArtMulti::NextAlbum()
{
    QListWidgetItem *curritem;

    AlbumIndex++;

    if (AlbumIndex >= Albums.count())
        return;

    curritem = ui->listAlbums->item(AlbumIndex);
    while (curritem->checkState() != Qt::Checked)
    {
        AlbumIndex++;
        if (AlbumIndex >= Albums.count())
            return;

        curritem = ui->listAlbums->item(AlbumIndex);
    }

    Search(Albums.at(AlbumIndex));
    Searching = true;
    while (Searching)
    {
        QApplication::processEvents();
    }
}

void frmAlbumArtMulti::DisplayAlbumList()
{
    int i;
    SKG_Album *curralbum;
    QListWidgetItem *item;

    ui->listAlbums->clear();
    for(i = 0;i < Albums.count();i++)
    {
        curralbum = Albums.at(i);
        item = new QListWidgetItem(QString("%1 -- ").arg(QString::number(curralbum->GetAlbumNumber()),3,'0') +
                                   curralbum->GetArtistName() + " " +
                                   curralbum->GetAlbumName());
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        if(curralbum->GetCoverArt() == "resources/Default.jpeg")
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);

        ui->listAlbums->addItem(item);
    }
}

void frmAlbumArtMulti::DisplayAlbumsWithoutArt()
{
    int i;
    QList <SKG_Album*> list;
    SKG_Album *curralbum;

    for(i = 0;i < Library->GetAlbums().count();i++)
    {
        curralbum = Library->GetAlbums().at(i);
        if (curralbum->GetCoverArt() == "resources/Default.jpeg")
            list.append(curralbum);
    }
    Albums = list;
    DisplayAlbumList();
}

void frmAlbumArtMulti::DisplayAllAlbums()
{
    Albums = Library->GetAlbums();
    DisplayAlbumList();
}

void frmAlbumArtMulti::Initialize(SKG_MusicLibrary *lib)
{
    Library = lib;
    ui->rbNoArt->setChecked(true);
    DisplayAlbumsWithoutArt();
}

void frmAlbumArtMulti::ItemChanged( QListWidgetItem * current, QListWidgetItem * previous)
{
    if (current == NULL)
        return;

    if (current->checkState() == Qt::Checked)
    {
        ui->btnToggle->setText("Uncheck");
    }
    else
    {
        ui->btnToggle->setText("Check");
    }
}

void frmAlbumArtMulti::ItemClicked(QListWidgetItem *item)
{
    if (item->checkState() == Qt::Checked)
        ui->btnToggle->setText("Uncheck");
    else
        ui->btnToggle->setText("Check");
}

int frmAlbumArtMulti::PercentComplete()
{
    return (Google->PercentageComplete() + Yahoo->PercentageComplete()) / 2;
    //return Yahoo->PercentageComplete();
}
