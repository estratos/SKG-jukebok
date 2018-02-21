#include "frmconfig.h"
#include "ui_frmconfig.h"
#include "frmaddeditlist.h"
#include "frmaddeditplaylist.h"
#include "frmdialog.h"
#include "lib/skglib.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

frmConfig::frmConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmConfig)
{
    CustomListFile = "resources/lists.xml";
    Config = NULL;
    Manager = NULL;
    LoadedList = NULL;
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    LoadKeyComboBoxes();

    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(btnSaveClicked()));
    QObject::connect(ui->btnAddDirectory,SIGNAL(clicked()),this,SLOT(btnAddDirectoryClicked()));
    QObject::connect(ui->btnRemoveDirectory,SIGNAL(clicked()),this,SLOT(btnRemoveDirectoryClicked()));
    QObject::connect(ui->btnAddList,SIGNAL(clicked()),this,SLOT(btnAddListClicked()));
    QObject::connect(ui->btnEditList,SIGNAL(clicked()),this,SLOT(btnEditListCLicked()));
    QObject::connect(ui->btnDeleteList,SIGNAL(clicked()),this,SLOT(btnDeleteListClicked()));
    QObject::connect(ui->btnAddPlaylist,SIGNAL(clicked()),this,SLOT(btnAddPlaylistClicked()));
    QObject::connect(ui->btnEditPlaylist,SIGNAL(clicked()),this,SLOT(btnEditPlaylistClicked()));
    QObject::connect(ui->btnDeletePlaylist,SIGNAL(clicked()),this,SLOT(btnDeletePlaylistClicked()));
    QObject::connect(ui->btnAddKey,SIGNAL(clicked()),this,SLOT(btnAddKeyClicked()));
    QObject::connect(ui->btnClearKeys,SIGNAL(clicked()),this,SLOT(btnClearKeysClicked()));
    QObject::connect(ui->btnViewKeyMappings,SIGNAL(clicked()),this,SLOT(ViewCurrentKeyMappings()));
}

frmConfig::~frmConfig()
{
    delete ui;
}

void frmConfig::changeEvent(QEvent *e)
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

void frmConfig::DisplayMusicDirectories()
{
    int i;

    ui->listMusicDirs->clear();
    for (i = 0; i < Config->GetMusicDirectories().count(); i++)
        ui->listMusicDirs->addItem(Config->GetMusicDirectories().at(i));
}

void frmConfig::DisplayCustomLists()
{
    int i;

    ui->listCustomLists->clear();
    for (i = 0; i < Manager->GetCustomLists().count(); i++)
        ui->listCustomLists->addItem(Manager->GetCustomLists().at(i)->GetName());
}

void frmConfig::DisplayPlaylists()
{
    int i;

    ui->listPlaylists->clear();
    if (AvailablePlaylists().count() == 0)
    {
        if (LoadedList == NULL)
        {
            ui->lblAvailablePlaylists->setText("No playlists available");
        }
        else
        {
            ui->lblAvailablePlaylists->setText("No playlists available for Custom List " + LoadedList->GetName());
        }
        ui->btnAddPlaylist->setEnabled(true);
        ui->btnEditPlaylist->setEnabled(false);
        ui->btnDeletePlaylist->setEnabled(false);
    }
    else
    {
        if (LoadedList == NULL)
        {
            ui->lblAvailablePlaylists->setText("Playlists available");
        }
        else
        {
            ui->lblAvailablePlaylists->setText("Playlists available for Custom List " + LoadedList->GetName());
        }
        for (i = 0; i < AvailablePlaylists().count();i++)
        {
            ui->listPlaylists->addItem(AvailablePlaylists().at(i)->GetName());
        }
        ui->btnAddPlaylist->setEnabled(true);
        ui->btnEditPlaylist->setEnabled(true);
        ui->btnDeletePlaylist->setEnabled(true);
    }
}

void frmConfig::btnAddDirectoryClicked()
{
    QFileDialog libdialog;
    QString dirname;

    libdialog.setFileMode(QFileDialog::Directory);
    libdialog.setOption(QFileDialog::ShowDirsOnly,true);
    dirname=libdialog.getExistingDirectory(this,tr("Select Album"));
    Config->AddDirectory(dirname);
}

void frmConfig::btnRemoveDirectoryClicked()
{
    if (ui->listMusicDirs->currentRow() >= 0)
    {
        Config->DeleteDirectory(ui->listMusicDirs->currentItem()->text());
    }
}

void frmConfig::btnAddListClicked()
{
    SKG_MusicLibrary *Library;
    int i;
    QDir *musicdir;

    Library = new SKG_MusicLibrary();
    for (i = 0; i < Config->GetMusicDirectories().count(); i++)
    {
        musicdir = new QDir(Config->GetMusicDirectories().at(i));
        Library->AddDirectory(musicdir);
    }

    frmAddEditList AddListForm;
    AddListForm.ProcessAddList(Library);
    if (AddListForm.exec() == QDialog::Accepted)
    {
        Manager->AddList(AddListForm.GetAlbumList());
        DisplayCustomLists();
    }
}

void frmConfig::btnDeleteListClicked()
{
    QMessageBox *msgbox;
    CustomAlbumList *list;

    if (ui->listCustomLists->currentRow() == -1)
        return;

    list = Manager->RetrieveListByName(ui->listCustomLists->currentItem()->text());
    msgbox = new QMessageBox(QMessageBox::Warning,"Delete Custom List",
                             "Are you sure you wish to delete custom album list " + list->GetName() + "?",
                             QMessageBox::Yes | QMessageBox::No,this);
    if(msgbox->exec() == QMessageBox::Yes)
        Manager->RemoveList(ui->listCustomLists->currentRow());

    DisplayCustomLists();
}

void frmConfig::btnEditListCLicked()
{
    SKG_MusicLibrary *Library;
    int i;
    QDir *musicdir;
    CustomAlbumList *list;
    bool albumsavailable;
    SKG_Album *curralbum;

    if (ui->listCustomLists->currentRow() == -1)
        return;

    Library = new SKG_MusicLibrary();
    for (i = 0; i < Config->GetMusicDirectories().count(); i++)
    {
        musicdir = new QDir(Config->GetMusicDirectories().at(i));
        Library->AddDirectory(musicdir);
    }

    list = Manager->RetrieveListByName(ui->listCustomLists->currentItem()->text());
    for (i = 0; i < list->GetAlbumNumbers().count(); i++)
    {
        curralbum = Library->GetAlbumByNumber(list->GetAlbumNumbers().at(i));
        curralbum->SetAvaialble(false);
    }
    foreach(SKG_Artist *artist,Library->GetArtists())
    {
        albumsavailable = false;
        foreach (SKG_Album *album,artist->GetAlbums())
        {
            if (album->IsAvailable())
                albumsavailable = true;
        }
        if (!albumsavailable)
            artist->SetAvaialble(false);
    }

    frmAddEditList EditListForm;
    EditListForm.ProcessEditList(Library,list);
    EditListForm.exec();
    DisplayCustomLists();
}

void frmConfig::btnAddPlaylistClicked()
{
    SKG_MusicLibrary *Library;
    int i;
    QDir *musicdir;

    Library = new SKG_MusicLibrary();
    for (i = 0; i < Config->GetMusicDirectories().count(); i++)
    {
        musicdir = new QDir(Config->GetMusicDirectories().at(i));
        Library->AddDirectory(musicdir);
    }

    frmAddEditPlaylist AddListForm;
    AddListForm.ProcessAddList(Library,LoadedList);
    if (AddListForm.exec() == QDialog::Accepted)
    {
        PManager->AddList(AddListForm.GetPlaylist());
        DisplayPlaylists();
    }
}

void frmConfig::btnDeletePlaylistClicked()
{
    QMessageBox *msgbox;
    Playlist *list;

    if (ui->listPlaylists->currentRow() == -1)
        return;

    list = PManager->RetrieveListByName(ui->listPlaylists->currentItem()->text());
    msgbox = new QMessageBox(QMessageBox::Warning,"Delete Playlist",
                             "Are you sure you wish to delete playlist " + list->GetName() + "?",
                             QMessageBox::Yes | QMessageBox::No,this);
    if(msgbox->exec() == QMessageBox::Yes)
        PManager->RemoveList(ui->listPlaylists->currentRow());

    DisplayPlaylists();
}

void frmConfig::btnEditPlaylistClicked()
{
    SKG_MusicLibrary *Library;
    int i;
    QDir *musicdir;
    Playlist *list;
    bool albumsavailable;
    SKG_Album *curralbum;

    if (ui->listPlaylists->currentRow() == -1)
        return;

    Library = new SKG_MusicLibrary();
    for (i = 0; i < Config->GetMusicDirectories().count(); i++)
    {
        musicdir = new QDir(Config->GetMusicDirectories().at(i));
        Library->AddDirectory(musicdir);
    }

    list = PManager->RetrieveListByName(ui->listPlaylists->currentItem()->text());

    frmAddEditPlaylist EditListForm;
    EditListForm.ProcessEditList(Library,list,LoadedList);
    if (EditListForm.exec() == QDialog::Accepted)
    {
        PManager->RemoveList(ui->listPlaylists->currentRow());
        PManager->AddList(EditListForm.GetPlaylist());
    }
    DisplayPlaylists();
}

void frmConfig::btnSaveClicked()
{
    if (ui->rbNetbook->isChecked())
        Config->SetOperatingMode(modeNetbook);
    else
        Config->SetOperatingMode(modeNormal);

    Config->SetConnected(ui->chkConnected->isChecked());
    Config->SetSlidingSound(ui->chkSlidingSound->isChecked());
    Config->SetAnimationEnabled(ui->chkAnimation->isChecked());
    Config->SetRandomTrackEnabled(ui->chkRandom->isChecked());

    if (ui->rbLarge->isChecked())
        Config->SetCollectionSize(sizeLarge);
    else
        Config->SetCollectionSize(sizeSmall);

    SaveConfigFile();
    Manager->SaveCustomListFile();
    Translator->SaveCustomKeysFile();
    PManager->SavePlaylistFile();
    accept();
}

void frmConfig::Initialize(JukeboxConfig *cfg,
                           CustomListManager *listmgr,
                           KeyTranslator *translator,
                           PlaylistManager *plistmgr,
                           CustomAlbumList *list)
{
    Config = cfg;
    Manager = listmgr;
    Translator = translator;
    PManager = plistmgr;
    LoadedList = list;

    if (Config->GetOperatingMode() == modeNetbook)
        ui->rbNetbook->setChecked(true);
    else if (Config->GetOperatingMode() == modeNormal)
        ui->rbNormal->setChecked(true);

    ui->chkConnected->setChecked(Config->IsConnected());
    ui->chkSlidingSound->setChecked(Config->PlaySlidingSound());
    ui->chkAnimation->setChecked((Config->PlayAnimation()));
    ui->chkRandom->setChecked((Config->PlayRandomTrack()));

    if (Config->GetCollectionSize() == sizeLarge)
        ui->rbLarge->setChecked(true);
    else
        ui->rbSmall->setChecked(true);

    if (Manager->ListCount() > 0)
    {
        ui->cbMapto->addItem("CustomList--None");
        for (int i = 0;i < Manager->GetCustomLists().count();i++)
        {
            ui->cbMapto->addItem("CustomList--" + Manager->GetCustomLists().at(i)->GetName());
        }
    }
    if (PManager->ListCount() > 0)
    {
        for (int i = 0;i < PManager->GetPlaylists().count();i++)
        {
            ui->cbMapto->addItem("Playlist--" + PManager->GetPlaylists().at(i)->GetName());
            ui->cbMapto->addItem("Playlist(R)--" + PManager->GetPlaylists().at(i)->GetName());
        }
    }

    DisplayMusicDirectories();
    DisplayCustomLists();
    DisplayPlaylists();
}

void frmConfig::LoadKeyComboBoxes()
{
    ui->cbKeyin->clear();
    ui->cbKeyin->addItem("A",QVariant(Qt::Key_A));
    ui->cbKeyin->addItem("B",QVariant(Qt::Key_B));
    ui->cbKeyin->addItem("C",QVariant(Qt::Key_C));
    ui->cbKeyin->addItem("D",QVariant(Qt::Key_D));
    ui->cbKeyin->addItem("E",QVariant(Qt::Key_E));
    ui->cbKeyin->addItem("F",QVariant(Qt::Key_F));
    ui->cbKeyin->addItem("G",QVariant(Qt::Key_G));
    ui->cbKeyin->addItem("H",QVariant(Qt::Key_H));
    ui->cbKeyin->addItem("I",QVariant(Qt::Key_I));
    ui->cbKeyin->addItem("J",QVariant(Qt::Key_J));
    ui->cbKeyin->addItem("K",QVariant(Qt::Key_K));
    ui->cbKeyin->addItem("L",QVariant(Qt::Key_L));
    ui->cbKeyin->addItem("M",QVariant(Qt::Key_M));
    ui->cbKeyin->addItem("N",QVariant(Qt::Key_N));
    ui->cbKeyin->addItem("O",QVariant(Qt::Key_O));
    ui->cbKeyin->addItem("P",QVariant(Qt::Key_P));
    ui->cbKeyin->addItem("Q",QVariant(Qt::Key_Q));
    ui->cbKeyin->addItem("R",QVariant(Qt::Key_R));
    ui->cbKeyin->addItem("S",QVariant(Qt::Key_S));
    ui->cbKeyin->addItem("T",QVariant(Qt::Key_T));
    ui->cbKeyin->addItem("U",QVariant(Qt::Key_U));
    ui->cbKeyin->addItem("V",QVariant(Qt::Key_V));
    ui->cbKeyin->addItem("W",QVariant(Qt::Key_W));
    ui->cbKeyin->addItem("X",QVariant(Qt::Key_X));
    ui->cbKeyin->addItem("Y",QVariant(Qt::Key_Y));
    ui->cbKeyin->addItem("Z",QVariant(Qt::Key_Z));
    ui->cbKeyin->addItem("1",QVariant(Qt::Key_1));
    ui->cbKeyin->addItem("2",QVariant(Qt::Key_2));
    ui->cbKeyin->addItem("3",QVariant(Qt::Key_3));
    ui->cbKeyin->addItem("4",QVariant(Qt::Key_4));
    ui->cbKeyin->addItem("5",QVariant(Qt::Key_5));
    ui->cbKeyin->addItem("6",QVariant(Qt::Key_6));
    ui->cbKeyin->addItem("7",QVariant(Qt::Key_7));
    ui->cbKeyin->addItem("8",QVariant(Qt::Key_8));
    ui->cbKeyin->addItem("9",QVariant(Qt::Key_9));
    ui->cbKeyin->addItem("0",QVariant(Qt::Key_0));
    ui->cbKeyin->addItem("F1",QVariant(Qt::Key_F1));
    ui->cbKeyin->addItem("F2",QVariant(Qt::Key_F2));
    ui->cbKeyin->addItem("F3",QVariant(Qt::Key_F3));
    ui->cbKeyin->addItem("F4",QVariant(Qt::Key_F4));
    ui->cbKeyin->addItem("F5",QVariant(Qt::Key_F5));
    ui->cbKeyin->addItem("F6",QVariant(Qt::Key_F6));
    ui->cbKeyin->addItem("F7",QVariant(Qt::Key_F7));
    ui->cbKeyin->addItem("F8",QVariant(Qt::Key_F8));
    ui->cbKeyin->addItem("F9",QVariant(Qt::Key_F9));
    ui->cbKeyin->addItem("F10",QVariant(Qt::Key_F10));
    ui->cbKeyin->addItem("F11",QVariant(Qt::Key_F11));
    ui->cbKeyin->addItem("F12",QVariant(Qt::Key_F12));
    ui->cbKeyin->addItem("Space",QVariant(Qt::Key_Space));
    ui->cbKeyin->addItem("Esc",QVariant(Qt::Key_Escape));
    ui->cbKeyin->addItem("Space",QVariant(Qt::Key_Space));
    ui->cbKeyin->addItem("`",QVariant(Qt::Key_Agrave));
    ui->cbKeyin->addItem("!",QVariant(Qt::Key_Exclam));
    ui->cbKeyin->addItem("@",QVariant(Qt::Key_At));
    ui->cbKeyin->addItem("#",QVariant(Qt::Key_NumberSign));
    ui->cbKeyin->addItem("$",QVariant(Qt::Key_Dollar));
    ui->cbKeyin->addItem("%",QVariant(Qt::Key_Percent));
    ui->cbKeyin->addItem("^",QVariant(Qt::Key_AsciiCircum));
    ui->cbKeyin->addItem("&",QVariant(Qt::Key_Ampersand));
    ui->cbKeyin->addItem("*",QVariant(Qt::Key_Asterisk));
    ui->cbKeyin->addItem("(",QVariant(Qt::Key_ParenLeft));
    ui->cbKeyin->addItem(")",QVariant(Qt::Key_ParenRight));
    ui->cbKeyin->addItem("-",QVariant(Qt::Key_Minus));
    ui->cbKeyin->addItem("_",QVariant(Qt::Key_Underscore));
    ui->cbKeyin->addItem("=",QVariant(Qt::Key_Equal));
    ui->cbKeyin->addItem("+",QVariant(Qt::Key_Plus));
    ui->cbKeyin->addItem("\\",QVariant(Qt::Key_Backslash));
    ui->cbKeyin->addItem("|",QVariant(Qt::Key_Bar));
    ui->cbKeyin->addItem("BackSp",QVariant(Qt::Key_Backspace));
    ui->cbKeyin->addItem("Insert",QVariant(Qt::Key_Insert));
    ui->cbKeyin->addItem("Delete",QVariant(Qt::Key_Delete));
    ui->cbKeyin->addItem("Home",QVariant(Qt::Key_Home));
    ui->cbKeyin->addItem("End",QVariant(Qt::Key_End));
    ui->cbKeyin->addItem("Page Up",QVariant(Qt::Key_PageUp));
    ui->cbKeyin->addItem("Page Down",QVariant(Qt::Key_PageDown));
    ui->cbKeyin->addItem("Tab",QVariant(Qt::Key_Tab));
    ui->cbKeyin->addItem("[",QVariant(Qt::Key_BracketLeft));
    ui->cbKeyin->addItem("{",QVariant(Qt::Key_BraceLeft));
    ui->cbKeyin->addItem("]",QVariant(Qt::Key_BracketRight));
    ui->cbKeyin->addItem("}",QVariant(Qt::Key_BraceLeft));
    ui->cbKeyin->addItem("Caps Lock",QVariant(Qt::Key_CapsLock));
    ui->cbKeyin->addItem("Num Lock",QVariant(Qt::Key_NumLock));
    ui->cbKeyin->addItem("Scroll Lock",QVariant(Qt::Key_ScrollLock));
    ui->cbKeyin->addItem(";",QVariant(Qt::Key_Semicolon));
    ui->cbKeyin->addItem(":",QVariant(Qt::Key_Colon));
    ui->cbKeyin->addItem("'",QVariant(Qt::Key_Apostrophe));
    ui->cbKeyin->addItem("\"",QVariant(Qt::Key_QuoteDbl));
    ui->cbKeyin->addItem("Shift",QVariant(Qt::Key_Shift));
    ui->cbKeyin->addItem(",",QVariant(Qt::Key_Comma));
    ui->cbKeyin->addItem(".",QVariant(Qt::Key_Period));
    ui->cbKeyin->addItem("/",QVariant(Qt::Key_Slash));
    ui->cbKeyin->addItem("<",QVariant(Qt::Key_Greater));
    ui->cbKeyin->addItem(">",QVariant(Qt::Key_Less));
    ui->cbKeyin->addItem("?",QVariant(Qt::Key_Question));
    ui->cbKeyin->addItem("Ctrl",QVariant(Qt::Key_Control));
    ui->cbKeyin->addItem("Alt",QVariant(Qt::Key_Alt));
    ui->cbKeyin->addItem("Win Key",QVariant(Qt::Key_Meta));
    ui->cbKeyin->addItem("Menu",QVariant(Qt::Key_Menu));
    ui->cbKeyin->addItem("Arrow Left",QVariant(Qt::Key_Left));
    ui->cbKeyin->addItem("Arrow Right",QVariant(Qt::Key_Right));
    ui->cbKeyin->addItem("Arrow Up",QVariant(Qt::Key_Up));
    ui->cbKeyin->addItem("Arrow Down",QVariant(Qt::Key_Down));
    ui->cbKeyin->setCurrentIndex(0);
    //
    ui->cbMapto->addItem("Ctrl-A (Album Art)");
    ui->cbMapto->addItem("Ctrl-C (Clear Track List)");
    ui->cbMapto->addItem("Ctrl-D (Add to Playlist)");
    ui->cbMapto->addItem("Ctrl-G (Config Form)");
    ui->cbMapto->addItem("Ctrl-L (Load Custom List)");
    ui->cbMapto->addItem("Ctrl-M (Minimize)");
    ui->cbMapto->addItem("Ctrl-N (Next Track)");
    ui->cbMapto->addItem("Ctrl-O (Options)");
    ui->cbMapto->addItem("Ctrl-P (Load Playlist)");
    ui->cbMapto->addItem("Ctrl-R (CD Ripper)");
    ui->cbMapto->addItem("Ctrl-S (Search for Track)");
    ui->cbMapto->addItem("Ctrl-T (Track List Form)");
    ui->cbMapto->addItem("Enter (Add Track)");
    ui->cbMapto->addItem("Space (Pause/Unpause)");
    ui->cbMapto->addItem("Esc (Quit Jukebox)");
    ui->cbMapto->addItem("1");
    ui->cbMapto->addItem("2");
    ui->cbMapto->addItem("3");
    ui->cbMapto->addItem("4");
    ui->cbMapto->addItem("5");
    ui->cbMapto->addItem("6");
    ui->cbMapto->addItem("7");
    ui->cbMapto->addItem("8");
    ui->cbMapto->addItem("9");
    ui->cbMapto->addItem("0");
    ui->cbMapto->addItem("Left");
    ui->cbMapto->addItem("Right");
    ui->cbMapto->addItem("Up");
    ui->cbMapto->addItem("Down");
    ui->cbMapto->addItem("0..9");
    ui->cbMapto->addItem("A");
    ui->cbMapto->addItem("B");
    ui->cbMapto->addItem("C");
    ui->cbMapto->addItem("D");
    ui->cbMapto->addItem("E");
    ui->cbMapto->addItem("F");
    ui->cbMapto->addItem("G");
    ui->cbMapto->addItem("H");
    ui->cbMapto->addItem("I");
    ui->cbMapto->addItem("J");
    ui->cbMapto->addItem("K");
    ui->cbMapto->addItem("L");
    ui->cbMapto->addItem("M");
    ui->cbMapto->addItem("N");
    ui->cbMapto->addItem("O");
    ui->cbMapto->addItem("P");
    ui->cbMapto->addItem("Q");
    ui->cbMapto->addItem("R");
    ui->cbMapto->addItem("S");
    ui->cbMapto->addItem("T");
    ui->cbMapto->addItem("U");
    ui->cbMapto->addItem("V");
    ui->cbMapto->addItem("W");
    ui->cbMapto->addItem("X");
    ui->cbMapto->addItem("Y");
    ui->cbMapto->addItem("Z");

    ui->cbMapto->setCurrentIndex(0);
}


void frmConfig::btnAddKeyClicked()
{
    KeyStroke in,out;

    in.KeyCode = ui->cbKeyin->itemData(ui->cbKeyin->currentIndex()).toInt();
    in.Ctrl = (ui->chkKeyinCtrl->isChecked());
    in.Alt = (ui->chkKeyinAlt->isChecked());
    in.Shft = (ui->chkKeyinShift->isChecked());

    out.Ctrl = false;
    out.Alt = false;
    out.Shft = false;
    out.KeyCode = 0;
    switch (ui->cbMapto->currentIndex())
    {
        case 0:
            out.KeyCode = Qt::Key_A;
            out.Ctrl = true;
            break;
        case 1:
            out.KeyCode = Qt::Key_C;
            out.Ctrl = true;
            break;
        case 2:
            out.KeyCode = Qt::Key_D;
            out.Ctrl = true;
            break;
        case 3:
            out.KeyCode = Qt::Key_G;
            out.Ctrl = true;
            break;
        case 4:
            out.KeyCode = Qt::Key_L;
            out.Ctrl = true;
            break;
        case 5:
            out.KeyCode = Qt::Key_M;
            out.Ctrl = true;
            break;
        case 6:
            out.KeyCode = Qt::Key_N;
            out.Ctrl = true;
            break;
        case 7:
            out.KeyCode = Qt::Key_O;
            out.Ctrl = true;
            break;
        case 8:
            out.KeyCode = Qt::Key_P;
            out.Ctrl = true;
            break;
        case 9:
            out.KeyCode = Qt::Key_R;
            out.Ctrl = true;
            break;
        case 10:
            out.KeyCode = Qt::Key_S;
            out.Ctrl = true;
            break;
        case 11:
            out.KeyCode = Qt::Key_T;
            out.Ctrl = true;
            break;
        case 12:
            out.KeyCode = Qt::Key_Return;
            break;
        case 13:
            out.KeyCode = Qt::Key_Space;
            break;
        case 14:
            out.KeyCode = Qt::Key_Escape;
            break;
        case 15:
            out.KeyCode = Qt::Key_1;
            break;
        case 16:
            out.KeyCode = Qt::Key_2;
            break;
        case 17:
            out.KeyCode = Qt::Key_3;
            break;
        case 18:
            out.KeyCode = Qt::Key_4;
            break;
        case 19:
            out.KeyCode = Qt::Key_5;
            break;
        case 20:
            out.KeyCode = Qt::Key_6;
            break;
        case 21:
            out.KeyCode = Qt::Key_7;
            break;
        case 22:
            out.KeyCode = Qt::Key_8;
            break;
        case 23:
            out.KeyCode = Qt::Key_9;
            break;
        case 24:
            out.KeyCode = Qt::Key_0;
            break;
        case 25:
            out.KeyCode = Qt::Key_Left;
            break;
        case 26:
            out.KeyCode = Qt::Key_Right;
            break;
        case 27:
            out.KeyCode = Qt::Key_Up;
            break;
        case 28:
            out.KeyCode = Qt::Key_Down;
            break;
        case 29:
            out.KeyCode = Qt::Key_Agrave;
            break;
        case 30:
            out.KeyCode = Qt::Key_A;
            break;
        case 31:
            out.KeyCode = Qt::Key_B;
            break;
        case 32:
            out.KeyCode = Qt::Key_C;
            break;
        case 33:
            out.KeyCode = Qt::Key_D;
            break;
        case 34:
            out.KeyCode = Qt::Key_E;
            break;
        case 35:
            out.KeyCode = Qt::Key_F;
            break;
        case 36:
            out.KeyCode = Qt::Key_G;
            break;
        case 37:
            out.KeyCode = Qt::Key_H;
            break;
        case 38:
            out.KeyCode = Qt::Key_I;
            break;
        case 39:
            out.KeyCode = Qt::Key_J;
            break;
        case 40:
            out.KeyCode = Qt::Key_K;
            break;
        case 41:
            out.KeyCode = Qt::Key_L;
            break;
        case 42:
            out.KeyCode = Qt::Key_M;
            break;
        case 43:
            out.KeyCode = Qt::Key_N;
            break;
        case 44:
            out.KeyCode = Qt::Key_O;
            break;
        case 45:
            out.KeyCode = Qt::Key_P;
            break;
        case 46:
            out.KeyCode = Qt::Key_Q;
            break;
        case 47:
            out.KeyCode = Qt::Key_R;
            break;
        case 48:
            out.KeyCode = Qt::Key_S;
            break;
        case 49:
            out.KeyCode = Qt::Key_T;
            break;
        case 50:
            out.KeyCode = Qt::Key_U;
            break;
        case 51:
            out.KeyCode = Qt::Key_V;
            break;
        case 52:
            out.KeyCode = Qt::Key_W;
            break;
        case 53:
            out.KeyCode = Qt::Key_X;
            break;
        case 54:
            out.KeyCode = Qt::Key_Y;
            break;
        case 55:
            out.KeyCode = Qt::Key_Z;
            break;
    default:
            out.KeyCode = 0;
            out.Custom = ui->cbMapto->itemText(ui->cbMapto->currentIndex());
            break;
    }
    if (Translator->Contains(in))
    {
        frmDialog dialogform;
        if (dialogform.DisplayYesNo(Translator->KeyStrokeAsString(in) +
                                    " is already maaped to " +
                                    Translator->KeyStrokeAsString(out) +
                                    ". Do you wish to re-map it?") == QDialog::Rejected)
        {
            return;
        }
    }


    Translator->AddKeyMapping(in,out);
    ui->lblKeyStatus->setText(Translator->KeyStrokeAsString(in) + " mapped to " +
                              Translator->KeyStrokeAsString(out));

}

void frmConfig::btnClearKeysClicked()
{
    frmDialog dialogform;
    if (dialogform.DisplayYesNo("This will erase all custom key mappings."
                                "Do you wish to continue?") == QDialog::Accepted)
    Translator->Clear();
}

QList <Playlist*> frmConfig::AvailablePlaylists()
{
    if (LoadedList == NULL)
    {
        return PManager->GetPlaylists();
    }
    else
    {
        QList <Playlist*> tmplist;
        for (int i = 0;i < PManager->GetPlaylists().count();i++)
        {
            if (PManager->GetPlaylists().at(i)->GetCustomListName() == LoadedList->GetName())
            {
                tmplist.append(PManager->GetPlaylists().at(i));
            }
        }
        return tmplist;
    }
}

void frmConfig::ViewCurrentKeyMappings()
{
    Translator->ViewCurrentKeyMappings();
}
