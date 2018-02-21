#include "skg_roundbutton.h"
#include "skg_roundbuttonplugin.h"

#include <QtCore/QtPlugin>

SKG_RoundButtonPlugin::SKG_RoundButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SKG_RoundButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SKG_RoundButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SKG_RoundButtonPlugin::createWidget(QWidget *parent)
{
    return new SKG_RoundButton(parent);
}

QString SKG_RoundButtonPlugin::name() const
{
    return QLatin1String("SKG_RoundButton");
}

QString SKG_RoundButtonPlugin::group() const
{
    return QLatin1String("SKG");
}

QIcon SKG_RoundButtonPlugin::icon() const
{
    return QIcon();
}

QString SKG_RoundButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SKG_RoundButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SKG_RoundButtonPlugin::isContainer() const
{
    return false;
}

QString SKG_RoundButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SKG_RoundButton\" name=\"sKG_RoundButton\">\n</widget>\n");
}

QString SKG_RoundButtonPlugin::includeFile() const
{
    return QLatin1String("skg_roundbuton.h");
}

Q_EXPORT_PLUGIN2(skg_roundbuttonplugin, SKG_RoundButtonPlugin)
