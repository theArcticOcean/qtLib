#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>

class DataSource : public QObject
{
    Q_OBJECT

public:
    explicit DataSource(QObject *parent = nullptr);
    Q_INVOKABLE const char* getTime();

signals:

public slots:

};

#endif // DATASOURCE_H
