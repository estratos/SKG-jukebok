#ifndef FRMRIP_H
#define FRMRIP_H

#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QEventLoop>
#include <QListWidgetItem>
#include <QApplication>
#include "lib/skglib.h"
#include <FLAC++/encoder.h>
#include <FLAC++/metadata.h>
#include "SKG_Ripper/skg_ripper.h"

namespace Ui {
    class FrmRip;
}

class FrmRip : public QDialog {
    Q_OBJECT
public:
    FrmRip(QWidget *parent = 0);
    ~FrmRip();

    void Initialize(SKG_MusicLibrary *lib);
    int Display();
    void Clear();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FrmRip *ui;
    SKG_Ripper *Ripper;
    SKG_MusicLibrary *Library;
    QDir *AlbumDirectory;
    int TrackIndex;
    bool DiscFound;
    QString ExtractProgressString;
    QString EncodeProgressString;
    QStringList TrackNameList;
    QString EncodeFileName;
    int ExtractProgress;
    int EncodeProgress;
    SKG_Album *NewAlbum;
    SKG_Track *NewTrack;
    void DisplayDialog();
    void DisplayFreeDBInfo();
    QString ValidTrackName(QString trackname);

private slots:
    void Rip();
    void DriveFound();
    void DriveNotFound();
    void ShowProgress();
    void ExtractFinished(QString fname);
    void EncodeFinished();
    void UpdateExtractProgress(int prog);
    void UpdateEncodeProgress(int prog);

    void LookupMessage(QString msg);
    void LookupFinished();
    void LookupError(QString errmsg);
};

#endif // FRMRIP_H
