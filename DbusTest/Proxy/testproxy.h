#ifndef TESTPROXY_H
#define TESTPROXY_H

#include <QObject>
#include "orgexampleddbustest_interface.h"

class TestProxy : public QObject
{
    Q_OBJECT
public:
    explicit TestProxy(QObject *parent = nullptr);

signals:

public slots:
    void onValueChanged(double newValue);

private:
    OrgExampleQdbusWtestInterface *testInterface;
};

#endif // TESTPROXY_H
