#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->toolButton1->setIcon( QIcon(":/handle.png") );
    ui->toolButton2->setIcon( QIcon(":/pen.png") );
    ui->toolButton3->setIcon( QIcon(":/array.png") );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButton1_clicked()
{
    setCursor( Qt::PointingHandCursor );
}

void Widget::on_toolButton3_clicked()
{
    setCursor( Qt::ArrowCursor );
}

void Widget::on_toolButton2_clicked()
{
    setCursor( QPixmap(":/pen.png") );
}
