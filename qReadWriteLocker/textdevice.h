#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QString>
#include <QReadWriteLock>

class TextDevice
{
public:
    TextDevice();
    void increse();
    void read();

private:
    int count;
    QReadWriteLock lock;
};

#endif // TEXTDEVICE_H
