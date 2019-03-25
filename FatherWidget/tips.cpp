#include "tips.h"
#include "ui_tips.h"

#include <QDebug>

Tips::Tips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tips)
{
    ui->setupUi(this);
    setStyleSheet( "background-color:black" );
}

Tips::~Tips()
{
    delete ui;
}
