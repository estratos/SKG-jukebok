#ifndef CD_EXTRACTOR_H
#define CD_EXTRACTOR_H


#include <QObject>
#include <QFile>
#include <cdio/cdio.h>
#include <cdio/cdda.h>
#include <cdio/paranoia.h>

class CD_Extractor : public QObject
{
Q_OBJECT

private:
    cdrom_drive_t *Drive;
    cdrom_paranoia_t *Paranoia;

    void WriteWav(int f,long bytes);
    void PutNum(long num,int f,int endianness,int bytes);
    long SectorsRead;
    long SectorsTotal;

public:
    explicit CD_Extractor(QObject *parent = 0);
    void Initialize();
    long Progress();
    void Extract(int tracknum);

    QByteArray Buffer;

signals:
    void DriveFound();
    void DriveNotFound();
    void ExtractFinished(QString fname);
    void UpdateProgress(int prog);
};

#endif // CD_EXTRACTOR_H
