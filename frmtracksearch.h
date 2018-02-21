#ifndef FRMTRACKSEARCH_H
#define FRMTRACKSEARCH_H

#include <QDialog>
#include "lib/skglib.h"

class TrackSearchNode
{
public:
    TrackSearchNode();

    QString TrackName;
    QString AlbumName;
    QString ArtistName;
    long TrackNumber;

    bool operator ==(const TrackSearchNode &other);
};

bool TrackLessThan(const TrackSearchNode *node1, const TrackSearchNode *node2);

namespace Ui {
    class FrmTrackSearch;
}

class FrmTrackSearch : public QDialog {
    Q_OBJECT
public:
    FrmTrackSearch(QWidget *parent = 0);
    ~FrmTrackSearch();

    void Initialize(QList <SKG_Album*> albums);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FrmTrackSearch *ui;

    QList <TrackSearchNode*> Tracks;
    QList <TrackSearchNode*> Matches;

    int IndexFirst(QString startswith);
    int IndexLast(QString startswith);

signals:
    void TrackAdd(long tracknum);

private slots:
    void AddButtonPressed();
    void UpPressed();
    void DownPressed();
    void KeyPressed(int keycode,bool shift);
    void DisplayMatches (QString startswith);
    void ShowKeyboard();
};

#endif // FRMTRACKSEARCH_H
