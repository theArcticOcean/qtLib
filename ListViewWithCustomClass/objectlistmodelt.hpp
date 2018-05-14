#ifndef OBJECTLISTMODELT_HPP
#define OBJECTLISTMODELT_HPP

#include <QList>
#include <QModelIndex>
#include "objectlistmodelbase.h"
#include <QDebug>
#include "mysortfilterproxymodel.h"

template<typename T>
class ObjectListModelT : public ObjectListModelBase
{
public:
    ObjectListModelT()
    {
        setCount( itemsList.count() );
        typeIsPointer = false;
    }

    ~ObjectListModelT()
    {
        clear();
    }

    void append(T it)
    {
        itemsList.append(it);
        emit rowCountChanged(itemsList.size());
    }

    void clear()
    {
        if( Count() > 0 )
        {
            if( typeIsPointer )
            {
                for( int i = 0; i < Count(); i++ )
                {
                    delete itemsList[i];
                    itemsList[i] = NULL;
                }
            }

            itemsList.clear();
            emit rowCountChanged(0);
        }
    }

    virtual QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const
    {
        if(Qt::DisplayRole == role)
        {
            int row = index.row();
            if( row > Count() )
            {
                return QVariant();  //Constructs an invalid variant.
            }
            //return itemsList[row];
            return QVariant::fromValue((MyData *)itemsList[row]); //fromValue copy T
            // why would we got null pointer if set `MyData *` as `void *` ?
        }
        else
        {
            return QVariant();
        }
    }

    Q_INVOKABLE QVariant row(const int index) const
    {
        QModelIndex modelIndex;
        modelIndex = createIndex(index, 0);
        QVariant var = data(modelIndex);
        //qDebug()<<"var is "<<var;
        return var;
    }

    Q_INVOKABLE QVariantList allData() const
    {
        QModelIndex modelIndex;
        QVariant var;
        QVariantList varList;

        for( int i=0; i<itemsList.length(); ++i )
        {
            modelIndex = createIndex(i, 0);
            var = data(modelIndex);
            varList.append(var);
        }

        return varList;
    }

    Q_INVOKABLE QVariantList allDataFiltered(int id) const
    {
        MySortFilterProxyModel* proxyModel = new MySortFilterProxyModel();
        proxyModel->setFilterId(id);
        proxyModel->setSourceModel( static_cast<QAbstractItemModel*>( allData() ) );
        return proxyModel->allData();
    }

    void setIsPointerFlag( bool tag )
    {
         typeIsPointer = tag;
    }

private:
    QList<T> itemsList;
    bool typeIsPointer;
};

#endif // OBJECTLISTMODELT_HPP
