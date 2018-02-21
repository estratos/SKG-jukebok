#ifndef FRMCDRIP_H
#define FRMCDRIP_H

#include <QDialog>
#include <QDialog>
#include <QTimer>
#include <QDir>
#include <QFileInfo>
#include <cdio/cdio.h>
#include <cdio/cdda.h>
#include "lib/skglib.h"
#include "freedblookup.h"
//#include "cd_extractor.h"
//#include "mp3_encoder.h"
//#include "ogg_encoder.h"
//#include "flac_encoder.h"


namespace Ui {
    class frmCDRip;
}

class frmCDRip : public QDialog
{
    Q_OBJECT

public:
    explicit frmCDRip(QWidget *parent = 0);
    ~frmCDRip();

    void Initialize(SKG_MusicLibrary *lib);
        int Display();
        void Clear();

protected:
        void changeEvent(QEvent *e);

private:
        Ui::frmCDRip *ui;
        CdIo_t *Drive;
        SKG_MusicLibrary *Library;
        FreeDBLookup *Lookup;
        QDir *AlbumDirectory;
        int TrackIndex;
        QString ExtractProgressString;
        QString EncodeProgressString;
        QStringList TrackNameList;
        int ExtractProgress;
        int EncodeProgress;
        SKG_Album *NewAlbum;
        SKG_Track *NewTrack;
        void DisplayDialog();
        void DiscFinished();

        QTimer *Timer;

        //CD_Extractor *Extractor;
        //MP3_Encoder *Encoder;
        //Ogg_Encoder *OggEncoder;
        //Flac_Encoder *FlacEncoder;

    private slots:
        void DisplayFreeDBInfo();
        void LookupDisc();
        void Rip();
        void DriveFound();
        void DriveNotFound();
        void ShowProgress();
        void ExtractFinished(QString fname);
        void EncodeFinished(QFileInfo finfo);
        void UpdateExtractProgress(int prog);
        void UpdateEncodeProgress(int prog);

        void LookupMessage(QString msg);
        void LookupFinished();
        void LookupError(QString errmsg);
};

#endif // FRMCDRIP_H
