CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(skg_buttonplugin)
TEMPLATE    = lib

HEADERS     = skg_buttonplugin.h
SOURCES     = skg_buttonplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(skg_button.pri)
