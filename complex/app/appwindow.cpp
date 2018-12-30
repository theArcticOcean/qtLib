#include "appwindow.h"

Window::Window()
{
    m_Button = new QPushButton( this );
    m_Label = new QLabel(this);
    m_Label->setGeometry( m_Button->x() + m_Button->width() / 2,
                          m_Button->y() + m_Button->height(),
                          30,
                          30 );
    connect( m_Button, &QPushButton::released, this, &Window::OnButtonClicked );

    resize( 100, 100 );
}

Window::~Window()
{
    delete m_Button;
    delete m_Label;
}

void Window::OnButtonClicked()
{
    m_Label->setText( QString("<b>%1</b>").arg( m_Base.GetClickTimes() ) );
}
