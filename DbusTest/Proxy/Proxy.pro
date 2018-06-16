QT -= gui
QT += dbus

DBUS_INTERFACES += OrgExampleDdbusTest.xml

CONFIG += c++11 console
SOURCES += main.cpp \
    testproxy.cpp

# install
target.path ="~/code/qtLib/DbusTest/Proxy"
INSTALLS += target

HEADERS += \
    testproxy.h
