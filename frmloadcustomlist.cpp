#include "frmloadcustomlist.h"
#include "ui_frmloadcustomlist.h"
#include <QMessageBox>

frmLoadCustomList::frmLoadCustomList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmLoadCustomList)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    //QObject::connect(ui->btnLoad,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(ui->btnLoad,SIGNAL(clicked()),this,SLOT(ShowTrackListWarning()));
    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(reject()));
}

frmLoadCustomList::~frmLoadCustomList()
{
    delete ui;
}

void frmLoadCustomList::changeEvent(QEvent *e)
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

void frmLoadCustomList::Initialize(CustomListManager *listmanager,
                                   CustomAlbumList *currlist,
                                   SKG_MusicLibrary *lib)
{
    int i;
    int currlistindex;

    Manager = listmanager;
    OriginalList = currlist;
    ui->cmbLists->clear();
    currlistindex = 0;
    ui->cmbLists->addItem("None -- Display All Albums");
    for (i = 0; i < Manager->GetCustomLists().count(); i++)
    {
        ui->cmbLists->addItem(Manager->GetCustomLists().at(i)->GetName() + " -- "
                              + QString::number(Manager->GetCustomLists().at(i)->GetAlbumNumbers().count())
                              + " Albums");

        if (Manager->GetCustomLists().at(i) == currlist)
            currlistindex = i + 1;
    }
    SelectedList = currlist;
    Library = lib;
    QObject::connect(ui->cmbLists,SIGNAL(currentIndexChanged(int)),this,SLOT(ComboBoxItemChanged(int)));
    ui->cmbLists->setCurrentIndex(currlistindex);
    ComboBoxItemChanged(currlistindex);
}

void frmLoadCustomList::ComboBoxItemChanged(int newindex)
{
    int i;
    CustomAlbumList *currlist;
    SKG_Album *curralbum;
    QStringList strlist;

    if(newindex == -1)
        return;

    ui->txtAlbums->clear();
    if (newindex == 0)
        currlist = NULL;
    else
        currlist = Manager->GetCustomLists().at(newindex - 1);

    SelectedList = currlist;
    strlist.clear();
    if (currlist == NULL)
    {
        for (i = 0; i < Library->GetAlbums().count(); i++)
        {
            curralbum = Library->GetAlbums().at(i);
            strlist.append(curralbum->GetArtistName() + ": "
                           + curralbum->GetAlbumName());
        }
    }
    else
    {
        for (i = 0; i < currlist->GetAlbumNumbers().count(); i++)
        {
            curralbum = Library->GetAlbumByNumber(currlist->GetAlbumNumbers().at(i));
            strlist.append(curralbum->GetArtistName() + ": "
                           + curralbum->GetAlbumName());
        }
    }
    ui->txtAlbums->setText(strlist.join("\n"));
}

void frmLoadCustomList::ShowTrackListWarning()
{
    QMessageBox *msgbox;

    if (SelectedList == OriginalList)
        return;

    msgbox = new QMessageBox(QMessageBox::Warning,"Warning: Track List",
                             "Loading a new custom list will cause your existing track list to be cleared. Do you wish to continue?",
                             QMessageBox::Yes | QMessageBox::No,this);
    if(msgbox->exec() == QMessageBox::Yes)
        accept();
}
