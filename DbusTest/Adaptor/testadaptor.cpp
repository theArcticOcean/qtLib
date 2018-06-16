#include "testadaptor.h"

TestAdaptor::TestAdaptor(QObject *parent) : QObject(parent)
{
    value = 12;
}

void TestAdaptor::setValue(double newValue)
{
    qDebug() << "TestAdaptor::setValue " << newValue;
    value = newValue;
    emit valueChanged( value );
}

double TestAdaptor::getValue()
{
    qDebug() << "TestAdaptor::getValue " << value;
    return value;
}
