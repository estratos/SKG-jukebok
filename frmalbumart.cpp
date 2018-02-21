#include "frmalbumart.h"
#include "ui_frmalbumart.h"
#include "jukeboxconfig.h"

frmAlbumArt::frmAlbumArt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmAlbumArt)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    Google = new GoogleImageSearch(this);
    Yahoo = new YahooImageSearch(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(Tick()));

    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnNext->setPixmap(QPixmap(RightArrow()));
    ui->btnPrev->setPixmap(QPixmap(LeftArrow()));

    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(Google,SIGNAL(Finished()),this,SLOT(GoogleFinished()));
    QObject::connect(Yahoo,SIGNAL(Finished()),this,SLOT(YahooFinished()));
}

frmAlbumArt::~frmAlbumArt()
{
    delete ui;
    delete Google;
    delete Yahoo;
    delete timer;
}

void frmAlbumArt::changeEvent(QEvent *e)
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

void frmAlbumArt::Tick()
{
    ui->lblStatus->clear();
    ui->lblStatus->setText("Downloading cover art for Artist: " + Album->GetArtistName()
                           + " Album: " + Album->GetAlbumName()
                           + "\n" + QString::number(PercentComplete()) + "\% complete");
    if (boolYahooFinished && boolGoogleFinished)
        Finished();
}

void frmAlbumArt::Search(SKG_Album *album)
{
    Album = album;
    PicIndex = 0;
    PicList.clear();
    boolGoogleFinished =false;
    boolYahooFinished = false;
    Google->Search(Album->GetArtistName(),Album->GetAlbumName(),5);
    Yahoo->Search(Album->GetArtistName(),Album->GetAlbumName(),5);

    Tick();
    timer->start();
}

void frmAlbumArt::Finished()
{
    timer->stop();
    PicList.append(Google->GetPicList());
    PicList.append(Yahoo->GetPicList());
    DisplayPicture();
    QObject::connect(ui->btnNext,SIGNAL(clicked()),this,SLOT(Next()));
    QObject::connect(ui->btnPrev,SIGNAL(clicked()),this,SLOT(Previous()));
    QObject::connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(Save()));
}

void frmAlbumArt::DisplayPicture()
{
    QPixmap pixmap;

    ui->lblStatus->setText("Artist: " + Album->GetArtistName() + "\n"
                           + "Album: " + Album->GetAlbumName() + "\n"
                           "Displaying picture " +
                           QString::number(PicIndex + 1) +
                           " of" + QString::number(PicList.count()));
    ui->lblArt->clear();
    pixmap = PicList.at(PicIndex);
    ui->lblArt->setPixmap(pixmap);
    ui->lblInfo->setText("Width: " + QString::number(pixmap.width()) + "\n"
                         + "Height: " + QString::number(pixmap.height()));
}

void frmAlbumArt::Previous()
{
    PicIndex--;
    if(PicIndex < 0)
        PicIndex = PicList.count() - 1;

    DisplayPicture();
}

void frmAlbumArt::Next()
{
    PicIndex++;
    if(PicIndex >= PicList.count())
        PicIndex = 0;

    DisplayPicture();
}

void frmAlbumArt::Save()
{
    QString filename;

    filename = Album->GetAlbumPath() + "/" + "cover.jpg";
    ui->lblArt->pixmap()->save(filename,0,100);
    Album->SetCoverArt(filename);
    this->accept();
}

int frmAlbumArt::PercentComplete()
{
    return (Google->PercentageComplete() + Yahoo->PercentageComplete()) / 2;
}
