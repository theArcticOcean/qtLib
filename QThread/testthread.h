#ifndef TESTTHREAD_H
#define TESTTHREAD_H
#include <QThread>
#include <QDebug>

class testThread:public QThread
{
protected:
    void run();
public:
    testThread();
};

#endif // TESTTHREAD_H
