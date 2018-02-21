CONFIG += designer \
    plugin \
    debug_and_release
TARGET = $$qtLibraryTarget(skg_albumpanelplugin)
TEMPLATE = lib
HEADERS = skg_albumpanelplugin.h \
    skg_albumpanelframe.h
SOURCES = skg_albumpanelplugin.cpp \
    skg_albumpanelframe.cpp
RESOURCES = icons.qrc
LIBS += -L.
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
include(skg_albumpanel.pri)
FORMS += skg_albumpanelframe.ui
