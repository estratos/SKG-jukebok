#include "skglib.h"

#include <QFileInfoList>
#include <QMessageBox>
#include <exception>

SKG_Track::SKG_Track(int tracknum,QFileInfo * trackfileinfo)
{
    TrackNumber=tracknum;
    TrackFile=trackfileinfo;
    Available = true;
}

// Returns the file name of the music file, without the qualifying path. 00 All Tracks
// allows the app to queue the entire album at once.
QString SKG_Track::GetTrackName()
{
    if (TrackNumber==0)
        return "00 = All Tracks";
    else
    {
        QString first2;
        int num;
        bool isnumeric;

        first2 = TrackFile->baseName().trimmed().left(2);
        num = first2.toInt(&isnumeric);
        if ((num != TrackNumber) || (!isnumeric))
        {
            return QString("%1").arg(QString::number(TrackNumber),2,QChar('0')) + " - " +
                TrackFile->completeBaseName();
        }
        else
        {
            return TrackFile->completeBaseName();
        }

    }
}

QString SKG_Track::GetTrackNameSansNumber()
{
    return GetTrackName().mid(5).trimmed();
}

// Constructor for Album class. Creates an album object from a referenct to the directory
// where the album is stored.
SKG_Album::SKG_Album(QDir *albumdir)
{
    int i;
    SKG_Track *currtrack;
    QFileInfoList trackfiles;
    QFileInfoList picfiles;
    QStringList namefilters;
    QFileInfo *trackinfo;
    bool found;

    Available = true;
    AlbumDirectory=albumdir;

    //Look only for files in supported formats, currently mp3, ogg and wav
    namefilters<<"*.mp3"<<"*.ogg"<<"*.wav"<<"*.flac";
    albumdir->setNameFilters(namefilters);
    trackfiles=albumdir->entryInfoList();

    // Create a track 0 in the list, referencing no actual music fil. This will be used to
    // queue all the tracks in an album at once.
    currtrack=new SKG_Track(0,NULL);
    Tracks.append(currtrack);

    // Find all supported music files in the directory, create track objects for them, and
    // add them to the album object.
    i=1;
    for(i=0;i<trackfiles.size();i++)
    {
        trackinfo=new QFileInfo(trackfiles.at(i));
        currtrack=new SKG_Track(i+1,trackinfo);
        Tracks.append(currtrack);
    }

    // Create a new list for picture art files.
    namefilters.clear();
    namefilters<<"*.jpg"<<".jpeg"<<"*.bmp"<<"*.gif"<<"*.tiff"<<"*.png";
    albumdir->setNameFilters(namefilters);
    picfiles=albumdir->entryInfoList();
    // Look for a file called "cover". If we don't find one, use the first picture file we find
    found = false;
    if (picfiles.count() > 0)
    {
        for (i = 0;i < picfiles.count();i++)
        {
            if (picfiles.at(i).baseName().toUpper() == "COVER")
            {
                CoverArt = picfiles.at(i).filePath();
                found = true;
            }
        }
        if (!found)
            CoverArt=picfiles.at(0).filePath();
    }
}

SKG_Album::~SKG_Album()
{
    foreach(SKG_Track *track,Tracks)
        delete track;
}

SKG_Album::SKG_Album(QString albumname, int albumnum, QString coverart)
{
    SKG_Track *zerotrack;

    AlbumDirectory = new QDir(albumname);
    if (!AlbumDirectory->exists())
    {
        throw(new SKG_LoadException("Album " + albumname + " does not exist."));
    }
    AlbumNumber = albumnum;

    CoverArt = coverart;
    Available = true;
    // Create a track 0 in the list, referencing no actual music fil. This will be used to
    // queue all the tracks in an album at once.
    zerotrack=new SKG_Track(0,NULL);
    Tracks.append(zerotrack);
}

// Returns the name of the Artist, which it assumes is the name of the parent directory,
// without the qualifying path
QString SKG_Album::GetArtistName()
{
    QDir *artistdir;
    artistdir=new QDir(AlbumDirectory->absolutePath());
    artistdir->cdUp();
    if (artistdir->dirName().left(4).toLower() == "the ")
    {
        return artistdir->dirName().mid(4);
    }
    else
    {
        return artistdir->dirName();
    }
}

QString SKG_Album::GetAlbumPath()
{
    return AlbumDirectory->absolutePath();
}

QString SKG_Album::GetDirectoryName()
{
    return AlbumDirectory->absolutePath();
}

SKG_Track* SKG_Album::GetTrackByName(QString trackname)
{
    for (int i = 0;i < Tracks.count();i++)
    {
        if (Tracks.at(i)->GetTrackName() == trackname)
        {
            return Tracks.at(i);
        }
    }
    return NULL;
}

// Creates an Artist object from a reference to the directory
SKG_Artist::SKG_Artist(QDir *artistdir)
{
    int i;
    QFileInfo albuminfo;
    QFileInfoList albumlist;
    QDir *tmpdir;
    SKG_Album *newalbum;
    ArtistName=artistdir->dirName();
    if (ArtistName.left(4).toLower() == "the ")
        ArtistName = ArtistName.mid(4);
    DirectoryName = artistdir->absolutePath();

    Available = true;
    // Create a new list, consisting of only subdirectories, which will be used to create
    // the album object.
    albumlist=artistdir->entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot,QDir::Name);
    // Create a new directory object for each subdirectory and add it to the directory list
    for(i=0;i<albumlist.count();i++)
    {
        albuminfo=albumlist.at(i);
        tmpdir=new QDir(albuminfo.filePath());
        AlbumDirectories.append(tmpdir);
    }

    // Use the list of directory objects to create the album objects and append them to
    // the album list.
    foreach(QDir *currdir, AlbumDirectories)
    {
        newalbum=new SKG_Album(currdir);
        Albums.append(newalbum);
    }
}

SKG_Artist::SKG_Artist(QString artistname)
{
    QDir tmpdir = QDir(artistname);
    if (!tmpdir.exists())
    {
        throw(new SKG_LoadException("Artist directory" + artistname + " does not exist."));
    }
    ArtistName = tmpdir.dirName();
    if (ArtistName.left(4).toLower() == "the ")
        ArtistName = ArtistName.mid(4);
    DirectoryName = tmpdir.absolutePath();
    Available = true;
}

SKG_Artist::~SKG_Artist()
{
    foreach(SKG_Album *album,Albums)
        delete album;
}

// Checks to see if an album with a specified name already exists for this artist.
bool SKG_Artist::AlbumExists(QString albumname)
{
    foreach(SKG_Album *curralbum,Albums)
    {
        if (curralbum->GetAlbumName()==albumname)
            return true;
    }
    return false;
}

void SKG_Artist::SortAlbums()
{
    int i;
    bool swapped;

    do
    {
        swapped = false;
        for (i = 0;i < Albums.count() - 1;i++)
        {
           if (Albums.at(i)->GetAlbumName() > Albums.at(i + 1)->GetAlbumName())
            {
               Albums.swap(i,i + 1);
               swapped = true;
           }
        }
    }
    while (swapped);
}

// Default constructor for the library object doesn't do anything. Action occurs when you
// start adding directories.
SKG_MusicLibrary::SKG_MusicLibrary()
{
    //
}

SKG_MusicLibrary::~SKG_MusicLibrary()
{
    Clear();
}

// Adds a top level music directory to the library, then creates the Artist objects from the
// subdirectories. Creating the Artist object creates the album objects, which in turn creates
// the track objects.
void SKG_MusicLibrary::AddDirectory(QDir *newdir)
{
    int i,j;
    QFileInfoList artistlist;
    QFileInfoList albumlist;
    QFileInfo artistinfo;
    QFileInfo albuminfo;
    QDir *tmpartistdir;
    QDir *tmpalbumdir;
    SKG_Artist *newartist;
    SKG_Album *newalbum;
    DirectoryNames.append(newdir->absolutePath());
    artistlist=newdir->entryInfoList((QDir::Dirs | QDir::NoDotAndDotDot),QDir::Name);

    for(i=0;i<artistlist.count();i++)
    {
        artistinfo=artistlist.at(i);
        tmpartistdir=new QDir(artistinfo.absoluteFilePath());
        newartist=new SKG_Artist(tmpartistdir);
        if (!ArtistExists(newartist->GetArtistName()))
        {
           Artists.append(newartist);
        }
        else
        {
            albumlist=tmpartistdir->entryInfoList((QDir::Dirs | QDir::NoDotAndDotDot),QDir::Name);
            for (j=0;i<albumlist.count();i++)
            {
                albuminfo=albumlist.at(i);
                if (!newartist->AlbumExists(albuminfo.fileName()))
                {
                    tmpalbumdir=new QDir(albuminfo.filePath());
                    newalbum=new SKG_Album(tmpalbumdir);
                    newartist->AddAlbum(newalbum);
                }
            }

        }
    }
    SortArtists();
}

SKG_Artist* SKG_MusicLibrary::GetArtistByName(QString artistname)
{
    int i;
    SKG_Artist *currartist;
    //GetArtistByName()=NULL;

    for(i=0;i<Artists.count();i++)
    {
        currartist=Artists.at(i);
        if (currartist->GetArtistName()==artistname)
        {
           // GetArtistByName()=currartist;
            return currartist;
        }
    }
    return NULL;
}

QList <SKG_Album *> SKG_MusicLibrary::GetAlbums()
{
    int i,j;
    int albumnumber;
    QList <SKG_Album *> tmplist;
    SKG_Artist *currartist;
    SKG_Album *curralbum;

    albumnumber=1;
    for(i=0;i<Artists.count();i++)
    {
        currartist=Artists.at(i);
        for(j=0;j<currartist->GetAlbums().count();j++)
        {
            curralbum=currartist->GetAlbums().at(j);
            curralbum->SetAlbumNumber(albumnumber++);
            tmplist.append(curralbum);
        }
    }
    return tmplist;
}

bool SKG_MusicLibrary::ArtistExists(QString artistname)
{
    int i;
    SKG_Artist *currartist;
    for(i=0;i<Artists.count();i++)
    {
       currartist=Artists.at(i);
       if (currartist->GetArtistName()==artistname)
       {
           return true;
       }
    }
    return false;
}

SKG_Album* SKG_MusicLibrary::GetAlbumByNumber(int albumnum)
{
    int i;
    SKG_Album *curralbum;
    QList<SKG_Album *> albumlist;

    albumlist=GetAlbums();
    for(i=0;i<albumlist.count();i++)
    {
        curralbum=albumlist.at(i);
        if (curralbum->GetAlbumNumber()==albumnum)
            return curralbum;
    }
    return NULL;
}

SKG_Track* SKG_MusicLibrary::GetTrackByNumber(long tracknum)
{
    int albumnumber;
    int tracknumber;

    albumnumber = tracknum / 100;
    tracknumber = tracknum % 100;
    try
    {
        return GetAlbumByNumber(albumnumber)->GetTracks().at(tracknumber);
    }
    catch(...)
    {
        return NULL;
    }
}

SKG_Album* SKG_MusicLibrary::GetAlbumByName(QString artistname,QString albumname)
{
    int i;
    SKG_Album *curralbum;

    for (i = 0; i < GetAlbums().count(); i++)
    {
        curralbum = GetAlbums().at(i);
        if ((curralbum->GetArtistName() == artistname) &&
            (curralbum->GetAlbumName() == albumname))
        {
            return curralbum;
            break;
        }
    }
    return NULL;
}

void SKG_MusicLibrary::SortArtists()
{
    int i;
    bool swapped;

    do
    {
        swapped = false;
        for (i = 0;i < Artists.count() - 1;i++)
        {
           if (Artists.at(i)->GetArtistName() > Artists.at(i + 1)->GetArtistName())
            {
               Artists.swap(i,i + 1);
               swapped = true;
           }
        }
    }
    while (swapped);
}

void SKG_MusicLibrary::SaveToFile(QString fname)
{
    QDomDocument doc;
    QMessageBox box(QMessageBox::NoIcon,"","",QMessageBox::Ok);
    QFile tracefile("C:/SKG_Jukebox/resources/Trace.txt");
    tracefile.open(QIODevice::WriteOnly);
    QString dbgstr;

    if(QFile::exists(fname))
        QFile::remove(fname);

    QFile libfile(fname);
    libfile.open(QIODevice::WriteOnly);

    QDomElement mainelement = doc.createElement("Library");
    foreach (QString dirname, this->GetDirectoryNames())
    {
        dbgstr = "Adding directory " + dirname + "\n";
        tracefile.write(dbgstr.toAscii());
        QDomElement dirnameelement = doc.createElement("DirectoryName");
        dirnameelement.setAttribute("Name",dirname);
        mainelement.appendChild(dirnameelement);
    }

    try
    {
        foreach(SKG_Artist *currartist, this->GetArtists())
        {
            if (currartist == NULL)
                continue;

            dbgstr = "Adding Artist " + currartist->GetArtistName() + "\n";
            tracefile.write(dbgstr.toAscii());
            QDomElement artistelement = doc.createElement("Artist");
            artistelement.setAttribute("ArtistName",currartist->GetArtistName());
            artistelement.setAttribute("DirectoryName",currartist->GetDirectoryName());
            foreach(SKG_Album *curralbum,currartist->GetAlbums())
            {
                if (curralbum == NULL)
                    continue;
                dbgstr = "Adding Album " + curralbum->GetAlbumName() + "\n";
                tracefile.write(dbgstr.toAscii());
                QDomElement albumelement = doc.createElement("Album");
                albumelement.setAttribute("AlbumNumber",curralbum->GetAlbumNumber());
                albumelement.setAttribute("AlbumDirectory",curralbum->GetDirectoryName());
                albumelement.setAttribute("CoverArt",curralbum->GetCoverArt());
                foreach(SKG_Track *currtrack,curralbum->GetTracks())
                {
                    if (currtrack == NULL)
                        continue;
                    if (currtrack->GetTrackNumber() == 0)
                        continue;
                    dbgstr = "Adding Track " + currtrack->GetTrackName() + "\n";
                    tracefile.write(dbgstr.toAscii());
                    QDomElement trackelement = doc.createElement("Track");
                    trackelement.setAttribute("TrackNumber",(uint)currtrack->GetTrackNumber());
                    trackelement.setAttribute("TrackFile",currtrack->GetFileName());
                    albumelement.appendChild(trackelement);
                }
                artistelement.appendChild(albumelement);
            }
            mainelement.appendChild(artistelement);
        }
    }
    catch(...)
    {
        box.setText("Exception: " );
        box.exec();
    }

    doc.appendChild(mainelement);
    libfile.write(doc.toByteArray());
    libfile.close();
    tracefile.close();
}

void SKG_MusicLibrary::LoadFromFile(QString fname)
{
    QDomDocument doc;
    QDomNodeList dirnamenodes;
    QDomNodeList artistnodes;
    QDomNodeList albumnodes;
    QDomNodeList tracknodes;
    QDomElement dirnameelement;
    QDomElement artistelement;
    QDomElement albumelement;
    QDomElement trackelement;
    QDomAttr artistdirattr;
    QDomAttr albumdirattr;
    QDomAttr albumnumattr;
    QDomAttr coverartattr;
    QDomAttr trackfileattr;
    QDomAttr tracknumattr;
    QString artistdir;
    QString albumdir;
    int albumnum;
    QString coverart;
    QString trackfile;
    int tracknum;
    QFileInfo *trackinfo;
    int i,j,k;
    bool x;
    QString errmsg;
    int errline;
    SKG_Artist *currartist;
    SKG_Album *curralbum;
    SKG_Track * currtrack;

    if (!QFile::exists(fname))
        return;

    DirectoryNames.clear();
    Artists.clear();
    QFile libfile(fname);
    libfile.open(QIODevice::ReadOnly);
    x = doc.setContent(libfile.readAll(),&errmsg,&errline);

    dirnamenodes = doc.elementsByTagName("DirectoryName");
    for (i = 0;i < dirnamenodes.count();i++)
    {
        dirnameelement = dirnamenodes.at(i).toElement();
        DirectoryNames.append(dirnameelement.attributeNode("Name").value());
    }

    artistnodes = doc.elementsByTagName("Artist");
    for (i = 0;i < artistnodes.count();i++)
    {
        artistelement = artistnodes.at(i).toElement();
        artistdirattr = artistelement.attributeNode("DirectoryName");
        artistdir = artistdirattr.value();
        currartist = new SKG_Artist(artistdir);
        albumnodes = artistelement.elementsByTagName("Album");
        for (j = 0;j < albumnodes.count();j++)
        {
            albumelement = albumnodes.at(j).toElement();
            albumdirattr = albumelement.attributeNode("AlbumDirectory");
            albumdir = albumdirattr.value();
            albumnumattr = albumelement.attributeNode("AlbumNumber");
            albumnum = albumnumattr.value().toInt();
            coverartattr = albumelement.attributeNode("CoverArt");
            coverart = coverartattr.value();
            curralbum = new SKG_Album(albumdir,albumnum,coverart);
            tracknodes = albumelement.elementsByTagName("Track");
            for (k = 0;k < tracknodes.count();k++)
            {
                trackelement = tracknodes.at(k).toElement();
                trackfileattr = trackelement.attributeNode("TrackFile");
                trackfile = trackfileattr.value();
                tracknumattr = trackelement.attributeNode("TrackNumber");
                tracknum = tracknumattr.value().toInt();
                trackinfo = new QFileInfo(trackfile);
                if (!trackinfo->exists())
                    throw (new SKG_LoadException("Track " + trackfile + " does not exist"));
                currtrack = new SKG_Track(tracknum,trackinfo);
                curralbum->AddTrack(currtrack);
            }
            currartist->AddAlbum(curralbum);
        }
        AddArtist(currartist);
    }
    libfile.close();
}

void SKG_MusicLibrary::Clear()
{
    foreach(SKG_Artist *artist, Artists)
        delete artist;
    Artists.clear();
    Albums.clear();
}

QStringList SKG_MusicLibrary::ArtistNames()
{
    QStringList list;
    list.clear();
    foreach (SKG_Artist *artist,Artists)
        list.append(artist->GetArtistName());

    return list;
}

SKG_Artist* SKG_MusicLibrary::ArtistStartsWith(QString str)
{
    SKG_Artist *artist = NULL;
    foreach(SKG_Artist *currartist,Artists)
    {
        if (currartist->GetArtistName().startsWith(str))
        {
            artist = currartist;
            break;
        }
    }
    return artist;
}
