#ifndef FLAC_ENCODER_H
#define FLAC_ENCODER_H

#include <QObject>
#include <QFileInfo>
#include "libkcddb/cdinfo.h"
#include <FLAC++/encoder.h>
#include <FLAC++/metadata.h>


class Flac_Encoder : public QObject
{
Q_OBJECT
public:
    explicit Flac_Encoder(QObject *parent = 0);
    void EncodeFlac(QString infilename, QString outfilename);
    void SetTrackInfo(KCDDB::TrackInfo info);

private:
    KCDDB::TrackInfo TrackInfo;

signals:
    void UpdateProgress(int prog);
    void EncodeFinished(QFileInfo finfo);

};

#endif // FLAC_ENCODER_H
