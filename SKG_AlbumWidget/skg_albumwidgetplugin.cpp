#include "skg_albumwidget.h"
#include "skg_albumwidgetplugin.h"

#include <QtCore/QtPlugin>

SKG_AlbumWidgetPlugin::SKG_AlbumWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SKG_AlbumWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SKG_AlbumWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SKG_AlbumWidgetPlugin::createWidget(QWidget *parent)
{
    return new SKG_AlbumWidget(parent);
}

QString SKG_AlbumWidgetPlugin::name() const
{
    return QLatin1String("SKG_AlbumWidget");
}

QString SKG_AlbumWidgetPlugin::group() const
{
    return QLatin1String("SKG");
}

QIcon SKG_AlbumWidgetPlugin::icon() const
{
    return QIcon();
}

QString SKG_AlbumWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SKG_AlbumWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SKG_AlbumWidgetPlugin::isContainer() const
{
    return false;
}

QString SKG_AlbumWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SKG_AlbumWidget\" name=\"sKG_AlbumWidget\">\n</widget>\n");
}

QString SKG_AlbumWidgetPlugin::includeFile() const
{
    return QLatin1String("skg_albumwidget.h");
}

Q_EXPORT_PLUGIN2(skg_albumwidgetplugin, SKG_AlbumWidgetPlugin)
