#ifndef FRMTRACKLIST_H
#define FRMTRACKLIST_H

#include <QDialog>
#include <phonon/mediaobject.h>
//#include <Phonon/MediaObject>
#include <phonon/mediasource.h>
//#include <Phonon/MediaSource>
#include <QListWidgetItem>
#include "lib/skglib.h"
#include "globals.h"

namespace Ui {
    class frmTrackList;
}

class frmTrackList : public QDialog {
    Q_OBJECT
public:
    frmTrackList(QWidget *parent = 0);
    ~frmTrackList();
    void Initialize(QList<SKG_Album*> albumlist,
                    Phonon::MediaObject *musicobj,
                    QList<long> &tracknumlist,
                    SKG_Track *currtrack,
                    bool largetracknums);
    QList<long> GetTrackNumbers(){return TrackNumbers;}
    SKG_Track* GetCurrTrack(){return CurrTrack;}
    long GetCurrentTrackNumber(){return CurrTrackNumber;}

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmTrackList *ui;
    Phonon::MediaObject *MusicObject;
    Phonon::MediaObject *MetaDataObject;
    QList<long> TrackNumbers;
    QList<long> OriginalList;
    QList<SKG_Album*> Albums;
    //SKG_MusicLibrary *Library;
    SKG_Track *SelectedTrack();
    SKG_Track *CurrTrack;
    SKG_Track* TrackByNumber(long tracknum);
    long CurrTrackNumber;
    Phonon::MediaSource SavedSource;
    qint64 SavedTime;
    bool LargeTrackNumbers;

    void LoadListTracks();

private slots:
    void btnUp();
    void btnDown();
    void MoveTrackUpList();
    void MoveTrackDownList();
    void MoveToTop();
    void RemoveTrack();
    void ClearList();
    void Pause();
    void PlayNow();
    void MetaDataResolved();
    void Cancel();
    void SaveAndExit();
    void SelectedTrackChanged(int row);
    void ShuffleTracks();

};

#endif // FRMTRACKLIST_H
