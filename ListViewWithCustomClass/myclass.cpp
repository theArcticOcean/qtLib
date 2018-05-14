#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

//void MyClass::setPriority(MyClass::Priority priority)
//{
//    m_priority = priority;
//    emit priorityChanged(priority);
//}

//MyClass::Priority MyClass::priority() const
//{
//    return m_priority;
//}

//QList<Space::CallLog> MyClass::fetchList()

//QList<CallLog> MyClass::fetchList()
//{
//    QList<CallLog> result;

//    for(int i = 0;i < 3; i++)
//    {
//        CallLog newLog;
//        newLog.logId = i+1;
//        newLog.number = QString::number(i+1);

//        result.append(newLog);
//    }

//    return result;
//}

QList<QString> MyClass::fetchNumbers()
{
    QList<QString> result;

    for(int i = 0;i < 3; i++)
    {
        QString newStr;
        newStr = QString::number(i+1);
        result.append(newStr);
    }

    return result;
}

ObjectListModelT<MyData *>* MyClass::fetchDataClass()
{
    ObjectListModelT<MyData *>* result;

    result = new ObjectListModelT<MyData *>();
    result->setIsPointerFlag( true );

    for(int i = 0;i < 3; i++)
    {
        MyData *newData = new MyData();
        //qDebug()<<i<<": "<<newData;
        newData->init(i+1, QString::number(i+1));
        result->append(newData);
    }

    return result;
}

//QList<MyData*> MyClass::fetchMyData()
//{
//    QList<MyData*> result;

//    for(int i = 0;i < 3; i++)
//    {
//        MyData *newData = new MyData();
//        newData->init(i+1, QString::number(i+1));
//        result.append(newData);
//    }

//    return result;
//}
