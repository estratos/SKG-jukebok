#ifndef FRMOPTIONS_H
#define FRMOPTIONS_H

#include <QDialog>

enum OptionType {OptionNone,
                 OptionConfig,
                 OptionRipper,
                 OptionAlbumArt,
                 OptionCustomLists,
                 OptionPlaylist,
                 OptionHelp,
                 OptionTrackSearch,
                 OptionAddToPlaylist,
                 OptionMinimize,
                 OptionAbout,
                 OptionRescan,
                 OptionExit};

namespace Ui {
    class frmOptions;
}

class frmOptions : public QDialog {
    Q_OBJECT
public:
    frmOptions(QWidget *parent = 0);
    ~frmOptions();

    OptionType Option;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmOptions *ui;

private slots:
    void btnConfigPressed();
    void btnRipPressed();
    void btnArtPressed();
    void btnCustomListsPressed();
    void btnPlaylistPressed();
    void btnHelpPressed();
    void btnTrackSearchPressed();
    void btnAddToPlaylistPressed();
    void btnMinimizePressed();
    void btnAboutPressed();
    void btnRescanPressed();
    void btnExitPressed();
};

#endif // FRMOPTIONS_H
