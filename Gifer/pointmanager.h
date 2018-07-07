#ifndef POINTMANAGER_H
#define POINTMANAGER_H

#include <QObject>
#include <QPointF>

class PointManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double width READ getWidth NOTIFY widthChanged)
    Q_PROPERTY(double height READ getHeight NOTIFY heightChanged)
    Q_PROPERTY(double leftTopX READ getLeftTopX NOTIFY leftTopXChanged)
    Q_PROPERTY(double leftTopY READ getLeftTopY NOTIFY leftTopYChanged)

public:
    explicit PointManager(QObject *parent = 0);
    Q_INVOKABLE void setLeftTopPoint( double x, double y );
    Q_INVOKABLE void setRightBottomPoint( double x, double y );

signals:
    void widthChanged();
    void heightChanged();
    void leftTopXChanged();
    void leftTopYChanged();

public slots:

private:
    double getWidth();
    double getHeight();
    double getLeftTopX();
    double getLeftTopY();

    QPointF leftTop;
    QPointF rightBottom;
};

#endif // POINTMANAGER_H
