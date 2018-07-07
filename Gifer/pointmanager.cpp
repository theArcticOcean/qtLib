#include "pointmanager.h"
#include <math.h>

PointManager::PointManager
    (
    QObject *parent
    )
    : QObject(parent)
    , leftTop( 0, 0 )
    , rightBottom( 0, 0 )
{

}

void PointManager::setLeftTopPoint(double x, double y)
{
    leftTop.setX( x );
    leftTop.setY( y );
    emit leftTopXChanged();
    emit leftTopYChanged();
}

void PointManager::setRightBottomPoint(double x, double y)
{
    rightBottom.setX( x );
    rightBottom.setY( y );
    emit widthChanged();
    emit heightChanged();
}

double PointManager::getWidth()
{
    return fabs( rightBottom.x() - leftTop.x() );
}

double PointManager::getHeight()
{
    return fabs( rightBottom.y() - leftTop.y() );
}

double PointManager::getLeftTopX()
{
    return leftTop.x();
}

double PointManager::getLeftTopY()
{
    return leftTop.y();
}
