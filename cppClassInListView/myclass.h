#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QList>
#include "mydata.h"

#include "objectlistmodelt.hpp"

typedef struct
{
    qint64 logId;
    QString number;
}CallLog;

class MyClass : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(Priority priority READ priority WRITE setPriority NOTIFY priorityChanged)

    Q_PROPERTY( ObjectListModelBase* dataClass READ fetchDataClass NOTIFY dataClassChanged )

public:
    explicit MyClass(QObject *parent = 0);

    Q_INVOKABLE QList<QString> fetchNumbers();
    Q_INVOKABLE ObjectListModelT<MyData *>* fetchDataClass();

signals:
    void dataClassChanged();

//    QList<MyData*> fetchMyData();
//    enum Priority { High, Low, VeryHigh, VeryLow };
//    Q_ENUM(Priority)

//    void setPriority(Priority priority);

//    Priority priority() const;

//    Q_INVOKABLE QList<Space::CallLog> fetchList();
//    Q_INVOKABLE QList<CallLog> fetchList();  // not work because of Call struct

//signals:
//    void priorityChanged(Priority);

//private:
//    Priority m_priority;
};

#endif // MYCLASS_H
