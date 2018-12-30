TEMPLATE = lib
TARGET = base
VERSION = 0.1.0
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.13
message( "This is a message for deploy target: " )
message( $$QMAKE_MACOSX_DEPLOYMENT_TARGET )
CONFIG += static
CONFIG += sdk_no_version_check #keep warning silent
DESTDIR = ../lib

INCLUDEPATH += ../include
DEPENDPATH += . ../include
SOURCES += base.cpp
HEADERS += base.h
