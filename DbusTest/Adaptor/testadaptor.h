#ifndef TESTADAPTOR_H
#define TESTADAPTOR_H

#include <QObject>
#include "orgexampleddbustest_adaptor.h"

class TestAdaptor : public QObject
{
    Q_OBJECT
public:
    explicit TestAdaptor(QObject *parent = nullptr);

signals:
    void valueChanged( double newValue);

public slots:
    void setValue(double newValue);
    double getValue();

private:
    double value;
};

#endif // TESTADAPTOR_H
