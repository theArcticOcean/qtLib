#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
#include "increasethread.h"
#include "textdevice.h"

class ReadThread : public QThread
{
public:
    ReadThread(IncreaseThread *_iThread, TextDevice *_m_Device);
    void run();
private:
    IncreaseThread *iThread;
    TextDevice *m_Device;
};

#endif // READTHREAD_H
