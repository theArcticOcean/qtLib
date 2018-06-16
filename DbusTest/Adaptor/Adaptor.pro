QT -= gui
QT += dbus

DBUS_ADAPTORS += OrgExampleDdbusTest.xml

CONFIG += c++11 console
SOURCES += main.cpp \
    testadaptor.cpp

# install
target.path ="~/code/qtLib/DbusTest/Adaptor"
INSTALLS += target

HEADERS += \
    testadaptor.h
