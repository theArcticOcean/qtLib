TEMPLATE = app
TARGET = app
QT += widgets
DESTDIR = ../bin
INCLUDEPATH += ./ ../include
DEPENDPATH += ./
LIBS += -L../lib -lbase

SOURCES += appwindow.cpp main.cpp
HEADERS += appwindow.h
