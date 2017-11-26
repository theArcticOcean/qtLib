#include "thread2control.h"
#include <QDebug>
#include <unistd.h>
#include <pthread.h>

thread2Control::thread2Control()
{
    myThread = new QThread;
    testThread2 *thread2 = new testThread2;
    thread2->moveToThread(myThread);
    connect(thread2,SIGNAL(resultChange(int)),this,SLOT(resultHandle(int)));
    connect(myThread,SIGNAL(finished()),thread2,SLOT(deleteLater()));
    myThread->start();
    thread2->addChange(0);
}

thread2Control::~thread2Control()
{
    delete myThread;
}

void thread2Control::resultHandle(int a)
{
    qDebug()<<"pid: "<<getpid()
           <<", tid: "<<pthread_self()
           <<", handle: "<<QThread::currentThreadId()
           <<", a: "<<a;
}
