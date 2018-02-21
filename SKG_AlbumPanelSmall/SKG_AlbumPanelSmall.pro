CONFIG += designer \
    plugin \
    debug_and_release
TARGET = $$qtLibraryTarget(skg_albumpanelsmallplugin)
TEMPLATE = lib
HEADERS = skg_albumpanelsmallplugin.h \
    skg_albumpanelframesmall.h

SOURCES = skg_albumpanelsmallplugin.cpp \
    skg_albumpanelframesmall.cpp

RESOURCES = icons.qrc
LIBS += -L.
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
include(skg_albumpanelsmall.pri)
FORMS += skg_albumpanelframesmall.ui
