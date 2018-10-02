#ifndef INCREASETHREAD_H
#define INCREASETHREAD_H

#include <QThread>

#include "textdevice.h"

class IncreaseThread : public QThread
{
public:
    IncreaseThread( TextDevice *device );
    ~IncreaseThread();
    void run();
    unsigned long long getTimes();
    static bool stoped;

private:
    TextDevice *m_Device;
    unsigned long long times;
};

#endif // INCREASETHREAD_H
