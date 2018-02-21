#ifndef FRMCONFIG_H
#define FRMCONFIG_H

#include <QDialog>
#include "jukeboxconfig.h"
#include "customalbumlist.h"
#include "customlistmanager.h"
#include "playlist.h"
#include "playlistmanager.h"
#include "keytranslator.h"

namespace Ui {
    class frmConfig;
}

class frmConfig : public QDialog {
    Q_OBJECT
public:
    frmConfig(QWidget *parent = 0);
    ~frmConfig();
    void Initialize(JukeboxConfig *cfg,
                    CustomListManager *listmgr,
                    KeyTranslator *translator,
                    PlaylistManager *plistmgr,
                    CustomAlbumList *list= NULL);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmConfig *ui;
    QString ConfigFile;
    QString CustomListFile;
    JukeboxConfig *Config;
    CustomListManager *Manager;
    PlaylistManager *PManager;
    KeyTranslator *Translator;
    CustomAlbumList *LoadedList;
    QList <Playlist*> AvailablePlaylists();
    void DisplayCustomLists();
    void DisplayPlaylists();
    void DisplayMusicDirectories();
    void SaveConfigFile(){Config->SaveConfigFile();}
    void SaveListsFile(){Manager->SaveCustomListFile();}
    void LoadKeyComboBoxes();

private slots:
    void btnAddDirectoryClicked();
    void btnRemoveDirectoryClicked();
    void btnAddListClicked();
    void btnEditListCLicked();
    void btnDeleteListClicked();
    void btnAddPlaylistClicked();
    void btnEditPlaylistClicked();
    void btnDeletePlaylistClicked();
    void btnSaveClicked();
    void btnAddKeyClicked();
    void btnClearKeysClicked();
    void ViewCurrentKeyMappings();
};

#endif // FRMCONFIG_H
