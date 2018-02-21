#include "frmaddeditlist.h"
#include "ui_frmaddeditlist.h"
#include "jukeboxconfig.h"
#include "frmkeyboard.h"
#include <QMessageBox>
#include <QDesktopWidget>

frmAddEditList::frmAddEditList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmAddEditList)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnAddAlbums->setPixmap(QPixmap(RightArrow()));
    ui->btnRemoveAlbums->setPixmap(QPixmap(LeftArrow()));

    QObject::connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(btnSaveClicked()));
    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(ui->treeAvailableAlbums,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(ProcessItemChecked(QTreeWidgetItem*,int)));
    QObject::connect(ui->treeAvailableAlbums,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(ProcessItemChecked(QTreeWidgetItem*,int)));
    QObject::connect(ui->treeAlbumsInList,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(ProcessItemChecked(QTreeWidgetItem*,int)));
    QObject::connect(ui->treeAlbumsInList,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(ProcessItemChecked(QTreeWidgetItem*,int)));
    QObject::connect(ui->btnAddAlbums,SIGNAL(clicked()),this,SLOT(AddAlbumsToList()));
    QObject::connect(ui->btnRemoveAlbums,SIGNAL(clicked()),this,SLOT(RemoveAlbumsFromList()));
    QObject::connect(ui->btnKeyboard,SIGNAL(clicked()),this,SLOT(ShowKeyboard()));
}

frmAddEditList::~frmAddEditList()
{
    delete ui;
}

void frmAddEditList::changeEvent(QEvent *e)
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

void frmAddEditList::DisplayAvailableAlbums()
{
    QTreeWidgetItem *artistitem;
    QTreeWidgetItem *albumitem;
    QStringList artistlist;
    QStringList albumlist;

    ui->treeAvailableAlbums->clear();
    foreach (SKG_Artist *artist,AvailableArtists)
    {
        if (!artist->IsAvailable())
            continue;

        artistlist.clear();
        artistlist.append(artist->GetArtistName());
        artistitem=new QTreeWidgetItem(artistlist,QTreeWidgetItem::Type);
        artistitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        artistitem->setCheckState(0,Qt::Unchecked);
        ui->treeAvailableAlbums->addTopLevelItem(artistitem);

        foreach(SKG_Album *album,artist->GetAlbums())
        {
            if (!album->IsAvailable())
                continue;
            albumlist.clear();
            albumlist.append(album->GetAlbumName());
            albumitem=new QTreeWidgetItem(artistitem,albumlist,QTreeWidgetItem::Type);
            albumitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
            albumitem->setCheckState(0,Qt::Unchecked);
        }
    }
}

void frmAddEditList::DisplayAlbumsInList()
{
    QTreeWidgetItem *artistitem;
    QTreeWidgetItem *albumitem;
    QStringList artistlist;
    QStringList albumlist;

    ui->treeAlbumsInList->clear();
    foreach (SKG_Artist *artist,ArtistsInList)
    {
        artistlist.clear();
        artistlist.append(artist->GetArtistName());
        artistitem=new QTreeWidgetItem(artistlist,QTreeWidgetItem::Type);
        artistitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        artistitem->setCheckState(0,Qt::Unchecked);
        ui->treeAlbumsInList->addTopLevelItem(artistitem);

        foreach(SKG_Album *album,artist->GetAlbums())
        {
            if (album->IsAvailable())
                continue;
            albumlist.clear();
            albumlist.append(album->GetAlbumName());
            albumitem=new QTreeWidgetItem(artistitem,albumlist,QTreeWidgetItem::Type);
            albumitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
            albumitem->setCheckState(0,Qt::Unchecked);
        }
    }
}

void frmAddEditList::ProcessAddList(SKG_MusicLibrary *lib)
{
    Library = lib;
    ui->lblHeader->setText("Add Custom List");
    AvailableArtists = Library->GetArtists();
    foreach (SKG_Artist *artist,AvailableArtists)
        artist->SetAvaialble(true);
    AvailableAlbums = Library->GetAlbums();
    foreach(SKG_Album *album,AvailableAlbums)
        album->SetAvaialble(true);
    AlbumList = new CustomAlbumList();
    DisplayAvailableAlbums();
}

void frmAddEditList::ProcessEditList(SKG_MusicLibrary *lib,CustomAlbumList *list)
{
    Library = lib;
    ui->lblHeader->setText("Edit Custom List");
    AvailableArtists = Library->GetArtists();
    AvailableAlbums = Library->GetAlbums();
    AlbumList = list;
    ui->txtName->setText(AlbumList->GetName());
    RefreshLists();
    DisplayAvailableAlbums();
    DisplayAlbumsInList();
}

void frmAddEditList::AddAlbumsToList()
{
    int i,j;
    QTreeWidgetItem *artistitem;
    QTreeWidgetItem *albumitem;
    SKG_Artist *currartist;
    SKG_Album* curralbum;
    bool albumsavailable;

    for (i = 0; i < ui->treeAvailableAlbums->topLevelItemCount(); i++)
    {
        artistitem = ui->treeAvailableAlbums->topLevelItem(i);
        if (artistitem->checkState(0) == Qt::Checked)
        {
            currartist = ArtistByName(AvailableArtists,artistitem->text(0));
            for (j = 0; j < artistitem->childCount(); j++)
            {
                albumitem = artistitem->child(j);
                if (albumitem->checkState(0) == Qt::Checked)
                {
                    curralbum = AlbumByName(AvailableAlbums,currartist->GetArtistName(),albumitem->text(0));
                    curralbum->SetAvaialble(false);
                }
            }
            albumsavailable = false;
            foreach (SKG_Album *album,currartist->GetAlbums())
            {
                if (album->IsAvailable())
                    albumsavailable = true;
            }
            if (!albumsavailable)
                currartist->SetAvaialble(false);
        }
    }
    RefreshLists();
}

void frmAddEditList::RemoveAlbumsFromList()
{
    int i,j;
    QTreeWidgetItem *artistitem;
    QTreeWidgetItem *albumitem;
    SKG_Artist *currartist;
    SKG_Album* curralbum;

    for (i = 0; i < ui->treeAlbumsInList->topLevelItemCount(); i++)
    {
        artistitem = ui->treeAlbumsInList->topLevelItem(i);
        if (artistitem->checkState(0) == Qt::Checked)
        {
            currartist = ArtistByName(ArtistsInList,artistitem->text(0));
            if (!currartist->IsAvailable())
                currartist->SetAvaialble(true);

            for (j = 0; j < artistitem->childCount(); j++)
            {
                albumitem = artistitem->child(j);
                if (albumitem->checkState(0) == Qt::Checked)
                {
                    curralbum = AlbumByName(AlbumsInList,currartist->GetArtistName(),albumitem->text(0));
                    curralbum->SetAvaialble(true);
                }
            }
        }
    }
    RefreshLists();
}

void frmAddEditList::RefreshLists()
{
    int i;
    SKG_Artist *currartist;
    QList <int> albumnumlist;
    bool artistadded;

    AvailableArtists.clear();
    AvailableAlbums.clear();
    ArtistsInList.clear();
    AlbumsInList.clear();

    for (i = 0; i < Library->GetArtists().count(); i++)
    {
        currartist = Library->GetArtists().at(i);
        if (currartist->IsAvailable())
        {
            AvailableArtists.append(currartist);
            artistadded = false;
            foreach (SKG_Album *album,currartist->GetAlbums())
            {
                if (album->IsAvailable())
                    AvailableAlbums.append(album);
                else
                {
                    AlbumsInList.append(album);
                    albumnumlist.append(album->GetAlbumNumber());
                    if (!artistadded)
                    {
                        ArtistsInList.append(currartist);
                        artistadded = true;
                    }
                }

            }
        }
        else
        {
            ArtistsInList.append(currartist);
            foreach(SKG_Album *album,currartist->GetAlbums())
            {
                AlbumsInList.append(album);
                albumnumlist.append(album->GetAlbumNumber());
            }
        }
    }
    AlbumList->Clear();
    AlbumList->SetName(ui->txtName->text().trimmed());
    AlbumList->AddAlbumNumbers(albumnumlist);
    DisplayAvailableAlbums();
    DisplayAlbumsInList();
}

void frmAddEditList::ProcessItemChecked(QTreeWidgetItem *item, int column)
{
    int i;
    QTreeWidgetItem *childitem;
    bool otheralbumschecked;

    if (item->parent() == NULL)
    {
        for (i = 0; i < item->childCount(); i++)
        {
            childitem = item->child(i);
            childitem->setCheckState(0,item->checkState(0));
        }
    }
    else
    {
        if (item->checkState(0) == Qt::Checked)
            item->parent()->setCheckState(0,Qt::Checked);
        else
        {
            otheralbumschecked = false;
            for (i = 0; i < item->parent()->childCount(); i++)
            {
                childitem = item->parent()->child(i);
                if (childitem->checkState(0) == Qt::Checked)
                    otheralbumschecked = true;
            }
            if (otheralbumschecked == false)
                item->parent()->setCheckState(0,Qt::Unchecked);
        }
    }
}

SKG_Artist* frmAddEditList::ArtistByName(QList <SKG_Artist*> artistlist,QString artistname)
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


SKG_Album* frmAddEditList::AlbumByName(QList <SKG_Album*> albumlist,QString artistname,QString albumname)
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

void frmAddEditList::btnSaveClicked()
{
    RefreshLists();
    if (ui->txtName->text().trimmed() == "")
    {
        QMessageBox msgbox;
        msgbox.setText("Please enter a name for the custom list");
        msgbox.exec();
        return;
    }
    else if (AlbumList->GetAlbumNumbers().count() == 0)
    {
        QMessageBox msgbox;
        msgbox.setText("No albums in custom list");
        msgbox.exec();
        return;
    }
    else
        accept();
}

void frmAddEditList::KeyPressed(int keycode,bool shift)
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

void frmAddEditList::ShowKeyboard()
{
    QDesktopWidget w;
    FrmKeyboard *Kbd = new FrmKeyboard;
    QObject::connect(Kbd,SIGNAL(KeyPressed(int,bool)),this,SLOT(KeyPressed(int,bool)));
    Kbd->move((w.screenGeometry().width() - Kbd->width()) / 2,
              w.screenGeometry().bottom() - Kbd->height());
    Kbd->Display();
}
