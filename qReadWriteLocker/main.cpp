#include <QApplication>
#include <QMessageBox>
#include <QDebug>

#include "increasethread.h"
#include "readthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextDevice device;
    IncreaseThread thread1( &device );
    thread1.start();
    ReadThread thread2( &thread1, &device );
    thread2.start();
    QMessageBox::information( 0, "Threading", "Close me to stop!" );
    IncreaseThread::stoped = true;
    thread1.wait();
    thread2.wait();
    qDebug() << "Finished";
    return a.exec();
}
