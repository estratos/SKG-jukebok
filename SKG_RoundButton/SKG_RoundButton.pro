CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(skg_roundbuttonplugin)
TEMPLATE    = lib

HEADERS     = skg_roundbuttonplugin.h
SOURCES     = skg_roundbuttonplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(skg_roundbutton.pri)
