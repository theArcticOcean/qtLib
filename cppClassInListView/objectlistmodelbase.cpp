#include "objectlistmodelbase.h"

ObjectListModelBase::ObjectListModelBase()
{
    elementCount = 0;
    QObject::connect( this, SIGNAL( rowCountChanged( int ) ),
                     this, SLOT( setCount( int ) ) );
}

int ObjectListModelBase::Count(const QModelIndex &parent) const
{
    return elementCount;
}

int ObjectListModelBase::rowCount(const QModelIndex &parent) const
{
    return elementCount;
}

int ObjectListModelBase::columnCount(const QModelIndex &parent) const
{
    return 0;
}

void ObjectListModelBase::setCount(int count)
{
    elementCount = count;
}
