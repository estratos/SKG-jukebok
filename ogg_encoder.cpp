#include "ogg_encoder.h"
#include <time.h>
#include <stdlib.h>
#include <QFile>
#include <QApplication>

Ogg_Encoder::Ogg_Encoder(QObject *parent) :
    QObject(parent)
{
}

void Ogg_Encoder::EncodeOgg(QString infilename,QString outfilename)
{
    const int READSIZE = 1024;

    signed char readbuffer[READSIZE*4+44];
    char *inpath;
    char *outpath;
    QFile infile(infilename);
    long infilesize = infile.size();
    long bytesread = 0;

    ogg_stream_state os; /* take physical pages, weld into a logical stream of packets */
    ogg_page         og; /* one Ogg bitstream page.  Vorbis packets are inside */
    ogg_packet       op; /* one raw packet of data for decode */
    vorbis_info      vi; /* struct that stores all the static vorbis bitstream settings */
    vorbis_comment   vc; /* struct that stores all the user comments */
    vorbis_dsp_state vd; /* central working state for the packet->PCM decoder */
    vorbis_block     vb; /* local working space for packet->PCM decode */
    int eos=0,ret;
    int i, founddata;

    inpath = infilename.toAscii().data();
    outpath = outfilename.toAscii().data();
    int prog;

    FILE *pcm = fopen(inpath,"rb");
    //FILE *ogg = fopen(outpath, "wb");
    QFile ogg(outpath);
    ogg.open(QIODevice::WriteOnly);

    //Wave header
    readbuffer[0] = '\0';
    for (i=0, founddata=0; i<30 && ! feof(pcm) && ! ferror(pcm); i++)
    {
      fread(readbuffer,1,2,pcm);
      if ( ! strncmp((char*)readbuffer, "da", 2) )
      {
        founddata = 1;
        fread(readbuffer,1,6,pcm);
        break;
      }
    }

    vorbis_info_init(&vi);
    ret = vorbis_encode_init_vbr(&vi,2,44100,0.8);
    if(ret)
        return;

    vorbis_comment_init(&vc);
    vorbis_comment_add_tag(&vc,"Title",TrackInfo.get(KCDDB::Title).toByteArray().data());
    vorbis_comment_add_tag(&vc,"Artist",TrackInfo.get(KCDDB::Artist).toByteArray().data());

    vorbis_analysis_init(&vd,&vi);
    vorbis_block_init(&vd,&vb);

    srand(time(NULL));
    ogg_stream_init(&os,rand());


    ogg_packet header;
    ogg_packet header_comm;
    ogg_packet header_code;
    vorbis_analysis_headerout(&vd,&vc,&header,&header_comm,&header_code);
    ogg_stream_packetin(&os,&header); /* automatically placed in its own
                                         page */
    ogg_stream_packetin(&os,&header_comm);
    ogg_stream_packetin(&os,&header_code);

    while(!eos)
    {
      int result=ogg_stream_flush(&os,&og);
      if(result==0)
          break;
      //fwrite(og.header,1,og.header_len,ogg);
      //fwrite(og.body,1,og.body_len,ogg);
      ogg.write((const char*)og.header,og.header_len);
      ogg.write((const char*)og.body,og.body_len);
    }

    while(!eos)
    {
      long i;
      long bytes=fread(readbuffer,1,READSIZE*4,pcm); /* stereo hardwired here */
      bytesread += bytes;
      prog = (int)(100.0 * bytesread / infilesize);
      UpdateProgress(prog);
      QApplication::processEvents();

      if(bytes==0)
      {
        vorbis_analysis_wrote(&vd,0);
      }
      else
      {
        float **buffer=vorbis_analysis_buffer(&vd,READSIZE);

        for(i=0;i<bytes/4;i++)
        {
          buffer[0][i]=((readbuffer[i*4+1]<<8)|(0x00ff&(int)readbuffer[i*4]))/32768.f;
          buffer[1][i]=((readbuffer[i*4+3]<<8)|(0x00ff&(int)readbuffer[i*4+2]))/32768.f;
        }

        vorbis_analysis_wrote(&vd,i);
      }

      while(vorbis_analysis_blockout(&vd,&vb)==1)
      {
        vorbis_analysis(&vb,NULL);
        vorbis_bitrate_addblock(&vb);

        while(vorbis_bitrate_flushpacket(&vd,&op))
        {
          ogg_stream_packetin(&os,&op);
          while(!eos)
          {
            int result=ogg_stream_pageout(&os,&og);
            if(result==0)
                break;

            //fwrite(og.header,1,og.header_len,ogg);
            //fwrite(og.body,1,og.body_len,ogg);
            ogg.write((const char*)og.header,og.header_len);
            ogg.write((const char*)og.body,og.body_len);

              if(ogg_page_eos(&og))
                  eos=1;
          }
        }
      }
  }
  ogg_stream_clear(&os);
  vorbis_block_clear(&vb);
  vorbis_dsp_clear(&vd);
  vorbis_comment_clear(&vc);
  vorbis_info_clear(&vi);
  fclose(pcm);
  //fclose(ogg);
  QFileInfo finfo(ogg);
  ogg.rename(outfilename);
  ogg.close();
  if(!ogg.exists())
  {
      EncodeOgg(infilename,outfilename);
      return;
  }
  QApplication::processEvents();
  UpdateProgress(100);
  QFile::remove(infilename);
  EncodeFinished(finfo);
  //infile.remove();

}

void Ogg_Encoder::SetTrackInfo(KCDDB::TrackInfo info)
{
    TrackInfo = info;
}
