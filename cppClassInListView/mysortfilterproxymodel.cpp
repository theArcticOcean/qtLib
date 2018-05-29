#include "mysortfilterproxymodel.h"

MySortFilterProxyModel::MySortFilterProxyModel()
{

}

bool MySortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index0 = sourceModel()->index(source_row, source_parent);
    QVariant var = sourceModel()->data(index0);
    MyData* item = var.value<MyData *>();
    return ( item->getNumber() == filterId );
}

QVariantList MySortFilterProxyModel::allData() const
{
    QModelIndex modelIndex;
    QVariant var;
    QVariantList varList;

    for( int i=0; i<rowCount(); ++i )
    {
        modelIndex = createIndex(i, 0);
        var = data(modelIndex);
        varList.append(var);
    }

    return varList;
}

bool MySortFilterProxyModel::SetFilterId(int id)
{
    filterId = id;
}
