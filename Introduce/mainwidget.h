#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QTextBrowser>
#include "textedit.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void FetchApplicationPtr( QApplication *app );
private slots:
    void on_pushButton_clicked();
    void on_textEditClosed();

private:
    Ui::MainWidget *ui;
    QApplication *m_ApplicationPtr;
    TextEdit *m_TextEdit;
    QTextBrowser *m_TextBrowser;
};

#endif // MAINWIDGET_H
