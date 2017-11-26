#include "testthread.h"
#include <unistd.h>
#include <QThread>
#include <pthread.h>

void testThread::run()
{
    int i;
    for(i=0; i<10; i++){
        usleep(200000);  //0.2 sec
        qDebug()<<"pid: "<<getpid()
               <<", tid: "<<pthread_self()
               <<", handle: "<<QThread::currentThreadId()
               <<", a: "<<i+1;
    }
}

testThread::testThread()
{
	// if testThread object is a pointer, we need to free it by deleteLater function.
	// or we need not connect finished and deleteLater
    connect(this, &testThread::finished, this, &QObject::deleteLater);
}
