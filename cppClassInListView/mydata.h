#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>

class MyData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

public:
    explicit MyData(QObject *parent = 0);

    int getNumber();
    QString getName();
    void init(int num, QString str);

signals:
    void numberChanged(int number);
    void nameChanged(QString str);

public slots:
    void setNumber(int number);
    void setName(QString str);

private:
    int number;
    QString name;
};

#endif // MYDATA_H
