#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onSplitterMoved(int pos, int index);
private:
    Ui::MainWindow *ui;

    QSplitter *splitter;
//    QPushButton *pushButton;
//    QPushButton *pushButton2;
    QLabel *m_Label;
    QLabel *m_Label1;
    QLabel *m_Label2;
    //QTextEdit *textedit;
};

#endif // MAINWINDOW_H
