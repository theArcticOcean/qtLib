#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "form.h"
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showButton_clicked();

    void on_hideButton_clicked();

private:
    Ui::MainWindow *ui;
    Form *childForm;
    Dialog *dialog;
};

#endif // MAINWINDOW_H
