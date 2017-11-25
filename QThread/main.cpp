#include <QCoreApplication>
#include "testthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testThread *thread = new testThread;
    thread->start(QThread::NormalPriority);
    return a.exec();
}
