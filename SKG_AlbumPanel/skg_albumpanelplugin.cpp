#include "skg_albumpanel.h"
#include "skg_albumpanelplugin.h"

#include <QtCore/QtPlugin>

SKG_AlbumPanelPlugin::SKG_AlbumPanelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SKG_AlbumPanelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SKG_AlbumPanelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SKG_AlbumPanelPlugin::createWidget(QWidget *parent)
{
    return new SKG_AlbumPanel(parent);
}

QString SKG_AlbumPanelPlugin::name() const
{
    return QLatin1String("SKG_AlbumPanel");
}

QString SKG_AlbumPanelPlugin::group() const
{
    return QLatin1String("SKG");
}

QIcon SKG_AlbumPanelPlugin::icon() const
{
    return QIcon();
}

QString SKG_AlbumPanelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SKG_AlbumPanelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SKG_AlbumPanelPlugin::isContainer() const
{
    return false;
}

QString SKG_AlbumPanelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SKG_AlbumPanel\" name=\"sKG_AlbumPanel\">\n</widget>\n");
}

QString SKG_AlbumPanelPlugin::includeFile() const
{
    return QLatin1String("skg_albumpanel.h");
}

Q_EXPORT_PLUGIN2(skg_albumpanelplugin, SKG_AlbumPanelPlugin)
