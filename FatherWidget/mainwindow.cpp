#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    childForm( new Form(this) ),
    dialog( new Dialog(this) )
{
    childForm->hide();
    dialog->hide();
    ui->setupUi(this);

    dialog->setWindowFlags(Qt::FramelessWindowHint);
    dialog->move(10, 10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_showButton_clicked()
{
    //childForm->show();
    dialog->show();
}

void MainWindow::on_hideButton_clicked()
{
    //childForm->hide();
    dialog->hide();
}
