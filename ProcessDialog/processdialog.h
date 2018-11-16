#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class ProcessDialog;
}

class ProcessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProcessDialog(QWidget *parent = 0);
    ~ProcessDialog();

private slots:
    void runUic();

    void handleError( QProcess::ProcessError );
    void handleFinish( int, QProcess::ExitStatus );
    void handleReadStandardError();
    void handleReadStandardOutput();
    void handleStarted();
    void handleStateChange( QProcess::ProcessState );

    void on_uicButton_clicked();

private:
    QProcess *process;
    Ui::ProcessDialog *ui;
};

#endif // PROCESSDIALOG_H
