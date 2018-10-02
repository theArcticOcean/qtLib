#include "textdevice.h"

#include <QDebug>

TextDevice::TextDevice()
{
    count = 0;
}

void TextDevice::increse()
{
    QWriteLocker locker(&lock);
    count++;
}

void TextDevice::read()
{
    QReadLocker locker(&lock);
    qDebug() << QString::number( count );
}
