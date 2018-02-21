#-------------------------------------------------
#
# Project created by QtCreator 2010-08-11T00:49:02
#
#-------------------------------------------------

QT       -= gui

TARGET = cdio
TEMPLATE = lib

DEFINES += CDIO_LIBRARY

CONFIG += dll

#INCLUDEPATH += C:\SKG_Jukebox\cdio

SOURCES += \
    ../../cdio/track.c \
    ../../cdio/sector.c \
    ../../cdio/read.c \
    ../../cdio/disc.c \
    ../../cdio/device.c \
    ../../cdio/cdtext.c \
    ../../cdio/cdio.c

HEADERS +=\
    ../../cdio/types.h \
    ../../cdio/track.h \
    ../../cdio/sector.h \
    ../../cdio/read.h \
    ../../cdio/disc.h \
    ../../cdio/device.h \
    ../../cdio/cdtext.h \
    ../../cdio/cdio.h \
    ../../cdio/version.h \
    ../../cdio/cdio_private.h \
    ../../cdio/audio.h \
    ../../cdio/mmc_private.h \
    ../../cdio/mmc.h \
    ../../cdio/mmc_util.h \
    ../../cdio/dvd.h \
    ../../cdio/generic.h \
    ../../cdio/iso9660.h \
    ../../cdio/posix.h \
    ../../cdio/ds.h \
    ../../cdio/xa.h \
    ../../cdio/rock.h \
    ../../cdio/logging.h \
    ../../cdio/util.h \
    ../../cdio/cdio_assert.h \
    ../../cdio/mmc_cmds.h \
    ../../cdio/mmc_hl_cmds.h \
    ../../cdio/mmc_ll_cmds.h \
    ../../cdio/cd_types.h
