#ifndef OBJECTLISTMODELBASE_H
#define OBJECTLISTMODELBASE_H

#include <QAbstractListModel>

class ObjectListModelBase : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ Count WRITE setCount NOTIFY rowCountChanged)

public:
    ObjectListModelBase();
    virtual int Count(const QModelIndex &parent = QModelIndex()) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent) const;
    Q_INVOKABLE virtual QVariant row(const int index) const = 0;
    Q_INVOKABLE virtual QVariantList allData() const = 0;
signals:
    void rowCountChanged(int count);

public slots:
    void setCount(int count);

private:
    int elementCount;
};

#endif // OBJECTLISTMODELBASE_H
