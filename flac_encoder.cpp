#include "flac_encoder.h"
#include <QFile>
#include <QApplication>

Flac_Encoder::Flac_Encoder(QObject *parent) :
    QObject(parent)
{
    //
}

void Flac_Encoder::EncodeFlac(QString infilename, QString outfilename)
{
    const int READSIZE = 1024;

    FLAC::Encoder::File Encoder;
    unsigned total_samples = 0; /* can use a 32-bit number due to WAVE size limitations */
    FLAC__byte buffer[READSIZE/*samples*/ * 2/*bytes_per_sample*/ * 2/*channels*/]; /* we read the WAVE data into here */
    FLAC__int32 pcm[READSIZE/*samples*/ * 2/*channels*/];
    FLAC__int32 *pcm_[2] = { pcm, pcm+READSIZE };
    char *inpath;
    char *outpath;
    int read, write, tag;
    QFile infile(infilename);
    long infilesize = infile.size();
    long bytesread = 0;

    inpath = infilename.toAscii().data();
    outpath = outfilename.toAscii().data();
    int prog;

    FILE *wav = fopen(inpath,"rb");
    //FILE *flac = fopen(outpath, "wb");

    bool ok = true;
    FLAC__StreamEncoderInitStatus init_status;
    FLAC__StreamMetadata *metadata[2];
    FLAC__StreamMetadata_VorbisComment_Entry entry;
    unsigned sample_rate = 0;
    unsigned channels = 0;
    unsigned bps = 0;

    /* read wav header and validate it */
    if(fread(buffer, 1, 44, wav) != 44 ||
       memcmp(buffer, "RIFF", 4) ||
       memcmp(buffer+8, "WAVEfmt \020\000\000\000\001\000\002\000", 16) ||
       memcmp(buffer+32, "\004\000\020\000data", 8))
        {
            fclose(wav);
            return;
        }

    sample_rate = ((((((unsigned)buffer[27] << 8) | buffer[26]) << 8) | buffer[25]) << 8) | buffer[24];
    channels = 2;
    bps = 16;
    total_samples = (((((((unsigned)buffer[43] << 8) | buffer[42]) << 8) | buffer[41]) << 8) | buffer[40]) / 4;

    /* check the encoder */
    if(!Encoder)
    {
        fprintf(stderr, "ERROR: allocating encoder\n");
        fclose(wav);
        return;
    }

     ok &= Encoder.set_verify(true);
     ok &= Encoder.set_compression_level(5);
     ok &= Encoder.set_channels(channels);
     ok &= Encoder.set_bits_per_sample(bps);
     ok &= Encoder.set_sample_rate(sample_rate);
     ok &= Encoder.set_total_samples_estimate(total_samples);

     /* now add some metadata; we'll add some tags and a padding block */
    if(ok)
    {
        if((metadata[0] = FLAC__metadata_object_new(FLAC__METADATA_TYPE_VORBIS_COMMENT)) == NULL ||
           (metadata[1] = FLAC__metadata_object_new(FLAC__METADATA_TYPE_PADDING)) == NULL ||
           /* there are many tag (vorbiscomment) functions but these are convenient for this particular use: */
           !FLAC__metadata_object_vorbiscomment_entry_from_name_value_pair(&entry, "TITLE", TrackInfo.get(KCDDB::Title).toByteArray().data()) ||
           !FLAC__metadata_object_vorbiscomment_append_comment(metadata[0], entry, /*copy=*/false) || /* copy=false: let metadata object take control of entry's allocated string */
           !FLAC__metadata_object_vorbiscomment_entry_from_name_value_pair(&entry, "ARTIST", TrackInfo.get(KCDDB::Artist).toByteArray().data()) ||
           !FLAC__metadata_object_vorbiscomment_append_comment(metadata[0], entry, /*copy=*/false))
        {
            //fprintf(stderr, "ERROR: out of memory or tag error\n");
            ok = false;
        }
        metadata[1]->length = 1234; /* set the padding length */
        ok = Encoder.set_metadata(metadata, 2);
    }

     /* initialize encoder */
    if(ok)
    {
        //init_status = Encoder.init(flac);
        init_status = Encoder.init(outpath);
        if(init_status != FLAC__STREAM_ENCODER_INIT_STATUS_OK)
        {
            //fprintf(stderr, "ERROR: initializing encoder: %s\n", FLAC__StreamEncoderInitStatusString[init_status]);
            ok = false;
        }
     }

    /* read blocks of samples from WAVE file and feed to encoder */
    if(ok)
    {
        size_t left = (size_t)total_samples;
        while(ok && left)
        {
            size_t need = (left>READSIZE? (size_t)READSIZE : (size_t)left);
            long bytes = fread(buffer, channels*(bps/8), need, wav);
            if (bytes != need)
            {
                //fprintf(stderr, "ERROR: reading from WAVE file\n");
                ok = false;

            }
            else
            {
                bytesread += bytes * 4;
                prog = (int)(100.0 * bytesread / infilesize);
                UpdateProgress(prog);
                QApplication::processEvents();

                /* convert the packed little-endian 16-bit PCM samples from WAVE into an interleaved FLAC__int32 buffer for libFLAC */
                size_t i;
                for(i = 0; i < need*channels; i++)
                {
                    /* inefficient but simple and works on big- or little-endian machines */
                    pcm[i] = (FLAC__int32)(((FLAC__int16)(FLAC__int8)buffer[2*i+1] << 8) | (FLAC__int16)buffer[2*i]);
                }
                /* feed samples to encoder */
                ok = Encoder.process_interleaved(pcm, need);
            }
            left -= need;
        }
    }
    UpdateProgress(100);
    QApplication::processEvents();
    fclose(wav);
    QFile::remove(infilename);
    QFileInfo finfo(outpath);
//    QFile f(outpath);
//    if (!f.exists())
//    {
//        EncodeFlac(infilename,outfilename);
//        return;
//    }
    EncodeFinished(finfo);
}

void Flac_Encoder::SetTrackInfo(KCDDB::TrackInfo info)
{
    TrackInfo = info;
}
