#ifndef MAINNETBOOK_H
#define MAINNETBOOK_H

#include <QMainWindow>
#include <phonon>
#include "jukeboxconfig.h"
#include "customalbumlist.h"
#include "customlistmanager.h"
#include "playlist.h"
#include "playlistmanager.h"
#include "keytranslator.h"
#include "lib/skglib.h"

namespace Ui {
    class MainNetbook;
}

class MainNetbook : public QMainWindow {
    Q_OBJECT
public:
    MainNetbook(QWidget *parent = 0);
    ~MainNetbook();
    void SetConfig(JukeboxConfig *config);
    void LoadTrackList();

protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *keypress);
    void resizeEvent(QResizeEvent *event);

private:
    QString cDEFAULT_COVER_ART;
    Ui::MainNetbook *ui;
    JukeboxConfig *Config;
    SKG_MusicLibrary *Library;
    QList<SKG_Album *> Albums;
    QList<long> TrackNumbers;
    SKG_Track *currTrack;
    QString TrackString;
    long currTrackNumber;
    int PanelIndex;
    int MoveIncrement;
    QTimer *timerSlideLeft;
    QTimer *timerSlideRight;
    QTimer *RandomTrackTimer;
    SKG_Album *SelectedAlbum;
    CustomListManager *ListManager;
    CustomAlbumList *LoadedList;
    PlaylistManager *PListManager;
    SKG_Track *TrackByNumber(long tracknum);
    KeyTranslator *Translator;
    Playlist *CurrPlaylist;

    bool SlideFinished;
    bool LargeAlbumNumbers();

    //Phonon objects
    Phonon::AudioOutput *MusicOutput;
    Phonon::AudioOutput *EffectsOutput;
    Phonon::MediaObject *MusicObject;
    Phonon::MediaObject *EffectsObject;
    Phonon::MediaObject *MetaDataObject;
    Phonon::MediaSource CurrentSong;

    void DisplaySelectedAlbum();
    void DisplayCurrTrack();
    void DisplayTrackNumbers();

    void LoadCustomAlbumList(CustomAlbumList *list);
    void LoadPlaylist(Playlist *plist,bool random = false);
    void TranslateCustomKeystroke(QString Custom);

    void SaveTrackList();

private slots:
    void LetterButtonClicked(QString btnCaption);
    void ButtonClicked(QString btnCaption);
    void PrevButtonClicked();
    void NextButtonClicked();
    void DisplayConfigForm();
    void DisplayTrackListForm();
    void DisplayOptionsForm();
    void DisplayAlbumArtForm();
    void DisplayAlbumArtMultiForm();
    void DisplayLoadCustomListForm();
    void DisplayRipForm();
    void DisplayPlaylistForm();
    void DisplayHelpForm();
    void DisplayTrackSearchForm();
    void DisplayVolumeForm();
    void DisplayAboutForm();
    void AddCurrentTrackToPlaylist();
    void SlideNextPanelLeft();
    void SlideCurrentPanelRight();
    void Album1Clicked();
    void Album2Clicked();
    void DisplayNextPanel();
    void DisplayPreviousPanel();
    void AddSelectedTrack();
    void CancelSelectedTrack();
    void SelectedTrackChanged();
    void AlbumArtClicked();
    void ReloadConfig();
    void ClearTracks();
    void NextTrack();
    void AddTrackNumber(long tracknum);
    void PlayRandomTrack();
    void VolumeUp();
    void VolumeDown();
    void NextLetter();
    void PrevLetter();


    //slots for each of the numbered buttons
    void Btn_0Clicked();
    void Btn_1Clicked();
    void Btn_2Clicked();
    void Btn_3Clicked();
    void Btn_4Clicked();
    void Btn_5Clicked();
    void Btn_6Clicked();
    void Btn_7Clicked();
    void Btn_8Clicked();
    void Btn_9Clicked();

    //Phonon slots
    void QueueNextTrack();
    void tick(qint64 time);
};

#endif // MAINNETBOOK_H
