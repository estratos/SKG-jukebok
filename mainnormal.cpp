#include "mainnormal.h"
#include "ui_mainnormal.h"
#include "frmtracklist.h"
#include "frmoptions.h"
#include "frmalbumart.h"
#include "frmalbumartmulti.h"
#include "frmloadcustomlist.h"
#include "frmloadplaylist.h"
#include "frmconfig.h"
#include "frmrip.h"
#include "frmhelp.h"
#include "frmtracksearch.h"
#include "frmaddtoplaylist.h"
#include "frmvolume.h"
#include "frmabout.h"
#include "stdlib.h"
#include "time.h"
#include <QTimer>
#include <QTime>
#include <QDesktopWidget>

MainNormal::MainNormal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainNormal)
{
    cDEFAULT_COVER_ART = "resources/Default.jpeg";
    //cDEFAULT_COVER_ART = "Default.jpeg";
    Library = new SKG_MusicLibrary();
    //TrackNumbers = new QList<long>;
    currTrackNumber = 0;
    TrackString = "";
    PanelIndex=0;
    SelectedAlbum = NULL;
    currTrack = NULL;
    MoveIncrement = this->width() / 5;
    timerSlideLeft = new QTimer(this);
    timerSlideRight = new QTimer(this);
    RandomTrackTimer = new QTimer(this);
    RandomTrackTimer->setInterval(120000);
    LoadedList = NULL;
    Translator = new KeyTranslator(this);
    CurrPlaylist = NULL;

    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    //this->resize(this->width(),this->height());
    ui->SelectedAlbumWidget->SetFontSize(12);

    QObject::connect(ui->btn_Next,SIGNAL(clicked()),this,SLOT(DisplayNextPanel()));
    QObject::connect(ui->btn_Prev,SIGNAL(clicked()),this,SLOT(DisplayPreviousPanel()));
//    ui->currPanel->LoadAlbums(Albums.at(0),Albums.at(1));
    ui->currPanel->show();
    ui->prevPanel->setGeometry(ui->currPanel->width() * -1,0,ui->currPanel->width(),ui->currPanel->height());
    ui->nextPanel->setGeometry(ui->currPanel->width() * 2,0,ui->currPanel->width(),ui->currPanel->height());

    QObject::connect(timerSlideLeft,SIGNAL(timeout()),this,SLOT(SlideNextPanelLeft()));
    QObject::connect(timerSlideRight,SIGNAL(timeout()),this,SLOT(SlideCurrentPanelRight()));
    QObject::connect(ui->currPanel,SIGNAL(Album1Clicked()),this,SLOT(Album1Clicked()));
    QObject::connect(ui->currPanel,SIGNAL(Album2Clicked()),this,SLOT(Album2Clicked()));
    QObject::connect(ui->currPanel,SIGNAL(Album3Clicked()),this,SLOT(Album3Clicked()));
    QObject::connect(ui->currPanel,SIGNAL(Album4Clicked()),this,SLOT(Album4Clicked()));
    QObject::connect(ui->btnCancelTrack,SIGNAL(clicked()),this,SLOT(CancelSelectedTrack()));
    QObject::connect(ui->btnAddTrack,SIGNAL(clicked()),this,SLOT(AddSelectedTrack()));
    QObject::connect(ui->SelectedAlbumWidget,SIGNAL(SelectedTrackChanged()),this,SLOT(SelectedTrackChanged()));
    QObject::connect(ui->SelectedAlbumWidget,SIGNAL(AlbumArtClicked()),this,SLOT(AlbumArtClicked()));
    QObject::connect(ui->SelectedAlbumWidget,SIGNAL(DoubleClicked()),this,SLOT(AddSelectedTrack()));

    //Connect the round buttons to the Letter Button CLicked slot
    QObject::connect(ui->rb_0thru9,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_A,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_B,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_C,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_D,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_E,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_F,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_G,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_H,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_I,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_J,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_K,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_L,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_M,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_N,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_O,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_P,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_Q,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_R,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_S,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_T,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_U,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_V,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_W,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_X,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_Y,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));
    QObject::connect(ui->rb_Z,SIGNAL(clicked(QString)),this,SLOT(LetterButtonClicked(QString)));


    //connect the number buttons to the button clicked slot
    QObject::connect(ui->btn_0,SIGNAL(clicked()),this,SLOT(Btn_0Clicked()));
    QObject::connect(ui->btn_1,SIGNAL(clicked()),this,SLOT(Btn_1Clicked()));
    QObject::connect(ui->btn_2,SIGNAL(clicked()),this,SLOT(Btn_2Clicked()));
    QObject::connect(ui->btn_3,SIGNAL(clicked()),this,SLOT(Btn_3Clicked()));
    QObject::connect(ui->btn_4,SIGNAL(clicked()),this,SLOT(Btn_4Clicked()));
    QObject::connect(ui->btn_5,SIGNAL(clicked()),this,SLOT(Btn_5Clicked()));
    QObject::connect(ui->btn_6,SIGNAL(clicked()),this,SLOT(Btn_6Clicked()));
    QObject::connect(ui->btn_7,SIGNAL(clicked()),this,SLOT(Btn_7Clicked()));
    QObject::connect(ui->btn_8,SIGNAL(clicked()),this,SLOT(Btn_8Clicked()));
    QObject::connect(ui->btn_9,SIGNAL(clicked()),this,SLOT(Btn_9Clicked()));

    QObject::connect(RandomTrackTimer,SIGNAL(timeout()),this,SLOT(PlayRandomTrack()));

    //Set up the Phonon ojects
    MusicOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    EffectsOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    MusicObject = new Phonon::MediaObject(this);
    EffectsObject = new Phonon::MediaObject(this);
    MetaDataObject = new Phonon::MediaObject(this);
    Phonon::MediaSource EffectsSource("resources/swoosh.wav");
    Phonon::createPath(MusicObject,MusicOutput);
    Phonon::createPath(EffectsObject,EffectsOutput);
    EffectsObject->setCurrentSource(EffectsSource);
    MusicObject->setTickInterval(1000);
    QObject::connect(MusicObject,SIGNAL(aboutToFinish()),this,SLOT(QueueNextTrack()));
    QObject::connect(MusicObject,SIGNAL(tick(qint64)),this,SLOT(tick(qint64)));
    qsrand(time(NULL));
    ui->frameSelectedAlbum->hide();
}

MainNormal::~MainNormal()
{
    delete ui;
}

void MainNormal::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainNormal::SetConfig(JukeboxConfig *config)
{
    Config = config;
    ReloadConfig();
    Config->KillSplashForm();
    //Library->SaveToFile(LibraryFile());
}

void MainNormal::mousePressEvent(QMouseEvent *event)
{
    QRect *rect;

    rect = new QRect(ui->Frame1->x() + ui->frameTrackList->x(),
                     ui->Frame1->y() + ui->frameTrackList->y(),
                     ui->frameTrackList->width(),ui->frameTrackList->height());
    if (event->button()==Qt::LeftButton)
    {
        //if (ui->lblTrackList->rect().contains(event->pos()))
        if (rect->contains(event->pos()))
        {
            DisplayTrackListForm();
        }
    }
    rect = NULL;
    rect = new QRect(ui->Frame1->x() + ui->frameNowPlaying->x(),
                     ui->Frame1->y() + ui->frameNowPlaying->y(),
                     ui->frameNowPlaying->width(),ui->frameNowPlaying->height());
    if (event->button()==Qt::LeftButton)
    {
        //if (ui->lblTrackList->rect().contains(event->pos()))
        if (rect->contains(event->pos()))
        {
            DisplayVolumeForm();
        }
    }
    rect = NULL;
}

void MainNormal::resizeEvent(QResizeEvent *event)
{
    QDesktopWidget w;
    float aspectratio = (float)w.width() / (float)w.height();
    if (aspectratio <= 1.35)
    {
        ui->verticalLayout_3->setStretch(0, 1);
        ui->verticalLayout_3->setStretch(1, 15);
        ui->verticalLayout_3->setStretch(2, 4);
    }
    //ui->verticalLayout_3->setGeometry(QRect(2,2,event->size().width(),event->size().height()));
    ui->Frame1->setGeometry(QRect(2,2,event->size().width() - 4,event->size().height() - 4));
    ui->prevPanel->setGeometry(ui->currPanel->width() * -1,0,ui->currPanel->width(),ui->currPanel->height());
    ui->nextPanel->setGeometry(ui->currPanel->width() * 2,0,ui->currPanel->width(),ui->currPanel->height());
}

void MainNormal::keyPressEvent(QKeyEvent *keypress)
{
    QString Custom;
    bool ShiftPressed = (keypress->modifiers() == Qt::ShiftModifier);
    bool CtrlPressed = (keypress->modifiers() == Qt::ControlModifier);
    bool AltPressed = (keypress->modifiers() == Qt::AltModifier);
    int keycode = Translator->TranslateKey(keypress->key(),
                                           ShiftPressed,
                                           CtrlPressed,
                                           AltPressed,
                                           Custom);

    switch(keycode){
    case 0:
        {
            TranslateCustomKeystroke(Custom);
            break;
        }
    case Qt::Key_Escape:
        if (ui->frameSelectedAlbum->isVisible())
        {
            CancelSelectedTrack();
            break;
        }
        else
        {
            QApplication::quit();
            break;
        }
    case Qt::Key_Return:
        if (ui->frameSelectedAlbum->isVisible())
            AddSelectedTrack();
        break;
    case Qt::Key_Enter:
        if (ui->frameSelectedAlbum->isVisible())
            AddSelectedTrack();
        break;
    case Qt::Key_Left:
        PrevButtonClicked();
        break;
    case Qt::Key_Right:
        NextButtonClicked();
        break;
    case Qt::Key_Up:
        VolumeUp();
        break;
    case Qt::Key_Down:
        VolumeDown();
        break;
    case Qt::Key_PageUp:
        PrevLetter();
        break;
    case Qt::Key_PageDown:
        NextLetter();
        break;
    case Qt::Key_0:
        Btn_0Clicked();
        break;
    case Qt::Key_1:
        Btn_1Clicked();
        break;
    case Qt::Key_2:
        Btn_2Clicked();
        break;
    case Qt::Key_3:
        Btn_3Clicked();
        break;
    case Qt::Key_4:
        Btn_4Clicked();
        break;
    case Qt::Key_5:
        Btn_5Clicked();
        break;
    case Qt::Key_6:
        Btn_6Clicked();
        break;
    case Qt::Key_7:
        Btn_7Clicked();
        break;
    case Qt::Key_8:
        Btn_8Clicked();
        break;
    case Qt::Key_9:
        Btn_9Clicked();
        break;
    case Qt::Key_AsciiCircum:
        LetterButtonClicked("0");
        break;
    case Qt::Key_A:
        if (CtrlPressed)
        {
            DisplayAlbumArtMultiForm();
            break;
        }
        else
        {
            LetterButtonClicked("A");
            break;
        }
    case Qt::Key_B:
        LetterButtonClicked("B");
        break;
    case Qt::Key_C:
        if (CtrlPressed)
        {
            ClearTracks();
            break;
        }
        else
        {
            LetterButtonClicked("C");
            break;
        }
    case Qt::Key_D:
        if (CtrlPressed)
        {
            AddCurrentTrackToPlaylist();
            break;
        }
        else
        {
            LetterButtonClicked("D");
            break;
        }
    case Qt::Key_E:
        LetterButtonClicked("E");
        break;
    case Qt::Key_F:
        LetterButtonClicked("F");
        break;
    case Qt::Key_G:
        if (CtrlPressed)
        {
            DisplayConfigForm();
            break;
        }
        else
        {
            LetterButtonClicked("G");
            break;
        }
    case Qt::Key_H:
        LetterButtonClicked("H");
        break;
    case Qt::Key_I:
        LetterButtonClicked("I");
        break;
    case Qt::Key_J:
        LetterButtonClicked("J");
        break;
    case Qt::Key_K:
        LetterButtonClicked("K");
        break;
    case Qt::Key_L:
        if (CtrlPressed)
        {
            DisplayLoadCustomListForm();
            break;
        }
        else
        {
            LetterButtonClicked("L");
            break;
        }
    case Qt::Key_M:
        if (CtrlPressed)
        {
            this->setWindowState(Qt::WindowMinimized);
            break;
        }
        else
        {
            LetterButtonClicked("M");
            break;
        }
    case Qt::Key_N:
        if (CtrlPressed)
        {
            NextTrack();
            break;
        }
        else
        {
            LetterButtonClicked("N");
            break;
        }
    case Qt::Key_O:
        if (CtrlPressed)
        {
            DisplayOptionsForm();
            break;
        }
        else
        {
            LetterButtonClicked("O");
            break;
        }
    case Qt::Key_P:
        if (CtrlPressed)
        {
            DisplayPlaylistForm();
            break;
        }
        else
        {
            LetterButtonClicked("P");
            break;
        }
    case Qt::Key_Q:
        LetterButtonClicked("Q");
        break;
    case Qt::Key_R:
        if (CtrlPressed)
        {
            DisplayRipForm();
            break;
        }
        else
        {
            LetterButtonClicked("R");
            break;
        }
    case Qt::Key_S:
        if (CtrlPressed)
        {
            DisplayTrackSearchForm();
            break;
        }
        else
        {
            LetterButtonClicked("S");
            break;
        }
    case Qt::Key_T:
        if (CtrlPressed)
        {
            DisplayTrackListForm();
            break;
        }
        else
        {
            LetterButtonClicked("T");
            break;
        }
    case Qt::Key_U:
        LetterButtonClicked("U");
        break;
    case Qt::Key_V:
        LetterButtonClicked("V");
        break;
    case Qt::Key_W:
        LetterButtonClicked("W");
        break;
    case Qt::Key_X:
        LetterButtonClicked("X");
        break;
    case Qt::Key_Y:
        LetterButtonClicked("Y");
        break;
    case Qt::Key_Z:
        LetterButtonClicked("Z");
        break;
    case Qt::Key_Space:
        if (MusicObject->state() == Phonon::PlayingState)
        {
            MusicObject->pause();
            break;
        }
        else if (MusicObject->state() == Phonon::PausedState)
        {
            MusicObject->play();
            break;
        }

    default:
        break;
    }
}

void MainNormal::DisplayCurrTrack()
{
    int albumnum;
    SKG_Album *curralbum;
    QTime *tracktime;

    albumnum = currTrackNumber / 100;
    curralbum = Albums.at(albumnum - 1);
    ui->lblCurrTrackArt->clear();
    ui->lblCurrTrackArt->setPixmap(QPixmap(curralbum->GetCoverArt()).scaledToHeight(ui->lblCurrTrackArt->height()));
    ui->lblCurrTrackName->setText(currTrack->GetTrackName());
    ui->lblCurrArtist->setText(curralbum->GetArtistName());
    ui->lblCurrTrackData->setText(curralbum->GetAlbumName());
    tracktime = new QTime(0,
                         (MusicObject->totalTime() / 60000) % 60,
                         (MusicObject->totalTime() / 1000) % 60);
    ui->lblCurrTrackTime->setText(QTime(0,0,0,0).toString("mm:ss") +
                                  " [" +
                                  tracktime->toString("mm:ss") +
                                  "]");
}

//void MainNormal::DisplayTrackNumbers()
//{
//    const int cMAX_TO_DISPLAY = 18;
//    QString tmptxt;
//    int i;
//    tmptxt = "";
//    ui->lblTrackList->clear();
//    for (i = 0;i < TrackNumbers.count();i++)
//    {
//        if (i == cMAX_TO_DISPLAY)
//            break;

//        if (LargeAlbumNumbers())
//        {
//            if (i == 0)
//                //tmptxt = QString::number(TrackNumbers.at(0));
//                tmptxt = QString("%1").arg(QString::number(TrackNumbers.at(i)),6,'0');
//            else if ((i % 3) == 1 || (i % 3) == 2 )
//                tmptxt = tmptxt + " " + QString("%1").arg(QString::number(TrackNumbers.at(i)),6,'0');  //QString::number(TrackNumbers.at(i));
//            else
//                tmptxt = tmptxt + "\n" + QString("%1").arg(QString::number(TrackNumbers.at(i)),6,'0');  //QString::number(TrackNumbers.at(i));
//        }
//        else
//        {
//            if (i == 0)
//                //tmptxt = QString::number(TrackNumbers.at(0));
//                tmptxt = QString("%1").arg(QString::number(TrackNumbers.at(i)),5,'0');
//            else if ((i % 3) == 1 || (i % 3) == 2 )
//                tmptxt = tmptxt + " " + QString("%1").arg(QString::number(TrackNumbers.at(i)),5,'0');  //QString::number(TrackNumbers.at(i));
//            else
//                tmptxt = tmptxt + "\n" + QString("%1").arg(QString::number(TrackNumbers.at(i)),5,'0');  //QString::number(TrackNumbers.at(i));
//        }

//        ui->lblTrackList->setText(tmptxt);
//    }

//}

void MainNormal::DisplayTrackNumbers()
{
    const int cMAX_TO_DISPLAY = 5;
    SKG_Track *currtrack;
    QString tmptxt;
    int i;
    tmptxt = "";
    ui->lblTrackList->clear();
    for (i = 0;i < TrackNumbers.count();i++)
    {
        if (i == cMAX_TO_DISPLAY)
            break;

        currtrack = TrackByNumber(TrackNumbers.at(i));
        tmptxt += currtrack->GetTrackNameSansNumber().left(20) + "\n";
    }
    //tmptxt += "\nClick for more";
    ui->lblTrackList->setText(tmptxt);
}

void MainNormal::LetterButtonClicked(QString btnCaption)
{
    int tmpindex = 0;
    QChar *artistname;
    QChar artistfirstletter;
    bool found = false;
    bool lessthancurrent;

    QCoreApplication::processEvents();
    if (btnCaption == "0..9")
    {
        // If any artist name, begins with a numeral, it will be in the first
        // panel. Chack that and if it is not the case, return
        artistname = Albums.at(0)->GetArtistName().data();
        artistfirstletter = artistname[0];
        if (artistfirstletter.isDigit())
        {
            PanelIndex = 0;
            lessthancurrent = true;
            found = true;
        }
        else
            return;
    }
    else
    {
        // Find the panel with the first artist whose name begins with the
        // appropriate letter and slide the panel leftward
        while (tmpindex < Albums.count())
        {
            artistname = Albums.at(tmpindex)->GetArtistName().data();
            artistfirstletter = artistname[0].toUpper();
            if (artistfirstletter > btnCaption.data()[0])
                return;

            if (artistfirstletter == btnCaption.data()[0])
            {
                if (tmpindex < PanelIndex)
                    lessthancurrent = true;
                else
                    lessthancurrent = false;

                PanelIndex = tmpindex;
                found = true;
                break;
            }
            //
            if ((tmpindex + 1) >= Albums.count())
                return;

            artistname = Albums.at(tmpindex + 1)->GetArtistName().data();
            artistfirstletter = artistname[0];
            if (artistfirstletter > btnCaption.data()[0])
                return;

            if (artistfirstletter == btnCaption.data()[0])
            {
                if (tmpindex < PanelIndex)
                    lessthancurrent = true;
                else
                    lessthancurrent = false;

                PanelIndex = tmpindex;
                found = true;
                break;
            }
            //
            if ((tmpindex + 2) >= Albums.count())
                return;

            artistname = Albums.at(tmpindex + 2)->GetArtistName().data();
            artistfirstletter = artistname[0];
            if (artistfirstletter > btnCaption.data()[0])
                return;

            if (artistfirstletter == btnCaption.data()[0])
            {
                if (tmpindex < PanelIndex)
                    lessthancurrent = true;
                else
                    lessthancurrent = false;

                PanelIndex = tmpindex;
                found = true;
                break;
            }
            //
            if ((tmpindex + 3) >= Albums.count())
                return;

            artistname = Albums.at(tmpindex + 3)->GetArtistName().data();
            artistfirstletter = artistname[0];
            if (artistfirstletter > btnCaption.data()[0])
                return;

            if (artistfirstletter == btnCaption.data()[0])
            {
                if (tmpindex < PanelIndex)
                    lessthancurrent = true;
                else
                    lessthancurrent = false;

                PanelIndex = tmpindex;
                found = true;
                break;
            }
            tmpindex += 4;
        }
    }
    if (!found) return;

    QCoreApplication::processEvents();
    if (lessthancurrent)
    {
        ui->prevPanel->Clear();
        ui->prevPanel->LoadAlbums(ui->currPanel->Album1(),
                                  ui->currPanel->Album2(),
                                  ui->currPanel->Album3(),
                                  ui->currPanel->Album4(),
                                  LargeAlbumNumbers());
        ui->prevPanel->setVisible(true);
        ui->prevPanel->setGeometry(ui->currPanel->x(),
                                   ui->currPanel->y(),
                                   ui->currPanel->width(),
                                   ui->currPanel->height());
        ui->prevPanel->raise();

        if ((PanelIndex + 3) < Albums.count())
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                      Albums.at(PanelIndex + 1),
                                      Albums.at(PanelIndex + 2),
                                      Albums.at(PanelIndex + 3),
                                      LargeAlbumNumbers());
        }
        else if ((PanelIndex + 2) < Albums.count())
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                                  Albums.at(PanelIndex + 1),
                                                  Albums.at(PanelIndex + 2),
                                                  NULL,
                                                  LargeAlbumNumbers());
        }
        else if ((PanelIndex + 1) < Albums.count())
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                                  Albums.at(PanelIndex + 1),
                                                  NULL,
                                                  NULL,LargeAlbumNumbers());
        }
        else
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                                  NULL,
                                                  NULL,
                                                  NULL,LargeAlbumNumbers());
        }

        if (Config->PlaySlidingSound())
        {
            EffectsObject->stop();
            EffectsObject->play();
        }

        if (Config->PlayAnimation())
        {
            SlideFinished = false;
            while (!SlideFinished)
            {
                SlideCurrentPanelRight();
            }
        }
        else
        {
            ui->prevPanel->move(ui->currPanel->width(),0);
            SlideCurrentPanelRight();
        }

    }
    else
    {
        ui->nextPanel->Clear();
        ui->nextPanel->setVisible(true);
        ui->nextPanel->setGeometry(this->width() * 2,
                                   ui->currPanel->y(),
                                   ui->currPanel->width(),
                                   ui->currPanel->height());

        if ((PanelIndex + 3) < Albums.count())
        {
            ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                      Albums.at(PanelIndex + 1),
                                      Albums.at(PanelIndex + 2),
                                      Albums.at(PanelIndex + 3),
                                      LargeAlbumNumbers());
        }
        else if ((PanelIndex + 2) < Albums.count())
        {
            ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                      Albums.at(PanelIndex + 1),
                                      Albums.at(PanelIndex + 2),
                                      NULL,
                                      LargeAlbumNumbers());
        }
        else if ((PanelIndex + 1) < Albums.count())
        {
            ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                      Albums.at(PanelIndex + 1),
                                      NULL,
                                      NULL,
                                      LargeAlbumNumbers());
        }
        else
        {
            ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                      NULL,
                                      NULL,
                                      NULL,
                                      LargeAlbumNumbers());
        }

        if (Config->PlaySlidingSound())
        {
            EffectsObject->stop();
            EffectsObject->play();
        }

        if (Config->PlayAnimation())
        {
            SlideFinished = false;
            while (!SlideFinished)
            {
                SlideNextPanelLeft();
            }
        }
        else
        {
            ui->nextPanel->move(0,ui->currPanel->y());
            SlideNextPanelLeft();
        }
    }
}

void MainNormal::ButtonClicked(QString btnCaption)
{
    int albumnum;
    int tracknum;

    if (Config->GetCollectionSize() == sizeSmall)
    {
        if (TrackString.length() < 5)
        {
            TrackString += btnCaption;
            ui->lblTrackString->setText(TrackString);
            if (TrackString.length() == 3)
            {
                if (TrackString == "000")
                {
                    DisplayOptionsForm();
                    TrackString = "";
                    ui->lblTrackString->setText("Track List");
                }
                else
                {
                    if (TrackString.toInt() <= Albums.count())
                    {
                        albumnum = TrackString.toInt();
                        SelectedAlbum = Albums.at(albumnum - 1);
                        DisplaySelectedAlbum();
                        PanelIndex = (SelectedAlbum->GetAlbumNumber());

                        if (PanelIndex % 4 == 0)
                        {
                            PanelIndex -= 4;
                        }
                        else if (PanelIndex % 4 == 3)
                        {
                            PanelIndex -= 3;
                        }
                        else if (PanelIndex % 4 == 2)
                        {
                            PanelIndex -= 2;
                        }
                        else
                        {
                            PanelIndex --;
                        }


                        ui->currPanel->Clear();
                        ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                                  Albums.at(PanelIndex + 1),
                                                  Albums.at(PanelIndex + 2),
                                                  Albums.at(PanelIndex + 3),
                                                  LargeAlbumNumbers());
                    }
                    else
                    {
                        TrackString = "";
                        ui->lblTrackString->setText("Track List");
                    }
                }
            }
            else if (TrackString.length() == 5)
            {
                tracknum = TrackString.right(2).toInt();
                if (tracknum < SelectedAlbum->GetTracks().count())
                    ui->SelectedAlbumWidget->SetSelectedTrack(tracknum);
                else
                    TrackString = TrackString.left(3);
                ui->lblTrackString->setText(TrackString);
            }
        }
    }
    else if (Config->GetCollectionSize() == sizeLarge)
    {
        if (TrackString.length() < 6)
        {
            TrackString += btnCaption;
            ui->lblTrackString->setText(TrackString);
            if (TrackString.length() == 4)
            {
                if (TrackString == "0000")
                {
                    DisplayOptionsForm();
                    TrackString = "";
                    ui->lblTrackString->setText("Track List");
                }
                else
                {
                    if (TrackString.toInt() <= Albums.count())
                    {
                        albumnum = TrackString.toInt();
                        SelectedAlbum = Albums.at(albumnum - 1);
                        DisplaySelectedAlbum();
                        PanelIndex = (SelectedAlbum->GetAlbumNumber());

                        if (PanelIndex % 4 == 0)
                        {
                            PanelIndex -= 4;
                        }
                        else if (PanelIndex % 3 == 0)
                        {
                            PanelIndex -= 3;
                        }
                        else if (PanelIndex % 2 == 0)
                        {
                            PanelIndex -= 2;
                        }
                        else
                        {
                            PanelIndex --;
                        }


                        ui->currPanel->Clear();
                        ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                                  Albums.at(PanelIndex + 1),
                                                  Albums.at(PanelIndex + 2),
                                                  Albums.at(PanelIndex + 3),
                                                  LargeAlbumNumbers());
                    }
                    else
                    {
                        TrackString = "";
                        ui->lblTrackString->setText("Track List");
                    }
                }
            }
            else if (TrackString.length() == 6)
            {
                tracknum = TrackString.right(2).toInt();
                if (tracknum < SelectedAlbum->GetTracks().count())
                    ui->SelectedAlbumWidget->SetSelectedTrack(tracknum);
                else
                    TrackString = TrackString.left(3);
                ui->lblTrackString->setText(TrackString);
            }
        }
    }
}

void MainNormal::PrevButtonClicked()
{
    DisplayPreviousPanel();
}

void MainNormal::NextButtonClicked()
{
    DisplayNextPanel();
}

void MainNormal::DisplayConfigForm()
{
    frmConfig ConfigForm;

    ConfigForm.Initialize(Config,ListManager,Translator,PListManager,LoadedList);

    if (ConfigForm.exec() == QDialog::Accepted)
    {
        ReloadConfig();
    }
}

void MainNormal::DisplayOptionsForm()
{
    frmOptions OptionForm;

    if (OptionForm.exec() == QDialog::Accepted)
    {
        if (OptionForm.Option == OptionConfig)
        {
            DisplayConfigForm();
        }
        else if (OptionForm.Option == OptionRipper)
        {
            DisplayRipForm();
        }
        else if (OptionForm.Option == OptionAlbumArt)
        {
            DisplayAlbumArtMultiForm();
        }
        else if (OptionForm.Option == OptionCustomLists)
        {
            DisplayLoadCustomListForm();
        }
        else if (OptionForm.Option == OptionPlaylist)
        {
            DisplayPlaylistForm();
        }
        else if (OptionForm.Option == OptionHelp)
        {
            DisplayHelpForm();
        }
        else if (OptionForm.Option == OptionAddToPlaylist)
        {
            AddCurrentTrackToPlaylist();
        }
        else if (OptionForm.Option == OptionTrackSearch)
        {
            DisplayTrackSearchForm();
        }
        else if (OptionForm.Option == OptionMinimize)
        {
            this->setWindowState(Qt::WindowMinimized);
        }
        else if (OptionForm.Option == OptionAbout)
        {
            DisplayAboutForm();
        }
        else if(OptionForm.Option == OptionExit)
        {
            QApplication::quit();
        }
    }
    TrackString = "";
    ui->lblTrackString->setText("Track List");
}

void MainNormal::DisplayTrackListForm()
{
    int res;

    if (TrackNumbers.count() == 0)
        return;

    frmTrackList TrackForm;
    TrackForm.Initialize(Albums,MusicObject,TrackNumbers,currTrack,LargeAlbumNumbers());
    res = TrackForm.exec();
    if (res == QDialog::Rejected)
        return;

    if(res == QDialog::Accepted)
    {
        TrackNumbers=TrackForm.GetTrackNumbers();
        DisplayTrackNumbers();
    }

    if (TrackForm.GetCurrentTrackNumber() != 0)
    {
        currTrackNumber = TrackForm.GetCurrentTrackNumber();
        currTrack = TrackForm.GetCurrTrack();
        DisplayCurrTrack();
    }
    else if (TrackNumbers.count() == 0)
    {
        ui->lblCurrTrackArt->clear();
        ui->lblCurrArtist->clear();
        ui->lblCurrTrackName->clear();
        ui->lblCurrTrackData->clear();
        ui->lblCurrTrackTime->clear();
        currTrack = NULL;
    }
    SaveTrackList();
}

void MainNormal::DisplayNextPanel()
{
    if (!SlideFinished)
        return;

    PanelIndex += 4;
    if (PanelIndex >= Albums.count())
        PanelIndex = 0;

    ui->nextPanel->Clear();
    ui->nextPanel->setVisible(true);
    ui->nextPanel->setGeometry(this->width() * 2,
                               ui->currPanel->y(),
                               ui->currPanel->width(),
                               ui->currPanel->height());
    ui->nextPanel->raise();

    if ((PanelIndex + 3) < Albums.count())
    {
        ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                  Albums.at(PanelIndex + 1),
                                  Albums.at(PanelIndex + 2),
                                  Albums.at(PanelIndex + 3),
                                  LargeAlbumNumbers());
    }
    else if ((PanelIndex + 2) < Albums.count())
    {
        ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                 Albums.at(PanelIndex + 1),
                                 Albums.at(PanelIndex + 2),
                                 NULL,
                                 LargeAlbumNumbers());
    }
    else if ((PanelIndex + 1) < Albums.count())
    {
        ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                 Albums.at(PanelIndex + 1),
                                 NULL,
                                 NULL,
                                 LargeAlbumNumbers());
    }
    else
    {
        ui->nextPanel->LoadAlbums(Albums.at(PanelIndex),
                                 NULL,
                                 NULL,
                                 NULL,
                                 LargeAlbumNumbers());
    }

    if (Config->PlaySlidingSound())
    {
        EffectsObject->stop();
        EffectsObject->play();
    }

    if (Config->PlayAnimation())
    {
        SlideFinished = false;
        while (!SlideFinished)
        {
            SlideNextPanelLeft();
        }
    }
    else
    {
        ui->nextPanel->move(0,ui->currPanel->y());
        SlideNextPanelLeft();
    }
}

void MainNormal::DisplayPreviousPanel()
{
    if (!SlideFinished)
        return;

    if (PanelIndex <= 3)
    {
        if (Albums.count() % 4 == 1)
            PanelIndex = Albums.count() - 1;
        else if (Albums.count() % 4 == 2)
            PanelIndex = Albums.count() - 2;
        else if (Albums.count() % 4 == 3)
            PanelIndex = Albums.count() - 3;
        else
            PanelIndex = Albums.count() - 4;
    }
    else
        PanelIndex -= 4;


    ui->prevPanel->Clear();
    ui->prevPanel->LoadAlbums(ui->currPanel->Album1(),
                              ui->currPanel->Album2(),
                              ui->currPanel->Album3(),
                              ui->currPanel->Album4(),
                              LargeAlbumNumbers());
    ui->prevPanel->setVisible(true);
    ui->prevPanel->setGeometry(ui->currPanel->x(),
                               ui->currPanel->y(),
                               ui->currPanel->width(),
                               ui->currPanel->height());
    ui->prevPanel->raise();

    ui->currPanel->Clear();
    if ((PanelIndex + 3) < Albums.count())
    {
        ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                  Albums.at(PanelIndex + 1),
                                  Albums.at(PanelIndex + 2),
                                  Albums.at(PanelIndex + 3),
                                  LargeAlbumNumbers());
    }
    else if ((PanelIndex + 2) < Albums.count())
    {
        ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                  Albums.at(PanelIndex + 1),
                                  Albums.at(PanelIndex + 2),
                                  NULL,
                                  LargeAlbumNumbers());
    }
    else if ((PanelIndex + 1) < Albums.count())
    {
        ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                  Albums.at(PanelIndex + 1),
                                  NULL,
                                  NULL,
                                  LargeAlbumNumbers());
    }
    else
    {
        ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                  NULL,
                                  NULL,
                                  NULL,
                                  LargeAlbumNumbers());
    }

    if (Config->PlaySlidingSound())
    {
        EffectsObject->stop();
        EffectsObject->play();
    }

    if (Config->PlayAnimation())
    {
        SlideFinished = false;
        while (!SlideFinished)
        {
            SlideCurrentPanelRight();
        }
    }
    else
    {
        ui->prevPanel->move(ui->currPanel->width(),0);
        SlideCurrentPanelRight();
    }
}


void MainNormal::SlideNextPanelLeft()
{
    if ((ui->nextPanel->x()) <= 0)
    {
        timerSlideLeft->stop();
        ui->currPanel->Clear();
        ui->nextPanel->move(ui->currPanel->x(),ui->currPanel->y());


        if ((PanelIndex + 3) < Albums.count())
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                      Albums.at(PanelIndex + 1),
                                      Albums.at(PanelIndex + 2),
                                      Albums.at(PanelIndex + 3),
                                      LargeAlbumNumbers());
        }
        else if ((PanelIndex + 2) < Albums.count())
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                     Albums.at(PanelIndex + 1),
                                     Albums.at(PanelIndex + 2),
                                     NULL,
                                     LargeAlbumNumbers());
        }
        else if ((PanelIndex + 1) < Albums.count())
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                     Albums.at(PanelIndex + 1),
                                     NULL,
                                     NULL,
                                     LargeAlbumNumbers());
        }
        else
        {
            ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                                     NULL,
                                     NULL,
                                     NULL,
                                     LargeAlbumNumbers());
        }

        ui->nextPanel->hide();
        ui->currPanel->show();
        SlideFinished = true;
    }
    else
        ui->nextPanel->move(ui->nextPanel->x() - MoveIncrement,ui->currPanel->y());

    QApplication::processEvents();
}

void MainNormal::SlideCurrentPanelRight()
{
    if(ui->prevPanel->x() >= ui->currPanel->width())
    {
        timerSlideRight->stop();
        SlideFinished = true;

        ui->prevPanel->hide();
        ui->currPanel->show();
    }
    else
        ui->prevPanel->move(ui->prevPanel->x() + MoveIncrement,ui->currPanel->y());

    QApplication::processEvents();
}

void MainNormal::Album1Clicked()
{
    SelectedAlbum = ui->currPanel->Album1();
    DisplaySelectedAlbum();
}

void MainNormal::Album2Clicked()
{
    SelectedAlbum = ui->currPanel->Album2();
    DisplaySelectedAlbum();
}

void MainNormal::Album3Clicked()
{
    SelectedAlbum = ui->currPanel->Album3();
    DisplaySelectedAlbum();
}

void MainNormal::Album4Clicked()
{
    SelectedAlbum = ui->currPanel->Album4();
    DisplaySelectedAlbum();
}

void MainNormal::AddSelectedTrack()
{
    long newtracknum;
    if (ui->SelectedAlbumWidget->GetSelectedTrack() == NULL)
        return;

    newtracknum = ui->SelectedAlbumWidget->SelectedTrackID().toLong();
    if (newtracknum % 100 == 0)
    {
        //User chose 00--All tracks
        if ((MusicObject->currentSource().type() == Phonon::MediaSource::Empty) ||
            (MusicObject->currentSource().type() == Phonon::MediaSource::Invalid))
        {
            long firsttracknum = ++newtracknum;
            currTrack = Library->GetTrackByNumber(firsttracknum);
            //currTrackNumber = TrackString.toLong();
            currTrackNumber = firsttracknum;
            CurrentSong = Phonon::MediaSource(currTrack->GetFileName());
            MusicObject->enqueue(CurrentSong);
            MetaDataObject->setCurrentSource(CurrentSong);

            DisplayCurrTrack();
            MusicObject->play();
            newtracknum++;

            while((newtracknum % 100) < SelectedAlbum->GetTracks().count())
            {
                TrackNumbers.append(newtracknum);
                newtracknum++;
            }
            DisplayTrackNumbers();
            while(MusicObject->state() != Phonon::PlayingState)
            {
                QApplication::processEvents();
                MusicObject->play();
            }
        }
        else
        {
            newtracknum++;
            while((newtracknum % 100) < SelectedAlbum->GetTracks().count())
            {
                TrackNumbers.append(newtracknum);
                newtracknum++;
            }
            DisplayTrackNumbers();
        }
    }
    else if ((MusicObject->currentSource().type() == Phonon::MediaSource::Empty) ||
             (MusicObject->currentSource().type() == Phonon::MediaSource::Invalid))
    {
        currTrack = TrackByNumber(newtracknum);
        currTrackNumber = TrackString.toLong();
        CurrentSong = Phonon::MediaSource(currTrack->GetFileName());
        MusicObject->enqueue(CurrentSong);
        MetaDataObject->setCurrentSource(CurrentSong);
        DisplayCurrTrack();
        MusicObject->play();
        while(MusicObject->state() != Phonon::PlayingState)
        {
            QApplication::processEvents();
            MusicObject->play();
        }
    }
    else
    {
        TrackNumbers.append(newtracknum);
        this->DisplayTrackNumbers();
    }
    TrackString = "";
    ui->lblTrackString->setText("Track List");
    ui->SelectedAlbumWidget->Clear();
    ui->frameSelectedAlbum->hide();
    SaveTrackList();
    RandomTrackTimer->stop();
    this->setFocus();
}

void MainNormal::CancelSelectedTrack()
{
    SelectedAlbum = NULL;
    TrackString = "";
    ui->lblTrackString->setText("Track List");
    ui->SelectedAlbumWidget->Clear();
    ui->frameSelectedAlbum->hide();
}

void MainNormal::DisplaySelectedAlbum()
{
    //ui->frameSelectedAlbum->setGeometry(0,0,this->width(),ui->frameLetterButtons->height() + ui->currPanel->height());
    //ui->SelectedAlbumWidget->setGeometry(0,0,this->width(),ui->frameLetterButtons->height() + ui->currPanel->height());
    ui->frameSelectedAlbum->setGeometry(0,0,this->width(),this->height() - ui->frameNowPlaying->x());
    //ui->SelectedAlbumWidget->setGeometry(0,0,this->width(),this->height() - ui->frameNowPlaying->x());

    ui->frameSelectedAlbum->raise();
    ui->SelectedAlbumWidget->LoadAlbum(SelectedAlbum,LargeAlbumNumbers());
    ui->SelectedAlbumWidget->Expand(ui->SelectedAlbumWidget->x(),
                                    ui->SelectedAlbumWidget->y(),
                                    ui->SelectedAlbumWidget->width(),
                                    ui->SelectedAlbumWidget->height());

    if (Config->GetCollectionSize() == sizeLarge)
        TrackString = QString("%1").arg(QString::number(SelectedAlbum->GetAlbumNumber()),4,'0');
    else
        TrackString = QString("%1").arg(QString::number(SelectedAlbum->GetAlbumNumber()),3,'0');

    ui->lblTrackString->setText(TrackString);
    ui->frameSelectedAlbum->show();
}

void MainNormal::Btn_0Clicked()
{
    ButtonClicked("0");
}

void MainNormal::Btn_1Clicked()
{
    ButtonClicked("1");
}

void MainNormal::Btn_2Clicked()
{
    ButtonClicked("2");
}

void MainNormal::Btn_3Clicked()
{
    ButtonClicked("3");
}

void MainNormal::Btn_4Clicked()
{
    ButtonClicked("4");
}

void MainNormal::Btn_5Clicked()
{
    ButtonClicked("5");
}

void MainNormal::Btn_6Clicked()
{
    ButtonClicked("6");
}

void MainNormal::Btn_7Clicked()
{
    ButtonClicked("7");
}

void MainNormal::Btn_8Clicked()
{
    ButtonClicked("8");
}

void MainNormal::Btn_9Clicked()
{
    ButtonClicked("9");
}

void MainNormal::SelectedTrackChanged()
{
    TrackString = ui->SelectedAlbumWidget->SelectedTrackID();
    ui->lblTrackString->setText(TrackString);
}

void MainNormal::QueueNextTrack()
{
    if (TrackNumbers.count() > 0)
    {
        currTrackNumber = TrackNumbers.takeFirst();
        currTrack = TrackByNumber(currTrackNumber);
        Phonon::MediaSource newsource(currTrack->GetFileName());
        MusicObject->enqueue(newsource);
        MetaDataObject->setCurrentSource(newsource);
        QApplication::processEvents();
        DisplayCurrTrack();
        DisplayTrackNumbers();
    }
    else
    {
        Phonon::MediaSource emptysource("");
        MusicObject->setCurrentSource(emptysource);
        MetaDataObject->setCurrentSource(emptysource);

        ui->lblCurrTrackArt->clear();
        ui->lblCurrArtist->clear();
        ui->lblCurrTrackName->clear();
        ui->lblCurrTrackData->clear();
        ui->lblCurrTrackTime->clear();
        currTrack = NULL;
        CurrPlaylist = NULL;

        if (Config->PlayRandomTrack())
            RandomTrackTimer->start();

    }
    SaveTrackList();
}

void MainNormal::tick(qint64 time)
{
    QTime *elapsed, *totaltime;

    elapsed = new QTime(0, (MusicObject->currentTime() / 60000) % 60,
                       (MusicObject->currentTime() / 1000) % 60);
    totaltime = new QTime(0, (MusicObject->totalTime() / 60000) % 60,
                         (MusicObject->totalTime() / 1000) % 60);
    ui->lblCurrTrackTime->setText(elapsed->toString("mm:ss") +
                                  " [" +
                                  totaltime->toString("mm:ss") +
                                  "]");

}

void MainNormal::DisplayAlbumArtForm()
{
    if (!Config->IsConnected())
    {
        QMessageBox box;
        box.setText("This function unavailable if jukebox is not connected to internet.");
        box.exec();
        return;
    }

    frmAlbumArt ArtForm;
    ArtForm.Search(this->SelectedAlbum);
    ArtForm.exec();
}

void MainNormal::DisplayAlbumArtMultiForm()
{
    if (!Config->IsConnected())
    {
        QMessageBox box;
        box.setText("This function unavailable if jukebox is not connected to internet.");
        box.exec();
        return;
    }

    frmAlbumArtMulti ArtForm;
    ArtForm.Initialize(this->Library);
    ArtForm.exec();
}

void MainNormal::AlbumArtClicked()
{
    DisplayAlbumArtForm();
    ui->SelectedAlbumWidget->Clear();
    ui->SelectedAlbumWidget->LoadAlbum(SelectedAlbum,LargeAlbumNumbers());
    ui->currPanel->Clear();
    ui->currPanel->LoadAlbums(Albums.at(PanelIndex),
                              Albums.at(PanelIndex + 1),
                              Albums.at(PanelIndex + 2),
                              Albums.at(PanelIndex + 3),
                              LargeAlbumNumbers());
}

void MainNormal::LoadCustomAlbumList(CustomAlbumList *list)
{
    int i;
    SKG_Album *curralbum;

    LoadedList = list;
    if (list != NULL)
    {
        Albums.clear();
        for (i = 0; i < list->GetAlbumNumbers().count(); i++)
        {
            curralbum = Library->GetAlbumByNumber(list->GetAlbumNumbers().at(i));
            Albums.append(curralbum);
        }
    }
    else
    {
        Albums = Library->GetAlbums();
    }

    for (i = 0;i < Albums.count(); i++)
        Albums.at(i)->SetAlbumNumber(i + 1);

    ui->currPanel->Clear();
    ui->currPanel->LoadAlbums(Albums.at(0),
                              Albums.at(1),
                              Albums.at(2),
                              Albums.at(3),
                              LargeAlbumNumbers());
}

SKG_Track* MainNormal::TrackByNumber(long tracknum)
{
    int albumnumber;
    int tracknumber;

    albumnumber = tracknum / 100;
    tracknumber = tracknum % 100;
    return Albums.at(albumnumber - 1)->GetTracks().at(tracknumber);
}

void MainNormal::DisplayLoadCustomListForm()
{
    frmLoadCustomList CustListForm;
    CustListForm.Initialize(ListManager,LoadedList,Library);
    if(CustListForm.exec() == QDialog::Accepted)
    {
        TrackNumbers.clear();
        ui->lblTrackList->clear();
        ui->lblTrackString->setText("Track List");
        PanelIndex = 0;
        LoadedList = CustListForm.GetSelectedList();
        LoadCustomAlbumList(LoadedList);
        if (LoadedList != NULL)
            Config->SetCustomListName(LoadedList->GetName());
        else
            Config->SetCustomListName("");

        Config->SaveConfigFile();
    }
}

void MainNormal::ReloadConfig()
{
    int i,j;
    QDir *musicdir;
    //AlbumInfo *info;
    SKG_Album *currAlbum;

    delete Library;
    Library = new SKG_MusicLibrary();
    TrackNumbers.clear();
    ui->lblTrackList->clear();
    ui->lblTrackString->setText("TrackList");

    if (QFile::exists(LibraryFile()))
    {
        Library->LoadFromFile(LibraryFile());
    }
    else
    {
        for (i = 0;i < Config->GetMusicDirectories().count();i++)
        {
            musicdir = new QDir(Config->GetMusicDirectories().at(i));
            Library->AddDirectory(musicdir);
        }
        Library->SaveToFile(LibraryFile());
    }
    Albums = Library->GetAlbums();
    ui->currPanel->LoadAlbums(Albums.at(0),
                              Albums.at(1),
                              Albums.at(2),
                              Albums.at(3),
                              LargeAlbumNumbers());
    //

    for (j = 0;j < Albums.count();j++)
    {
       currAlbum = Albums.at(j);
       if (currAlbum->GetCoverArt() == "")
            currAlbum->SetCoverArt(cDEFAULT_COVER_ART);
    }

    Translator = new KeyTranslator;

    PListManager = new PlaylistManager;
    PListManager->SetLibrary(Library);

    ListManager = new CustomListManager;
    ListManager->SetLibrary(Library);
    if (Config->GetCustomListName() != "")
        LoadCustomAlbumList(ListManager->RetrieveListByName(Config->GetCustomListName()));
}

void MainNormal::DisplayRipForm()
{
    if (!Config->IsConnected())
    {
        QMessageBox box;
        box.setText("This function unavailable if jukebox is not connected to internet.");
        box.exec();
        return;
    }

    FrmRip RipForm;
    RipForm.Initialize(Library);
    if (RipForm.Display() == QDialog::Accepted)
    {
        QFile::remove(LibraryFile());
        ReloadConfig();
    }

}

void MainNormal::ClearTracks()
{
    TrackNumbers.clear();
    MusicObject->stop();
    QApplication::processEvents();
    currTrack = NULL;
    DisplayTrackNumbers();
    QueueNextTrack();
    ui->lblCurrTrackTime->setText("");
    if (Config->PlayRandomTrack())
        RandomTrackTimer->start();
}

void MainNormal::NextTrack()
{
    if (TrackNumbers.count() == 0)
    {
        ClearTracks();
    }
    else
    {
        MusicObject->stop();
        MusicObject->clear();
        QueueNextTrack();
        MusicObject->play();
        while(MusicObject->state() != Phonon::PlayingState)
        {
            QApplication::processEvents();
            MusicObject->play();
        }
    }
}

void MainNormal::DisplayPlaylistForm()
{
    frmLoadPlaylist PlaylistForm;

    PlaylistForm.Initialize(PListManager,Library);
    if(PlaylistForm.exec() == QDialog::Accepted)
    {
        LoadPlaylist(PlaylistForm.GetSelectedList(),PlaylistForm.RandomOrder());
    }
}

void MainNormal::DisplayHelpForm()
{
    frmHelp HelpForm;
    HelpForm.exec();

}

void MainNormal::LoadPlaylist(Playlist *plist, bool random)
{
    QList<int> *tracknums;
    SKG_Track *currtack;

    this->ClearTracks();
    TrackNumbers.clear();
    ui->lblTrackList->clear();
    ui->lblTrackString->setText("Track List");
    tracknums = plist->GetTrackNumbers(random);
    currTrackNumber = tracknums->at(0);
    currTrack = TrackByNumber(currTrackNumber);
    CurrentSong = Phonon::MediaSource(currTrack->GetFileName());
    MusicObject->enqueue(CurrentSong);
    MetaDataObject->setCurrentSource(CurrentSong);
    DisplayCurrTrack();
    MusicObject->play();
    for(int i = 1;i < tracknums->count();i++)
    {
        TrackNumbers.append(tracknums->at(i));
    }
    DisplayTrackNumbers();
    SaveTrackList();
    while(MusicObject->state() != Phonon::PlayingState)
    {
        QApplication::processEvents();
        MusicObject->play();
    }
    CurrPlaylist = plist;
}

void MainNormal::TranslateCustomKeystroke(QString Custom)
{
    if (Custom.trimmed() == "CustomList--None")
    {
        LoadCustomAlbumList(NULL);
    }
    else if (Custom.left(12) == "CustomList--")
    {
        CustomAlbumList *list = ListManager->RetrieveListByName(Custom.mid(12).trimmed());
        LoadCustomAlbumList(list);
    }
    else if (Custom.left(10) == "Playlist--")
    {
        Playlist *plist = PListManager->RetrieveListByName(Custom.mid(10).trimmed());
        LoadPlaylist(plist,false);
    }
    else if (Custom.left(13) == "Playlist(R)--")
    {
        Playlist *plist = PListManager->RetrieveListByName(Custom.mid(13).trimmed());
        LoadPlaylist(plist,true);
    }
}

bool MainNormal::LargeAlbumNumbers()
{
    return (Config->GetCollectionSize() == sizeLarge);
}

void MainNormal::SaveTrackList()
{
    QFile f(TrackListFile());
    if (TrackNumbers.isEmpty() && (currTrack == NULL))
    {
        if (f.exists())
            f.remove();
    }
    else
    {
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QStringList l;
        if (currTrack != NULL)
            l.append(QString::number(currTrackNumber));

        for (int i = 0;i < TrackNumbers.count();i++)
        {
            l.append(QString::number(TrackNumbers.at(i)));
        }
        f.write(l.join(",").toAscii());
        f.close();
    }
}

void MainNormal::LoadTrackList()
{
    //SKG_Track *currTrack;
    QFile f(TrackListFile());
    if (!f.exists())
    {
        if (Config->PlayRandomTrack())
            RandomTrackTimer->start();

        return;
    }


    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString s = f.readAll();
    f.close();
    QStringList l = s.split(",");
    long firsttrack = l.at(0).toLong();
    for (int i = 1;i < l.count();i++)
    {
        TrackNumbers.append(l.at(i).toLong());
    }

    currTrack = TrackByNumber(firsttrack);
    currTrackNumber = firsttrack;
    CurrentSong = Phonon::MediaSource(currTrack->GetFileName());
    MusicObject->enqueue(CurrentSong);
    MetaDataObject->setCurrentSource(CurrentSong);
    MusicObject->play();
    DisplayTrackNumbers();
    DisplayCurrTrack();
    SaveTrackList();
    while(MusicObject->state() != Phonon::PlayingState)
    {
        QApplication::processEvents();
        MusicObject->play();
    }
}

void MainNormal::DisplayTrackSearchForm()
{
    FrmTrackSearch *TrackSearchForm = new FrmTrackSearch;

    TrackSearchForm->Initialize(Albums);
    QObject::connect(TrackSearchForm,SIGNAL(TrackAdd(long)),this,SLOT(AddTrackNumber(long)));
    TrackSearchForm->exec();
}

void MainNormal::AddTrackNumber(long tracknum)
{
    if ((MusicObject->currentSource().type() == Phonon::MediaSource::Empty) ||
        (MusicObject->currentSource().type() == Phonon::MediaSource::Invalid))
    {
        currTrack = TrackByNumber(tracknum);
        currTrackNumber = tracknum;
        CurrentSong = Phonon::MediaSource(currTrack->GetFileName());
        MusicObject->enqueue(CurrentSong);
        MetaDataObject->setCurrentSource(CurrentSong);
        DisplayCurrTrack();
        MusicObject->play();
        while(MusicObject->state() != Phonon::PlayingState)
        {
            QApplication::processEvents();
            MusicObject->play();
        }
    }
    else
    {
        TrackNumbers.append(tracknum);
        DisplayTrackNumbers();
    }
    RandomTrackTimer->stop();
}

void MainNormal::AddCurrentTrackToPlaylist()
{
    FrmAddToPlaylist AddToPlaylistForm;
    AddToPlaylistForm.Initialize(PListManager,currTrack,currTrackNumber);
    AddToPlaylistForm.exec();
}

void MainNormal::PlayRandomTrack()
{
    int randomalbum;
    int randomtrack;
    SKG_Album *album;

    randomalbum = (qrand() % Albums.count());
    album = Albums.at(randomalbum);
    randomtrack = (qrand() % (album->GetTracks().count() - 1)) + 1;

    this->AddTrackNumber(randomalbum * 100 + randomtrack);

    // Delete track list file if it exists. Don't want to save random track
    QFile f(TrackListFile());
    if (f.exists())
    {
        f.remove();
    }
}

void MainNormal::VolumeUp()
{
    MusicOutput->setVolumeDecibel(MusicOutput->volumeDecibel() + 2);
}

void MainNormal::VolumeDown()
{
    MusicOutput->setVolumeDecibel(MusicOutput->volumeDecibel() - 2);
}

void MainNormal::DisplayVolumeForm()
{
    if (MusicObject->state() != Phonon::PlayingState)
        return;

    frmVolume *frm = new frmVolume;

    QObject::connect(frm,SIGNAL(VolumeUp()),this,SLOT(VolumeUp()));
    QObject::connect(frm,SIGNAL(VolumeDown()),this,SLOT(VolumeDown()));
    frm->exec();

    delete frm;
}

void MainNormal::DisplayAboutForm()
{
    frmAbout abt;
    abt.exec();
}

void MainNormal::NextLetter()
{
    QString currletter;
    if (ui->currPanel->Album4() == NULL)
    {
        if (ui->currPanel->Album3() == NULL)
        {
            if (ui->currPanel->Album2() == NULL)
            {
                currletter = ui->currPanel->Album1()->GetArtistName().left(1);
            }
            else
            {
                currletter = ui->currPanel->Album2()->GetArtistName().left(1);
            }
        }
        else
        {
            currletter = ui->currPanel->Album3()->GetArtistName().left(1);
        }

    }
    else
    {
        currletter = ui->currPanel->Album4()->GetArtistName().left(1);
    }

    //QMessageBox box(QMessageBox::NoIcon,"",currletter);
    //box.exec();

    if (currletter >= "0" && currletter <= "9")
    {
        LetterButtonClicked("A");
    }
    else if (currletter.toUpper() == "Z")
    {
        LetterButtonClicked("0..9");
    }
    else
    {
        char ch = currletter.toAscii().at(0);
        do
        {
            ch++;
        }while (Library->ArtistStartsWith(QString(ch)) == NULL);

        LetterButtonClicked(QString(QChar(ch)));
    }
}

void MainNormal::PrevLetter()
{
    QString currletter = ui->currPanel->Album1()->GetArtistName().left(1);
    if (currletter >= "0" && currletter <= "9")
    {
        LetterButtonClicked("Z");
    }
    else if (currletter.toUpper() == "A")
    {
        LetterButtonClicked("0..9");
    }
    else
    {
        char ch = currletter.toAscii().at(0);
        do
        {
            ch--;
        }while (Library->ArtistStartsWith(QString(ch)) == NULL);
        LetterButtonClicked(QString(QChar(ch)));
    }
}
