#include <QCoreApplication>
#include "testthread.h"
#include <thread2control.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // simple thread class inherit QThread
    testThread *thread = new testThread;
    thread->start(QThread::NormalPriority);

    // a class which changed by moveToThread
    thread2Control *controller = new thread2Control;
    return a.exec();
}
/*
we get result:

pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  1
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  1
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  2
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  2
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  3
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  3
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  4
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  4
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  5
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  5
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  6
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  6
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  7
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  7
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  8
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  8
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  9
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  9
pid:  3102 , tid:  0x70000acb0000 , handle:  0x70000acb0000 , a:  10
pid:  3102 , tid:  0x7fff8ee18340 , handle:  0x7fff8ee18340 , a:  10

we can get a conclusion QThread::currentThreadId() return tid(handle) and
they are different, but all thread run in same process.
*/
