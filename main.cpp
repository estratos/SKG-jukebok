#include <QtGui/QApplication>
#include "mainnetbook.h"
#include "mainnormal.h"
#include "jukeboxconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("SKG Jukebox");
    JukeboxConfig *config = new JukeboxConfig();
    if (config->GetOperatingMode() == modeNetbook)
    {
        MainNetbook w;
        w.SetConfig(config);
        w.showMaximized();
        w.LoadTrackList();
        return a.exec();
    }
    else
    {
        MainNormal w;
        w.SetConfig(config);
        w.showMaximized();
        w.LoadTrackList();
        return a.exec();
    }
}
