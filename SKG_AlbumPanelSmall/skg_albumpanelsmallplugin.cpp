#include "skg_albumpanelsmall.h"
#include "skg_albumpanelsmallplugin.h"

#include <QtCore/QtPlugin>

SKG_AlbumPanelSmallPlugin::SKG_AlbumPanelSmallPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SKG_AlbumPanelSmallPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SKG_AlbumPanelSmallPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SKG_AlbumPanelSmallPlugin::createWidget(QWidget *parent)
{
    return new SKG_AlbumPanelSmall(parent);
}

QString SKG_AlbumPanelSmallPlugin::name() const
{
    return QLatin1String("SKG_AlbumPanelSmall");
}

QString SKG_AlbumPanelSmallPlugin::group() const
{
    return QLatin1String("SKG");
}

QIcon SKG_AlbumPanelSmallPlugin::icon() const
{
    return QIcon();
}

QString SKG_AlbumPanelSmallPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SKG_AlbumPanelSmallPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SKG_AlbumPanelSmallPlugin::isContainer() const
{
    return false;
}

QString SKG_AlbumPanelSmallPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SKG_AlbumPanelSmall\" name=\"sKG_AlbumPanelSmall\">\n</widget>\n");
}

QString SKG_AlbumPanelSmallPlugin::includeFile() const
{
    return QLatin1String("skg_albumpanelsmall.h");
}

Q_EXPORT_PLUGIN2(skg_albumpanelsmallplugin, SKG_AlbumPanelSmallPlugin)
