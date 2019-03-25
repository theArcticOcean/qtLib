#ifndef TIPS_H
#define TIPS_H

#include <QWidget>

namespace Ui {
class Tips;
}

class Tips : public QWidget
{
    Q_OBJECT

public:
    explicit Tips(QWidget *parent = 0);
    ~Tips();

private:
    Ui::Tips *ui;
};

#endif // WIDGET_H
