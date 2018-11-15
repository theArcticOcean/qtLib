#ifndef TEXTDIALOG_H
#define TEXTDIALOG_H

#include <QDialog>
#include <qabstractbutton.h>

#include "textandnumber.h"

namespace Ui {
class TextDialog;
}

class TextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextDialog(QWidget *parent = 0);
    ~TextDialog();

public slots:
    void showText( TextAndNumber tan );

private slots:
    void buttonClicked( QAbstractButton *button );

    void on_pushButton_clicked();
signals:
    void getInfo( TextAndNumber tan );

private:
    int count;
    QMutex mutex;
    Ui::TextDialog *ui;
};

#endif // TEXTDIALOG_H
