#include "testproxy.h"
#include <QDebug>

TestProxy::TestProxy(QObject *parent) : QObject(parent)
{
    testInterface = new OrgExampleQdbusWtestInterface(
                                                        "org.example.dbus.test",
                                                        "/DbusTest",
                                                        QDBusConnection::sessionBus(),
                                                        this
                                                     );
    connect( testInterface, &OrgExampleQdbusWtestInterface::valueChanged,
             this, &TestProxy::onValueChanged );


    // After call testInterface->getValue(), server return true value (12)
    QDBusPendingReply<double> reply = testInterface->getValue();
    // But the true value will not be transfer client by normal method unless we use signal.
    qDebug() << "original value: " << reply.value();
    testInterface->setValue( 20 );
}

void TestProxy::onValueChanged(double newValue)
{
    qDebug() << "onValueChanged, interface get value: " << newValue;
}
