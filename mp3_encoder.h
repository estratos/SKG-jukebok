#ifndef MP3_ENCODER_H
#define MP3_ENCODER_H

#include <QObject>
#include <QFileInfo>
#include <QFile>
#include <QByteArray>
#include "lame/lame_global_flags.h"
#include "lame/lame.h"

class MP3_Encoder : public QObject
{
    Q_OBJECT
public:
    MP3_Encoder(QObject *parent = 0);
    void EncodeMP3(QString infilename, QString outfilename);
    void SetTrackInfo(QString trackartist,QString tracktitle);

private:
    lame_global_flags *GF;
    QString Artist;
    QString Title;

signals:
    void UpdateProgress(int prog);
    void EncodeFinished();
    void EncodeError(QString ermsg);
};

#endif // MP3_ENCODER_H
