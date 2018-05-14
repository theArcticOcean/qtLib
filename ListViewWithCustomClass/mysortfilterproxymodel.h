#ifndef MYSORTFILTERPROXYMODEL_H
#define MYSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "mydata.h".h"

class MySortFilterProxyModel : public QSortFilterProxyModel
{
public:
    MySortFilterProxyModel();
    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    void setFilterId(int id);
    QVariantList allData() const;
private:
    int filterId;
};

#endif // MYSORTFILTERPROXYMODEL_H
