#include "frmrip.h"
#include "ui_frmrip.h"
#include "frmdialog.h"
#include "jukeboxconfig.h"
#include <QRegExp>

FrmRip::FrmRip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmRip)
{
    bool x;
    QList <unsigned> sig;

    ExtractProgress = 0;
    EncodeProgress = 0;
    ui->setupUi(this);
    Ripper = new SKG_Ripper(this);
    QObject::connect(Ripper,SIGNAL(DriveFound()),this,SLOT(DriveFound()));
    QObject::connect(Ripper,SIGNAL(DriveNotFound()),this,SLOT(DriveNotFound()));
    QObject::connect(Ripper,SIGNAL(LookupError(QString)),this,SLOT(LookupError(QString)));
    QObject::connect(Ripper,SIGNAL(LookupMessage(QString)),this,SLOT(LookupMessage(QString)));
    QObject::connect(Ripper,SIGNAL(LookupDisconnected()),this,SLOT(LookupDisconnected()));
    QObject::connect(Ripper,SIGNAL(LookupFinish()),this,SLOT(LookupFinished()));
    QObject::connect(Ripper,SIGNAL(UpdateExtractProgress(int)),this,SLOT(UpdateExtractProgress(int)));
    QObject::connect(Ripper,SIGNAL(UpdateEncodeProgress(int)),this,SLOT(UpdateEncodeProgress(int)));
    QObject::connect(Ripper,SIGNAL(ExtractFinished(QString)),this,SLOT(ExtractFinished(QString)));
    QObject::connect(Ripper,SIGNAL(EncodeFinished()),this,SLOT(EncodeFinished()));

    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    QObject::connect(ui->btnRip,SIGNAL(clicked()),this,SLOT(Rip()));
    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(accept()));

    ui->rbMp3->setChecked(true);
}

FrmRip::~FrmRip()
{
    delete ui;
    delete Ripper;
}

void FrmRip::Initialize(SKG_MusicLibrary *lib)
{
    Library = lib;
    Ripper->Initialize();
}

void FrmRip::changeEvent(QEvent *e)
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

void FrmRip::DisplayFreeDBInfo()
{
    QString str,trackstr;
    QListWidgetItem *item;
    int minutes,seconds,numtracks;

    ui->txtArtist->setText(Ripper->GetArtist());
    ui->txtTitle->setText(Ripper->GetAlbum());
    ui->txtGenre->setText(Ripper->GetGenre());
    if (Ripper->GetYear() != 0)
    {
        ui->txtYear->setText(QString::number(Ripper->GetYear()));
    }
    ui->listTracks->clear();

    for(int i = 0; i < Ripper->GetTracks().count(); i++)
    {
        trackstr = Ripper->GetTracks().at(i);
        str = "Track " + QString::number(i + 1) + ": " +
               trackstr.replace("/","-");
        item = new QListWidgetItem(str);
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item->setCheckState(Qt::Checked);
        ui->listTracks->addItem(item);
        TrackNameList.append(trackstr.replace("/","-"));
    }
    minutes = Ripper->GetRunningTime() / 60;
    seconds = Ripper->GetRunningTime() % 60;
    numtracks = Ripper->GetTracks().count();
    ui->lblTracksInfo->setText(QString("%1 Tracks -- %2:%3").arg(numtracks).arg(minutes,2).arg(seconds,2));
    ui->lblStatus->clear();
}

void FrmRip::Rip()
{
    QDir *ArtistDir;
    QString ArtistName;
    QString AlbumName;
    SKG_Artist *Artist;

    ArtistName = ui->txtArtist->text().trimmed();
    AlbumName = ui->txtTitle->text().trimmed();
    if (Library->ArtistExists(ArtistName))
    {
        Artist = Library->GetArtistByName(ArtistName);
        ArtistDir = new QDir(Artist->GetDirectoryName());
        if (Artist->AlbumExists(AlbumName))
        {
            QMessageBox box;
            box.addButton(QMessageBox::Yes);
            box.addButton(QMessageBox::No);
            box.setText("Album already exists. Do you wish to delete album from Library and re-encode?");
            if(box.exec() == QMessageBox::Yes)
            {
                SKG_Album *album =Library->GetAlbumByName(ArtistName,AlbumName);
                QDir *AlbumDirectory = new QDir(album->GetDirectoryName());
                for (int i = 0;i < AlbumDirectory->entryList().count();i++)
                {
                    AlbumDirectory->remove(AlbumDirectory->entryList().at(i));
                }
                ArtistDir->rmdir(AlbumName);
            }
            else
            {
                return;
            }
        }

    }
    else
    {
        QDir *LibraryDir = new QDir(Library->GetDirectoryNames().at(0));
        LibraryDir->mkdir(ArtistName);
        LibraryDir->cd(ArtistName);
        ArtistDir = LibraryDir;
        Artist = new SKG_Artist(ArtistDir->absolutePath());
        Library->AddArtist(Artist);
    }

    ArtistDir->mkdir(AlbumName);
    ArtistDir->cd(AlbumName);
    AlbumDirectory = ArtistDir;
    NewAlbum = new SKG_Album(AlbumDirectory);
    Artist->AddAlbum(NewAlbum);
    Artist->SortAlbums();

    TrackIndex = 1;
    Ripper->Extract(TrackIndex);
}

void FrmRip::DriveFound()
{
    Ripper->LookupDisc();
}

void FrmRip::DriveNotFound()
{
    QMessageBox box;

    box.setText("Drive Not Found");
    box.exec();
}

void FrmRip::ShowProgress()
{
    if (ExtractProgress > 0)
    {
        ExtractProgressString = ("Extracting Track " + QString::number(TrackIndex) + ": "
                                 + QString::number(ExtractProgress) + "%");

        ui->lblStatus->setText(ExtractProgressString);
    }
    else if (EncodeProgress > 0)
    {
        EncodeProgressString = ("Encoding " + Ripper->GetTracks().at(TrackIndex - 1) + ": "
                                 + QString::number(EncodeProgress) + "%");
        ui->lblStatus->setText(EncodeProgressString);
    }
}

void FrmRip::UpdateExtractProgress(int prog)
{
    ExtractProgress = prog;
    ShowProgress();
}

void FrmRip::UpdateEncodeProgress(int prog)
{
    EncodeProgress = prog;
    ShowProgress();
}

void FrmRip::ExtractFinished(QString fname)
{
    EncodeFileName = AlbumDirectory->path() + "/" +
                        QString("%1").arg(QString::number(TrackIndex),2,QChar('0')) + " - " +
                        ValidTrackName(Ripper->GetTracks().at(TrackIndex - 1));
                        //ui->listTracks->item(TrackIndex - 1)->text();
    EncodeFileName = EncodeFileName.trimmed();
    ExtractProgress = 0;
    ExtractProgressString = "";
    if (ui->rbMp3->isChecked())
    {
        Ripper->EncodeMp3(fname,EncodeFileName + ".mp3");
    }
    else if (ui->rbOgg->isChecked())
    {
        Ripper->EncodeOgg(fname,EncodeFileName + ".ogg");
    }
    else
    {
        Ripper->EncodeFlac(fname,EncodeFileName + ".flac");
    }
}

void FrmRip::EncodeFinished()
{
    QFileInfo *finfo = new QFileInfo(EncodeFileName);
    EncodeProgress = 0;
    EncodeProgressString = "";
    NewTrack = new SKG_Track(TrackIndex,finfo);
    NewAlbum->AddTrack(NewTrack);
    EncodeFileName = "";
    delete finfo;
    TrackIndex++;

    if (TrackIndex > Ripper->GetTracks().count())
    {
        ui->lblStatus->setText("Finished");
        //DiscFinished();
        //Library->SaveToFile(LibraryFile());
        DisplayDialog();
    }
    else
    {
        while(ui->listTracks->item(TrackIndex - 1)->checkState() != Qt::Checked)
        {
            TrackIndex++;
            if (TrackIndex >=Ripper->GetTracks().count())
            {
                ui->lblStatus->setText("Finished");
                //DiscFinished();
                DisplayDialog();
                return;
            }
        }
        Ripper->Extract(TrackIndex);
    }
}

int FrmRip::Display()
{
    ui->lblStatus->setText("Looking up disc info");
    this->setVisible(true);
    QApplication::processEvents();
    return exec();
}

void FrmRip::DisplayDialog()
{
    //QMessageBox box;
    int x,y;

    frmDialog dialogform;
    x = dialogform.DisplayOther("Finished importing CD. What do you wish to do?",
                                "Import Another CD","Exit CD Ripper");  //== QDialog::Accepted)
    if (x == QDialog::Accepted)
    {
        Ripper->Eject();
        y = dialogform.DisplayOkCancel("Insert another disc and click OK");  //== QDialog::Accepted)
        if (y == QDialog::Accepted)
        {
            ExtractProgressString = "";
            EncodeProgressString = "";
            TrackNameList.clear();
            Clear();
            QApplication::processEvents();
            //LookupDisc();
            Ripper->Initialize();
        }
        else
        {
            this->accept();
        }
    }
    else
    {
        this->accept();
    }
}

void FrmRip::Clear()
{
    ui->txtArtist->clear();
    ui->txtTitle->clear();
    ui->txtYear->clear();
    ui->listTracks->clear();
}

void FrmRip::LookupMessage(QString msg)
{
    ui->lblStatus->setText(msg);
}

void FrmRip::LookupError(QString errmsg)
{
    ui->lblStatus->setText(errmsg);
}

void FrmRip::LookupFinished()
{
    DisplayFreeDBInfo();
    ui->btnRip->setEnabled(true);
}

// Removes invalid characters from track name prior to creating file.
QString FrmRip::ValidTrackName(QString trackname)
{
    QString validname = trackname;
    QRegExp exp("\\/:*\"?<>|");
    if (validname.contains(exp) == true)
    {
        validname = validname.replace("\\","-");
        validname = validname.replace("/-","");
        validname = validname.replace(":","-");
        validname = validname.replace("\"","");
        validname = validname.replace("?","");
        validname = validname.replace("<","");
        validname = validname.replace(">","");
        validname = validname.replace("|","");
    }
    return validname;
}
