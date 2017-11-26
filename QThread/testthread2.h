#ifndef TESTTHREAD2_H
#define TESTTHREAD2_H

#include <QObject>

class testThread2:public QObject
{
    Q_OBJECT
public:
    testThread2();
    ~testThread2();
    void addChange(int a);
signals:
    void resultChange(int a);
};

#endif // TESTTHREAD2_H
