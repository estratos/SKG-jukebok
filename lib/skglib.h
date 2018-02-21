#ifndef SKGLIB_H
#define SKGLIB_H

#include <QDir>
#include <QList>
#include <QString>
#include <QDomDocument>
#include <QDomAttr>
#include <QDomElement>

// The skglib header and cpp files contain classes for organizing, displaying, and looking up
// music files on he user's computer. It asumes music is organized in one or more music
// directories, with the artist subdirectories. Each artist subdirectory will contain one or
// more album subdirectories, which will contain the tracks in mp3, ogg, or flac formats.

#include <QFileInfo>
#include <QStringList>
#include <QPicture>

class SKG_LoadException{
    private:
        QString message;

    public:
        SKG_LoadException(QString msg){message = msg;}
};


// Track base class. Contains a number identifying the track in the album, and a file info
// object describing the exact music file.
class SKG_Track {
    private :
        long TrackNumber;
        QFileInfo *TrackFile;
        bool Available;

    public :
        SKG_Track(int tracknum, QFileInfo * trackfileinfo);
        QString GetTrackName();  // File name without path
        QString GetFileName(){return TrackFile->absoluteFilePath();}   // Full path/file name
        QString GetTrackNameSansNumber();
        long GetTrackNumber(){return TrackNumber;}  // 2 digit number identifying track position in album.
        bool IsAvailable(){return Available;}
        void SetAvaialble(bool value){Available = value;}
    };

// Album class containing a list of tracks and other identifying information, such as a
// 3 digit identifying number and a string representing the cover art file
class SKG_Album {
    private :
        int AlbumNumber;
        QDir *AlbumDirectory;  // Reference to the actual directory on the hard drive for this album
        QString CoverArt;      // Contains the file name of the picture file containing the album art
        QList <SKG_Track *> Tracks;
        bool Available;  //Used by add/edit custom list screen

    public :
        SKG_Album(QString albumname,int albumnum,QString coverart);
        SKG_Album(QDir *albumdir);
        ~SKG_Album();
        QString GetAlbumName(){return AlbumDirectory->dirName();}  // Returns the album name, same as the directory name
        QString GetCoverArt(){return CoverArt;}
        QList <SKG_Track *> GetTracks(){return Tracks;}
        void SetAlbumNumber(int albumnum){AlbumNumber = albumnum;}
        void SetCoverArt(QString coverartfile){CoverArt = coverartfile;}
        QString GetArtistName();
        int GetAlbumNumber(){return AlbumNumber;}
        QString GetAlbumPath();
        bool IsAvailable(){return Available;}
        void SetAvaialble(bool value){Available = value;}
        QString GetDirectoryName();
        void AddTrack(SKG_Track *track){Tracks.append(track);}
        SKG_Track* GetTrackByName(QString trackname);
    };

// Artist object, consists of a collection of albums and a string for the artist name
class SKG_Artist {
    private :
        QList <QDir *> AlbumDirectories;
        QList <SKG_Album *> Albums;
        QString ArtistName;
        bool Available;  // Used by add/edit custom list form
        QString DirectoryName;

   public :
       SKG_Artist(QString artistname);
       SKG_Artist(QDir *artistdir);
       ~SKG_Artist();
       QString GetArtistName(){return ArtistName;}
       QList<SKG_Album *> GetAlbums(){return Albums;}
       bool AlbumExists(QString albumname);  // Checks to see if the artist directory already contains a directory
                                             // for the specified album name. Used by the ripper function so as to
                                             // not add the same album twice.
       void AddAlbum(SKG_Album *newalbum){Albums.append(newalbum);}
       bool IsAvailable(){return Available;}
       void SetAvaialble(bool value){Available = value;}
       QString GetDirectoryName(){return DirectoryName;}
       void SortAlbums();
   };

// Library class. Maintains a list of artist objects, as well as various functions for accessing
// the individual albums and tracks.
class SKG_MusicLibrary {
    private :
        QList <SKG_Artist *> Artists;  // List of Artist objects
        QList <SKG_Album *> Albums;    // List of all the albums in numerical order
        QStringList DirectoryNames;
        void SortArtists();

    public :
        SKG_MusicLibrary();
        ~SKG_MusicLibrary();
        void AddDirectory(QDir *newdir);  // Adds a top level music directory
        QList <SKG_Artist *> GetArtists(){return Artists;}
        QList <SKG_Album *> GetAlbums();
        bool ArtistExists(QString artistname);  // Checks to see if artist exists in library. Used by ripper function.
        SKG_Album *GetAlbumByNumber(int albumnum);  // Returns a reference to an album object by 3 digit album number.
        SKG_Track *GetTrackByNumber(long tracknum); // Returns a reference to the individual track by 5 digit track id,
                                                    // consisting of the 3 digit album numer and the 2 digit track number.
                                                    // For example, the 7th track on album 39 would have a track id of 03907.
        SKG_Album *GetAlbumByName(QString artistname, QString albumname);
        void AddArtist(SKG_Artist *Artist){Artists.append(Artist);SortArtists();}
        QStringList GetDirectoryNames(){return DirectoryNames;}
        SKG_Artist* GetArtistByName(QString artistname);
        void SaveToFile(QString fname);
        void LoadFromFile(QString fname);
        void Clear();
        QStringList ArtistNames();
        SKG_Artist *ArtistStartsWith(QString str);

    };


#endif  //SKGLIB_H
