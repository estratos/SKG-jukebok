#include "jukeboxconfig.h"
#include "lib/skglib.h"
#include <QFile>
#include <QTextStream>
#include <QErrorMessage>
#include <QDir>
#include <QApplication>
#include <exception>

JukeboxConfig::JukeboxConfig()
{
    OperatingMode = modeNone;
    CustomListName = "";
    Connected = true;
    SlidingSound = true;
    AnimationEnabled = true;
    RandomTrackEnabled = false;
    CollectionSize = sizeSmall;
    LoadConfigFile();
}

void JukeboxConfig::LoadConfigFile()
{
    QFile configfile(ConfigFile());
    QString cf = ConfigFile();
    QString nextline;
    QStringList parts;
    QString key;
    SKG_MusicLibrary *lib;
    QDir *musicdir;
    QErrorMessage errormsg;
    SplashForm = new frmSplash;
    bool x;

    errorType = configErrorTypeNone;
    lib = NULL;

    x=configfile.exists();
    if (!configfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //errormsg.showMessage("Unable to open config file");
        //return;
        SplashForm->ShowFirstTime();
        MusicDirectories.append(SplashForm->GetMusicDirectory());
        if (SplashForm->NormalSelected())
            OperatingMode = modeNormal;
        else
            OperatingMode = modeNetbook;

        if (SplashForm->Connected())
            Connected = true;
        else
            Connected = false;

        if (SplashForm->LargeSelected())
            CollectionSize = sizeLarge;
        else
            CollectionSize = sizeSmall;

        SaveConfigFile();
        //delete SplashForm;
        return;
    }

    SplashForm->ShowLoading();
    QTextStream instream(&configfile);
    while (!instream.atEnd())
    {
        nextline = instream.readLine();
        parts = nextline.split("|");
        key = QString(parts.at(0)).trimmed().toUpper();
        if (key == "MODE")
        {
            if (QString(parts.at(1)).trimmed().toUpper() == "NETBOOK")
                OperatingMode = modeNetbook;
            else if (QString(parts.at(1)).trimmed().toUpper() == "NORMAL")
                OperatingMode = modeNormal;
            else
            {
                OperatingMode = modeNone;
                errorType = configErrorTypeInvalidMode;
                errormsg.showMessage("Invalid Operating Mode. Please fix the config file");
            }
        }
        else if (key == "MUSICDIR")
        {
            //if (lib == NULL)
            //    lib = new SKG_MusicLibrary();
            try
            {
                MusicDirectories.append(parts.at(1));
                musicdir = new QDir(QString(parts.at(1)).trimmed());
                if (musicdir->exists())
                {
                    //lib->AddDirectory(musicdir);
                }
            }
            catch (...)
            {
                errormsg.showMessage(QString("Unable to add directory %1").arg(parts.at(1)));
                errorType = configErrorTypeMusicLibrary;
            }
        }
        else if (key == "CUSTOMLIST")
        {
            CustomListName = QString(parts.at(1)).trimmed();
        }
        else if (key == "CONNECTED")
        {
            if (parts.at(1).toUpper() == "F")
                Connected = false;
        }
        else if (key == "SIZE")
        {
            if (parts.at(1).toUpper() == "L")
                CollectionSize = sizeLarge;
            else if(parts.at(1).toUpper() == "S")
                CollectionSize = sizeSmall;
        }
        else if (key == "SLIDINGSOUND")
        {
            if (parts.at(1).toUpper() == "F")
                SlidingSound = false;
            else
                SlidingSound = true;
        }
        else if (key == "ANIMATION")
        {
            if (parts.at(1).toUpper() == "F")
                AnimationEnabled = false;
            else
                AnimationEnabled = true;
        }
        else if (key == "RANDOMTRACK")
        {
            if (parts.at(1).toUpper() == "F")
                RandomTrackEnabled = false;
            else
                RandomTrackEnabled = true;
        }

    }
    configfile.close();
}

void JukeboxConfig::DeleteDirectory(QString dirname)
{
    int i;

    for(i = 0; i < MusicDirectories.count(); i++)
    {
        if (MusicDirectories.at(i) == dirname)
            MusicDirectories.removeAt(i);
    }
}

void JukeboxConfig::SaveConfigFile()
{
    QString line;
    int i;

    QFile file(ConfigFile());
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

   if (OperatingMode == modeNetbook)
       line = "mode|netbook\n";
   else
       line = "mode|normal\n";
   file.write(line.toAscii());

   for (i = 0; i < MusicDirectories.count(); i++)
   {
       line = "musicdir|" + MusicDirectories.at(i) + "\n";
       file.write(line.toAscii());
   }
   //
   if (CustomListName != "")
   {
       line = "customlist|" + CustomListName + "\n";
       file.write(line.toAscii());
   }
   //
   if (Connected)
   {
       line = "connected|T\n";
   }
   else
   {
       line = "connected|F\n";
   }
   file.write(line.toAscii());
   //
   if (SlidingSound)
   {
        line = "SlidingSound|T\n";
   }
   else
   {
       line = "SlidingSound|F\n";
   }
   file.write(line.toAscii());
   //
   if (AnimationEnabled)
   {
        line = "Animation|T\n";
   }
   else
   {
       line = "Animation|F\n";
   }
   file.write(line.toAscii());
   //
   if (RandomTrackEnabled)
   {
       line = "RandomTrack|T\n";
   }
   else
   {
       line = "RandomTrack|F\n";
   }
   file.write(line.toAscii());
   //
   if (CollectionSize == sizeLarge)
   {
       line = "size|L";
   }
   else
   {
       line = "size|S";
   }
   file.write(line.toAscii());

   file.close();
}

void JukeboxConfig::KillSplashForm()
{
    SplashForm->close();
    delete SplashForm;
}

QString ResourcesDirectory()
{
    QString tmpstr;
    tmpstr = QApplication::applicationDirPath();
    if (tmpstr.right(1) != "/")
        tmpstr = tmpstr + "/";
    tmpstr = tmpstr + "resources";

    QDir d(tmpstr);
    if (d.exists())
        return tmpstr;
    else
        return "C:/SKG_Jukebox/resources";
}

QString UpArrow()
{
    return ResourcesDirectory() + "/arrow-bold-up.jpg";
}

QString DownArrow()
{
    return ResourcesDirectory() + "/arrow-bold-down.jpg";
}

QString LeftArrow()
{
    return ResourcesDirectory() + "/arrow-bold-left.jpg";
}

QString RightArrow()
{
    return ResourcesDirectory() + "/arrow-bold-right.jpg";
}

QString ConfigFile()
{
    return ResourcesDirectory() + "/Config.txt";
}

QString TrackListFile()
{
    return ResourcesDirectory() + "/TrackList.txt";
}

QString LibraryFile()
{
    return ResourcesDirectory() + "/Library.xml";
}
