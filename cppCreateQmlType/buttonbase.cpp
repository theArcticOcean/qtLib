#include "buttonbase.h"

ButtonBase::ButtonBase
    (
    QQuickItem *parent
    )
    : QQuickItem( parent )
{
    setButtonName( "default button" );
    setImplicitHeight(50);
    setImplicitWidth(50);
    setVisible(true);
}

QString ButtonBase::getButtonName()
{
    return name;
}

void ButtonBase::setButtonName(const QString newName)
{
    name = newName;
    emit buttonNameChanged();
}
