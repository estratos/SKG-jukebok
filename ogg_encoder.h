#ifndef OGG_ENCODER_H
#define OGG_ENCODER_H

#include <QObject>
#include <QFileInfo>
#include <vorbis/vorbisenc.h>
#include <libkcddb/cdinfo.h>

class Ogg_Encoder : public QObject
{
Q_OBJECT
public:
    explicit Ogg_Encoder(QObject *parent = 0);
    void EncodeOgg(QString infilename, QString outfilename);
    void SetTrackInfo(KCDDB::TrackInfo info);

private:
    KCDDB::TrackInfo TrackInfo;

signals:
    void UpdateProgress(int prog);
    void EncodeFinished(QFileInfo finfo);

};

#endif // OGG_ENCODER_H
