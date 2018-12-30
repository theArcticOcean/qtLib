#include "base.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>

class Window: public QWidget
{
public:
    Window();
    ~Window();

public slots:
    void OnButtonClicked();

private:
    QPushButton *m_Button;
    QLabel *m_Label;
    Base m_Base;
};
