#ifndef JUKEBOXCONFIG_H
#define JUKEBOXCONFIG_H

#include <QStringList>
#include "frmsplash.h"

enum JukeboxOperatingMode{modeNone,modeNetbook,modeNormal};
enum JukeboxConfigErrorType {configErrorTypeNone,
                             configErrorTypeFileOpen,
                             configErrorTypeInvalidMode,
                             configErrorTypeMusicLibrary,
                             configErrorTypeAlbumArt};
enum JukeboxCollectionSize{sizeSmall,sizeLarge};

QString ConfigFile();
QString TrackListFile();
QString LibraryFile();
QString ResourcesDirectory();
QString UpArrow();
QString DownArrow();
QString LeftArrow();
QString RightArrow();

class JukeboxConfig
{
public:
    JukeboxConfig();
    JukeboxOperatingMode GetOperatingMode(){return OperatingMode;}
    JukeboxConfigErrorType GetErrorType(){return errorType;}
    JukeboxCollectionSize GetCollectionSize(){return CollectionSize;}
    QStringList GetMusicDirectories(){return MusicDirectories;}
    QString GetCustomListName(){return CustomListName;}
    void AddDirectory(QString dirname){MusicDirectories.append(dirname);}
    void DeleteDirectory(QString dirname);
    void SetOperatingMode(JukeboxOperatingMode mode){OperatingMode = mode;}
    void SetCustomListName(QString listname){CustomListName = listname;}
    void SaveConfigFile();
    void KillSplashForm();
    bool PlaySlidingSound(){return SlidingSound;}
    void SetSlidingSound(bool value){SlidingSound = value;}
    bool PlayAnimation(){return AnimationEnabled;}
    void SetAnimationEnabled(bool value){AnimationEnabled = value;}
    bool IsConnected(){return Connected;}
    void SetConnected(bool connected){Connected = connected;}
    bool PlayRandomTrack(){return RandomTrackEnabled;}
    void SetRandomTrackEnabled(bool value){RandomTrackEnabled = value;}
    void SetCollectionSize(JukeboxCollectionSize size){CollectionSize = size;}


private:
    JukeboxOperatingMode OperatingMode;
    JukeboxConfigErrorType errorType;
    JukeboxCollectionSize CollectionSize;
    QStringList MusicDirectories;
    QString CustomListName;
    bool Connected;
    bool SlidingSound;
    bool AnimationEnabled;
    bool RandomTrackEnabled;
    void LoadConfigFile();
    frmSplash *SplashForm;
};

#endif // JUKEBOXCONFIG_H
