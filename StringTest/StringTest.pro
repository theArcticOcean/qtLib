QT       += testlib
TARGET = tst_string
CONFIG   += console
CONFIG   -= app_bundle

SOURCES += \
        tst_string.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
