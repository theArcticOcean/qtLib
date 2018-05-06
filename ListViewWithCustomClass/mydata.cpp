#include "mydata.h"

MyData::MyData(QObject *parent) : QObject(parent)
{
    connect( this, SIGNAL(numberChanged(int)), this, SLOT(setNumber(int)) );
    connect( this, SIGNAL(nameChanged(QString)), this, SLOT(setName(QString)) );
}

int MyData::getNumber()
{
    return number;
}

QString MyData::getName()
{
    return name;
}

void MyData::init(int num, QString str)
{
    number = num;
    name = str;
}

void MyData::setNumber(int number)
{
    this->number = number;
}

void MyData::setName(QString str)
{
    this->name = str;
}
