#ifndef BUTTONBASE_H
#define BUTTONBASE_H

#include <QQuickItem>

class ButtonBase : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY( QString buttonName READ getButtonName WRITE setButtonName NOTIFY buttonNameChanged )

public:
    ButtonBase( QQuickItem *parent = 0 );

    QString getButtonName();
    void setButtonName(const QString newName);

signals:
    void buttonNameChanged();

public slots:

private:
    QString name;
};

#endif // BUTTONBASE_H
