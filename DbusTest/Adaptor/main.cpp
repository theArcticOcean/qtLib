#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusMessage>
#include "testadaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestAdaptor tAdaptor;
    new WtestAdaptor(&tAdaptor);
    QDBusConnection connection = QDBusConnection::sessionBus();  //systemBus() always fail in my mac.
    connection.registerObject("/DbusTest", &tAdaptor);
    connection.registerService("org.example.dbus.test");
    qDebug() << "has error ? " << connection.lastError();
    return a.exec();
}
