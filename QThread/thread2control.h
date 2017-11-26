#ifndef THREAD2CONTROL_H
#define THREAD2CONTROL_H

#include <QObject>
#include <QThread>
#include <testthread2.h>

class thread2Control:public QObject
{
    Q_OBJECT
    QThread *myThread;
public:
    thread2Control();
    ~thread2Control();
public slots:
    void resultHandle(int a);
};

#endif // THREAD2CONTROL_H
