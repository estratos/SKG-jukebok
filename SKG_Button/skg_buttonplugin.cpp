#include "skg_button.h"
#include "skg_buttonplugin.h"

#include <QtCore/QtPlugin>

SKG_ButtonPlugin::SKG_ButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SKG_ButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SKG_ButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *SKG_ButtonPlugin::createWidget(QWidget *parent)
{
    return new SKG_Button(parent);
}

QString SKG_ButtonPlugin::name() const
{
    return QLatin1String("SKG_Button");
}

QString SKG_ButtonPlugin::group() const
{
    return QLatin1String("SKG");
}

QIcon SKG_ButtonPlugin::icon() const
{
    return QIcon();
}

QString SKG_ButtonPlugin::toolTip() const
{
    return QLatin1String("");
}

QString SKG_ButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool SKG_ButtonPlugin::isContainer() const
{
    return false;
}

QString SKG_ButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SKG_Button\" name=\"sKG_Button\">\n</widget>\n");
}

QString SKG_ButtonPlugin::includeFile() const
{
    return QLatin1String("skg_button.h");
}

Q_EXPORT_PLUGIN2(skg_buttonplugin, SKG_ButtonPlugin)
