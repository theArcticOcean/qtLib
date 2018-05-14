#include "brightness.h"
#include <QDebug>

BrightNess* BrightNess::instance = NULL;

BrightNess::BrightNess(QObject *parent) : QObject(parent)
{
    brightLevel = 0;
}

BrightNess *BrightNess::getInstance()
{
    if( NULL == instance )
    {
        instance = new BrightNess();
    }

    return instance;
}

void BrightNess::addBrightLevel()
{
    ++brightLevel;
    qDebug()<<"brightLevel: "<<brightLevel;
}
