#include "mp3_encoder.h"
#include <QEventLoop>
#include <iostream>
//#include <istream>

MP3_Encoder::MP3_Encoder(QObject *parent) :
    QObject(parent)
{
    //
}


void MP3_Encoder::EncodeMP3(QString infilename, QString outfilename)
{
    QEventLoop evloop;
    //const int PCM_SIZE = 8192;
    const int PCM_SIZE = 4096;
    const int MP3_SIZE = 8192;

    const char *inpath;
    const char *outpath;

    GF= lame_init();
    int read,write;
    QFile infile(infilename);
    long infilesize = infile.size();
    long bytesread = 0;

    //    //lame_set_quality(GF,2);
    GF->quality = 2;
    //    //lame_set_VBR(GF,vbr_default);
    GF->VBR = vbr_default;
    //    //lame_set_VBR_q(GF,2);
    GF->VBR_q = 2;

    lame_init_params(GF);
    inpath = infilename.toAscii().constData();
    outpath = outfilename.toAscii().constData();
    int prog;

    FILE *pcm = fopen(inpath,"rb");
    //FILE *mp3 = fopen(outpath, "wb");
    QFile mp3(outpath);
    mp3.open(QIODevice::WriteOnly);

    short int pcm_buffer[PCM_SIZE*2];
    unsigned char mp3_buffer[MP3_SIZE];

    //id3tag_set_title(GF,Title.toAscii().data());
    //id3tag_set_artist(GF,Artist.toAscii().data());

    do
    {
        read = fread(pcm_buffer, 2*sizeof(short int), PCM_SIZE, pcm);
        bytesread += read;

        if (read == 0)
            write = lame_encode_flush(GF, mp3_buffer, MP3_SIZE);
        else
        {
            write = lame_encode_buffer_interleaved(GF, pcm_buffer, read, mp3_buffer, MP3_SIZE);
        }
        //fwrite(mp3_buffer, write, 1, mp3);
        //fwrite(mp3_buffer,sizeof(char),write,mp3);
        mp3.write((const char *)mp3_buffer,write);
        prog = (int)(100.0 * bytesread * 2*sizeof(short int) / infilesize);
        UpdateProgress(prog);
        //QApplication::processEvents();
        evloop.processEvents(QEventLoop::AllEvents);
    } while (read != 0);

    //lame_mp3_tags_fid(GF,mp3);
    //lame_mp3_tags_fid(GF,(FILE *)mp3);

    lame_close(GF);
    QFileInfo finfo(mp3);
    mp3.close();
    if(!mp3.exists())
    {
        EncodeMP3(infilename,outfilename);
        return;
    }
    if (finfo.suffix() != "mp3")
    {
        QString fname = finfo.fileName();
        mp3.rename(fname + ".mp3");
    }
    fclose(pcm);
    QFile::remove(infilename);
    //QApplication::processEvents();
    evloop.processEvents(QEventLoop::AllEvents);
    UpdateProgress(100);
    EncodeFinished();
}

void MP3_Encoder::SetTrackInfo(QString trackartist,QString tracktitle)
{
    Artist = trackartist;
    Title = tracktitle;
}
