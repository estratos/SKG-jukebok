#include "frmtracksearch.h"
#include "ui_frmtracksearch.h"
#include "jukeboxconfig.h"
#include "frmkeyboard.h"
#include <QDesktopWidget>

TrackSearchNode::TrackSearchNode()
{
    TrackName = "";
    ArtistName = "";
    AlbumName = "";
    TrackNumber = 0;
}

bool TrackSearchNode::operator ==(const TrackSearchNode &other)
{
    return (this->TrackName == other.TrackName);
}

FrmTrackSearch::FrmTrackSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmTrackSearch)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnDown->setPixmap(QPixmap(DownArrow()));
    ui->btnUp->setPixmap(QPixmap(UpArrow()));

    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(AddButtonPressed()));
    QObject::connect(ui->btnUp,SIGNAL(clicked()),this,SLOT(UpPressed()));
    QObject::connect(ui->btnDown,SIGNAL(clicked()),this,SLOT(DownPressed()));
    QObject::connect(ui->txtTrackName,SIGNAL(textChanged(QString)),this,SLOT(DisplayMatches(QString)));
    QObject::connect(ui->btnKeyboard,SIGNAL(clicked()),this,SLOT(ShowKeyboard()));
}

FrmTrackSearch::~FrmTrackSearch()
{
    delete ui;
}

void FrmTrackSearch::changeEvent(QEvent *e)
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

void FrmTrackSearch::Initialize(QList<SKG_Album*> albums)
{
    TrackSearchNode *node;
    SKG_Album *curralbum;
    SKG_Track *currtrack;

    for (int i = 0; i < albums.count(); i++)
    {
        curralbum = albums.at(i);
        for (int j = 1; j < curralbum->GetTracks().count(); j++)
        {
            currtrack = curralbum->GetTracks().at(j);
            node = new TrackSearchNode;
            node->ArtistName = curralbum->GetArtistName();
            node->AlbumName = curralbum->GetAlbumName();
            node->TrackName = currtrack->GetTrackNameSansNumber();
            node->TrackNumber = curralbum->GetAlbumNumber() * 100 + currtrack->GetTrackNumber();
            Tracks.append(node);
        }
    }
    qSort(Tracks.begin(),Tracks.end(),TrackLessThan);
}

void FrmTrackSearch::DisplayMatches(QString startswith)
{
    Matches.clear();
    ui->listNames->clear();
    if (startswith == "")
        return;

    int first = IndexFirst(startswith);
    int last = IndexLast(startswith);

    if (first != -1)
    {
        for (int i = first; i <= last; i++)
        {
            Matches.append(Tracks.at(i));
            ui->listNames->addItem(Tracks.at(i)->TrackName + "(" +
                                   Tracks.at(i)->ArtistName + ":" +
                                   Tracks.at(i)->AlbumName + ")");
        }
        ui->listNames->setCurrentRow(0);
    }
}

void FrmTrackSearch::AddButtonPressed()
{
    int index = ui->listNames->currentRow();
    if (index != -1)
    {
        TrackAdd(Matches.at(index)->TrackNumber);
    }
    ui->lblStatus->setText("Track " + QString::number(Matches.at(index)->TrackNumber) +
                           ", " + Matches.at(index)->TrackName + " added to list.");
}

bool TrackLessThan(const TrackSearchNode *node1, const TrackSearchNode *node2)
{
    return (node1->TrackName.toLower() < node2->TrackName.toLower());
}

int FrmTrackSearch::IndexFirst(QString startswith)
{
    startswith = startswith.toLower();
    int i = 0;

    while (true)
    {
        if (Tracks.at(i)->TrackName.toLower().left(startswith.length()) == startswith)
            return i;
        else if (Tracks.at(i)->TrackName.toLower().left(startswith.length()) > startswith)
            return -1;
        else
            i++;
    }
}

int FrmTrackSearch::IndexLast(QString startswith)
{
    startswith = startswith.toLower();
    int i = Tracks.count() - 1;

    while (true)
    {
        if (Tracks.at(i)->TrackName.toLower().left(startswith.length()) == startswith)
            return i;
        else if (Tracks.at(i)->TrackName.toLower().left(startswith.length()) < startswith)
            return -1;
        else
            i--;
    }
}

void FrmTrackSearch::KeyPressed(int keycode,bool shift)
{
    if (keycode == Qt::Key_Backspace)
        ui->txtTrackName->backspace();
    else
    {
        if (shift)
            ui->txtTrackName->insert(QString(QChar(keycode)).toUpper());
        else
            ui->txtTrackName->insert(QString(QChar(keycode)).toLower());
    }
}

void FrmTrackSearch::UpPressed()
{
    if (ui->listNames->count() == 0)
        return;

    if (ui->listNames->currentRow() < 0)
        return;

    if (ui->listNames->currentRow() > 0)
        ui->listNames->setCurrentRow(ui->listNames->currentRow() - 1);
}

void FrmTrackSearch::DownPressed()
{
    if (ui->listNames->count() == 0)
        return;

    if (ui->listNames->currentRow() < 0)
        return;

    if (ui->listNames->currentRow() < ui->listNames->count() - 1)
        ui->listNames->setCurrentRow(ui->listNames->currentRow() + 1);
}

void FrmTrackSearch::ShowKeyboard()
{
    QDesktopWidget w;
    FrmKeyboard *Kbd = new FrmKeyboard;
    QObject::connect(Kbd,SIGNAL(KeyPressed(int,bool)),this,SLOT(KeyPressed(int,bool)));
    Kbd->move((w.screenGeometry().width() - Kbd->width()) / 2,
              w.screenGeometry().bottom() - Kbd->height());
    Kbd->Display();
    delete Kbd;
}
