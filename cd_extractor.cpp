#include <unistd.h>
#include "cd_extractor.h"
//#include <QFile>
#include <QEventLoop>
const int CD_Framesize_Raw = 2352;

CD_Extractor::CD_Extractor(QObject *parent) :
    QObject(parent)
{
    Buffer.clear();
}
void CD_Extractor::Initialize()
{
    char ** ppsz_message;
    int x;

    SectorsRead = 0;
    SectorsTotal = 0;

    Drive = cdio_cddap_identify(NULL,1,ppsz_message);

    if (Drive != NULL)
    {
        if (0 == cdio_cddap_open(Drive))
        {
            //Paranoia = cdio_paranoia_init(Drive);
            x = cdio_cddap_tracks(Drive);
            DriveFound();
        }
    }
    else
        DriveNotFound();
}

long CD_Extractor::Progress()
{
    if ((SectorsRead == 0) || (SectorsTotal == 0))
        return 0;
    else
        return ((double)SectorsRead / (double)SectorsTotal) * 100;
}

void CD_Extractor::Extract(int tracknum)
{
    int size;
    char *buf;
    int16_t *readresult;
    long result;
    long x;
    long firstsector,lastsector;
    long i;
    QString fname;
    QByteArray arr;
    QEventLoop evloop;

    Paranoia = cdio_paranoia_init(Drive);
    firstsector = cdio_cddap_track_firstsector(Drive, tracknum);
    lastsector = cdio_cddap_track_lastsector(Drive, tracknum);
    size = (lastsector - firstsector) + 1;
    SectorsTotal = size;
    SectorsRead = 0;
    cdio_cddap_speed_set(Drive,32);
    paranoia_modeset(Paranoia, PARANOIA_MODE_FULL); //^PARANOIA_MODE_NEVERSKIP);
    paranoia_seek(Paranoia, firstsector, SEEK_SET);
    QFile file("Track" + QString::number(tracknum) + ".wav");
    file.open(QIODevice::WriteOnly);
    WriteWav(file.handle(),size * CD_Framesize_Raw);
    for (i = firstsector; i <= lastsector; i++)
    {
        try
        {
            //readresult = cdio_paranoia_read(Paranoia,NULL);
            readresult = cdio_paranoia_read_limited(Paranoia,NULL,3);
            SectorsRead++;
            buf = (char*)readresult;
            file.write(buf,CD_Framesize_Raw);
            UpdateProgress(Progress());
            evloop.processEvents();
        }
        catch(...)
        {
            break;
        }
    }
    fname = file.fileName();
    file.close();
    cdio_paranoia_free(Paranoia);

    ExtractFinished(fname);
}

void CD_Extractor::WriteWav(int f,long bytes)
{
  /* quick and dirty */

  write(f,"RIFF",4);               /*  0-3 */
  PutNum(bytes+44-8,f,0,4);        /*  4-7 */
  write(f,"WAVEfmt ",8);           /*  8-15 */
  PutNum(16,f,0,4);                /* 16-19 */
  PutNum(1,f,0,2);                 /* 20-21 */
  PutNum(2,f,0,2);                 /* 22-23 */
  PutNum(44100,f,0,4);             /* 24-27 */
  PutNum(44100*2*2,f,0,4);         /* 28-31 */
  PutNum(4,f,0,2);                 /* 32-33 */
  PutNum(16,f,0,2);                /* 34-35 */
  write(f,"data",4);               /* 36-39 */
  PutNum(bytes,f,0,4);             /* 40-43 */
}

void CD_Extractor::PutNum(long num,int f,int endianness,int bytes){
  int i;
  unsigned char c;

  if(!endianness)
    i=0;
  else
    i=bytes-1;
  while(bytes--){
    c=(num>>(i<<3))&0xff;
    if(write(f,&c,1)==-1){
      perror("Could not write to output.");
      return;
    }
    if(endianness)
      i--;
    else
      i++;
  }
}
