#include "frmaddeditplaylist.h"
#include "ui_frmaddeditplaylist.h"
#include "jukeboxconfig.h"
#include "frmkeyboard.h"
#include <QMessageBox>
#include <QDesktopWidget>

frmAddEditPlaylist::frmAddEditPlaylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmAddEditPlaylist)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnAddTracks->setPixmap(QPixmap(RightArrow()));
    ui->btnRemoveTracks->setPixmap(QPixmap(LeftArrow()));

    TracksToAdd = new QList <long>;
    CustomList = NULL;

    QObject::connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(btnSaveClicked()));
    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(ui->treeAvailableTracks,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(ProcessItemChecked(QTreeWidgetItem*,int)));
    QObject::connect(ui->treeAvailableTracks,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(ProcessItemChecked(QTreeWidgetItem*,int)));
    QObject::connect(ui->btnAddTracks,SIGNAL(clicked()),this,SLOT(AddTracksToList()));
    QObject::connect(ui->btnRemoveTracks,SIGNAL(clicked()),this,SLOT(RemoveTracksFromList()));
    QObject::connect(ui->btnMoveTrackUp,SIGNAL(clicked()),this,SLOT(MoveTrackUp()));
    QObject::connect(ui->btnMoveTrackDown,SIGNAL(clicked()),this,SLOT(MoveTrackDown()));
    QObject::connect(ui->btnKeyboard,SIGNAL(clicked()),this,SLOT(ShowKeyboard()));
}

frmAddEditPlaylist::~frmAddEditPlaylist()
{
    delete ui;
}

void frmAddEditPlaylist::changeEvent(QEvent *e)
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

void frmAddEditPlaylist::DisplayAvailableTracks()
{
    QTreeWidgetItem *artistitem;
    QTreeWidgetItem *albumitem;
    QTreeWidgetItem *trackitem;
    QStringList artistlist;
    QStringList albumlist;
    QStringList tracklist;

    ui->treeAvailableTracks->clear();
    if (CustomList == NULL)
    {
        foreach (SKG_Artist *artist,Library->GetArtists())
        {
            artistlist.clear();
            artistlist.append(artist->GetArtistName());
            artistitem=new QTreeWidgetItem(artistlist,QTreeWidgetItem::Type);
            ui->treeAvailableTracks->addTopLevelItem(artistitem);

            foreach(SKG_Album *album,artist->GetAlbums())
            {
                if (!album->IsAvailable())
                    continue;
                albumlist.clear();
                albumlist.append(album->GetAlbumName());
                albumitem=new QTreeWidgetItem(artistitem,albumlist,QTreeWidgetItem::Type);
                foreach(SKG_Track *track,album->GetTracks())
                {
                    if (track->GetTrackNumber() == 0)
                        continue;
                    if (!track->IsAvailable())
                        continue;
                    tracklist.clear();
                    tracklist.append(QString("%1").arg(track->GetTrackName()));
                    trackitem = new QTreeWidgetItem(albumitem,tracklist,QTreeWidgetItem::Type);
                    trackitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
                    trackitem->setCheckState(0,Qt::Unchecked);
                }
            }
        }
    }
    else
    {
        QStringList artistnames;
        SKG_Album* curralbum;

        for (int i = 0; i < CustomList->GetAlbumNumbers().count();i++)
        {
            curralbum = Library->GetAlbumByNumber(CustomList->GetAlbumNumbers().at(i));
            if (!artistnames.contains(curralbum->GetArtistName(),Qt::CaseInsensitive))
            {
                artistnames.append(curralbum->GetArtistName());
            }
        }
        //
        foreach(QString artistname,artistnames)
        {
            SKG_Artist* currartist = Library->GetArtistByName(artistname);

            artistlist.clear();
            artistlist.append(artistname);
            artistitem=new QTreeWidgetItem(artistlist,QTreeWidgetItem::Type);
            ui->treeAvailableTracks->addTopLevelItem(artistitem);

            foreach(SKG_Album *album,currartist->GetAlbums())
            {
                if (!CustomList->GetAlbumNumbers().contains(album->GetAlbumNumber()))
                    continue;
                albumlist.clear();
                albumlist.append(album->GetAlbumName());
                albumitem=new QTreeWidgetItem(artistitem,albumlist,QTreeWidgetItem::Type);
                foreach(SKG_Track *track,album->GetTracks())
                {
                    if (track->GetTrackNumber() == 0)
                        continue;
                    if (!track->IsAvailable())
                        continue;
                    tracklist.clear();
                    tracklist.append(QString("%1").arg(track->GetTrackName()));
                    trackitem = new QTreeWidgetItem(albumitem,tracklist,QTreeWidgetItem::Type);
                    trackitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
                    trackitem->setCheckState(0,Qt::Unchecked);
                }
            }
        }
    }
}

void frmAddEditPlaylist::DisplayTracksInList()
{
    QListWidgetItem *trackitem;
    SKG_Track *currtrack;
    int tracknum;
    int albumnum;
    QString trackname;

    ui->listTracksInList->clear();
    if (CustomList == NULL)
    {
        for (int i = 0;i < List->GetTrackNumbers(false)->count();i++)
        {
            tracknum = List->GetTrackNumbers(false)->at(i);
            currtrack = Library->GetTrackByNumber(tracknum);
            trackitem = new QListWidgetItem(QString("%1-%2").arg(QString::number(tracknum),5,'0').arg(currtrack->GetTrackName().mid(4).trimmed()));
            trackitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
            trackitem->setCheckState(Qt::Unchecked);
            ui->listTracksInList->addItem(trackitem);
        }
    }
    else
    {
        for (int i = 0;i < List->GetTrackNumbers(false)->count();i++)
        {
            tracknum = List->GetTrackNumbers(false)->at(i);
            //currtrack = Library->GetTrackByNumber(tracknum);
            currtrack = Library->GetAlbumByNumber(tracknum / 100)->GetTracks().at(tracknum % 100);
            trackitem = new QListWidgetItem(QString("%1-%2").arg(QString::number(tracknum),5,'0').arg(currtrack->GetTrackName().mid(4).trimmed()));
            trackitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
            trackitem->setCheckState(Qt::Unchecked);
            ui->listTracksInList->addItem(trackitem);
        }
    }
}

void frmAddEditPlaylist::ProcessAddList(SKG_MusicLibrary *lib,CustomAlbumList *list)
{
    Library = lib;
    if (list != NULL)
    {
        CustomList = list;
    }
    ui->lblHeader->setText("Add Playist");
    foreach (SKG_Album *curralbum,Library->GetAlbums())
    {
        foreach(SKG_Track *currtrack,curralbum->GetTracks())
        {
            currtrack->SetAvaialble(true);
        }
    }

    List = new Playlist();
    DisplayAvailableTracks();
}

void frmAddEditPlaylist::ProcessEditList(SKG_MusicLibrary *lib,Playlist *plist,CustomAlbumList *list)
{
    SKG_Track *currtrack;

    Library = lib;
    if (list != NULL)
    {
        CustomList = list;
    }
    ui->lblHeader->setText("Edit Playlist");
    List = plist;
    for (int i = 0; i < List->GetTrackNumbers(false)->count();i++)
    {
        currtrack = Library->GetTrackByNumber(List->GetTrackNumbers(false)->at(i));
        currtrack->SetAvaialble(false);
    }
    ui->txtName->setText(List->GetName());
    RefreshLists();
    DisplayAvailableTracks();
    DisplayTracksInList();
}

//void frmAddEditPlaylist::AddTracksToList()
//{
//    int i,j,k;
//    QTreeWidgetItem *artistitem;
//    QTreeWidgetItem *albumitem;
//    QTreeWidgetItem *trackitem;
//    SKG_Artist *currartist;
//    SKG_Album *curralbum;
//    SKG_Track *currtrack;
//    bool albumsavailable;
//    bool tracksavailable;
//    int tracknum;

//    for (i = 0; i < ui->treeAvailableTracks->topLevelItemCount(); i++)
//    {
//        artistitem = ui->treeAvailableTracks->topLevelItem(i);
//        currartist = ArtistByName(Library->GetArtists(),artistitem->text(0));
//        for (j = 0; j < artistitem->childCount(); j++)
//        {
//            albumitem = artistitem->child(j);
//            //curralbum = AlbumByName(Library->GetArtists(),currartist->GetArtistName(),albumitem->text(0));
//            curralbum = Library->GetAlbumByName(currartist->GetArtistName(),albumitem->text(0));
//            for (k = 0;k < albumitem->childCount();k++)
//            {
//                trackitem = albumitem->child(k);
//                currtrack = curralbum->GetTrackByName(trackitem->text(0));
//                if (trackitem->checkState(0) == Qt::Checked)
//                {
//                    tracknum = (curralbum->GetAlbumNumber() * 100) + currtrack->GetTrackNumber();
//                    List->AddTrackNumber(tracknum);
//                    currtrack->SetAvaialble(false);
//                }
//            }
//        }
//    }
//    RefreshLists();
//}

void frmAddEditPlaylist::AddTracksToList()
{
    for (int i = 0; i < TracksToAdd->count(); i++)
    {
        List->AddTrackNumber(TracksToAdd->at(i));
    }
    TracksToAdd->clear();
    RefreshLists();
}

void frmAddEditPlaylist::RemoveTracksFromList()
{
    int i;
    QListWidgetItem *trackitem;
    int tracknum;
    QStringList tmplist;
    SKG_Track *currtrack;

    for (i = 0;i < ui->listTracksInList->count();i++)
    {
        trackitem = ui->listTracksInList->item(i);
        if (trackitem->checkState() == Qt::Checked)
        {
            tmplist.clear();
            tmplist = trackitem->text().split("-");
            tracknum = tmplist.at(0).toInt();
            List->RemoveTrackNumber(tracknum);
            currtrack = Library->GetTrackByNumber(tracknum);
            currtrack->SetAvaialble(true);
        }
    }
    RefreshLists();
}

void frmAddEditPlaylist::RefreshLists()
{
    ui->treeAvailableTracks->clear();
    ui->listTracksInList->clear();
    DisplayAvailableTracks();
    DisplayTracksInList();
}

//void frmAddEditPlaylist::ProcessItemChecked(QTreeWidgetItem *item, int column)
//{
//    int i;
//    QTreeWidgetItem *childitem;
//    bool otheralbumschecked;

//    if (item->parent() == NULL)
//    {
//        for (i = 0; i < item->childCount(); i++)
//        {
//            childitem = item->child(i);
//            childitem->setCheckState(0,item->checkState(0));
//        }
//    }
//    else
//    {
//        if (item->checkState(0) == Qt::Checked)
//            item->parent()->setCheckState(0,Qt::Checked);
//        else
//        {
//            otheralbumschecked = false;
//            for (i = 0; i < item->parent()->childCount(); i++)
//            {
//                childitem = item->parent()->child(i);
//                if (childitem->checkState(0) == Qt::Checked)
//                    otheralbumschecked = true;
//            }
//            if (otheralbumschecked == false)
//                item->parent()->setCheckState(0,Qt::Unchecked);
//        }
//    }
//}

void frmAddEditPlaylist::ProcessItemChecked(QTreeWidgetItem *item, int column)
{
    if (item->childCount() == 0)
    {
        // Track item. We don't care about any others
        SKG_Artist *artist;
        SKG_Album *album;
        SKG_Track *track;

        artist = Library->GetArtistByName(item->parent()->parent()->text(0));
        album = Library->GetAlbumByName(artist->GetArtistName(),item->parent()->text(0));
        track = album->GetTrackByName(item->text(0));

        long tracknum = (album->GetAlbumNumber() * 100) + track->GetTrackNumber();

        if(item->checkState(0) == Qt::Checked)
        {
            TracksToAdd->append(tracknum);
            track->SetAvaialble(false);
        }
        else
        {
            TracksToAdd->removeAll(tracknum);
            track->SetAvaialble(true);
        }

        artist = NULL;
        album = NULL;
        track = NULL;
    }
}

SKG_Artist* frmAddEditPlaylist::ArtistByName(QList <SKG_Artist*> artistlist,QString artistname)
{
    foreach (SKG_Artist *artist,artistlist)
    {
        if (artist->GetArtistName() == artistname)
        {
            return artist;
            break;
        }
    }
    return NULL;
}


SKG_Album* frmAddEditPlaylist::AlbumByName(QList <SKG_Album*> albumlist,QString artistname,QString albumname)
{
    foreach (SKG_Album *album,albumlist)
    {
        if ((album->GetArtistName() == artistname) && (album->GetAlbumName() == albumname))
        {
            return album;
            break;
        }
    }
    return NULL;
}

Playlist* frmAddEditPlaylist::GetPlaylist()
{
    return List;
}

void frmAddEditPlaylist::btnSaveClicked()
{
    RefreshLists();
    if (ui->txtName->text().trimmed() == "")
    {
        QMessageBox msgbox;
        msgbox.setText("Please enter a name for the custom list");
        msgbox.exec();
        return;
    }
    List->SetName(ui->txtName->text().trimmed());
    List->SetCustomListName("None");
    accept();
}

void frmAddEditPlaylist::MoveTrackUp()
{
    int selected;
    selected = ui->listTracksInList->currentRow();
    if ((selected >= 1) && (selected <= List->Count()))
    {
        List->Swap(selected,selected - 1);
        DisplayTracksInList();
    }

}

void frmAddEditPlaylist::MoveTrackDown()
{
    int selected;
    selected = ui->listTracksInList->currentRow();
    if ((selected >= 0) && (selected < List->Count()))
    {
        List->Swap(selected,selected + 1);
        DisplayTracksInList();
    }
}

void frmAddEditPlaylist::KeyPressed(int keycode,bool shift)
{
    if (keycode == Qt::Key_Backspace)
        ui->txtName->backspace();
    else
    {
        if (shift)
            ui->txtName->insert(QString(QChar(keycode)).toUpper());
        else
            ui->txtName->insert(QString(QChar(keycode)).toLower());
    }
}

void frmAddEditPlaylist::ShowKeyboard()
{
    QDesktopWidget w;
    FrmKeyboard *Kbd = new FrmKeyboard;
    QObject::connect(Kbd,SIGNAL(KeyPressed(int,bool)),this,SLOT(KeyPressed(int,bool)));
    Kbd->move((w.screenGeometry().width() - Kbd->width()) / 2,
              w.screenGeometry().bottom() - Kbd->height());
    Kbd->Display();
}

