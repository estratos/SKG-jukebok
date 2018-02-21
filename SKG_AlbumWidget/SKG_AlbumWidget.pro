CONFIG += designer \
    plugin \
    debug_and_release
TARGET = $$qtLibraryTarget(skg_albumwidgetplugin)
TEMPLATE = lib
HEADERS = skg_albumwidgetplugin.h \
    skg_albumframe.h \

SOURCES = skg_albumwidgetplugin.cpp \
    skg_albumframe.cpp \

RESOURCES = icons.qrc
LIBS += -L.
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
include(skg_albumwidget.pri)
FORMS += skg_albumframe.ui
