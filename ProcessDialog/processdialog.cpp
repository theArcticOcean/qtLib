#include "processdialog.h"
#include "ui_processdialog.h"
#include <errno.h>

ProcessDialog::ProcessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessDialog)
{
    ui->setupUi(this);
}

ProcessDialog::~ProcessDialog()
{
    delete ui;
}

/*
the result of a successful execution:
1. stateChanged( Starting )
2. started()
3. readyReadStandardOutput()(severaltimes)
4. stateChanged( NotRunning )
5. finished( 0, NormalExit )
*/

void ProcessDialog::runUic()
{
    ui->uicButton->setEnabled( false );
    ui->textEdit->setText("");

    if( process )
    {
        delete process;
        process = nullptr;
    }

    process = new QProcess( this );

    connect( process, SIGNAL(error(QProcess::ProcessError)),
               this, SLOT(handleError(QProcess::ProcessError)) );

    connect( process, SIGNAL(finished(int,QProcess::ExitStatus)),
               this, SLOT(handleFinish(int,QProcess::ExitStatus)) );

    connect( process, SIGNAL(readyReadStandardError()),
             this, SLOT(handleReadStandardError()) );

    connect( process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(handleReadStandardOutput()) );

    connect( process, SIGNAL(started()),
           this, SLOT(handleStarted()) );

    connect( process, SIGNAL(stateChanged(QProcess::ProcessState)),
           this, SLOT(handleStateChange(QProcess::ProcessState)) );

    QStringList arguments;
    arguments << "-tr" << "MYTR" << "/Users/weiyang/code/ProcessDialog/processdialog2.ui";

    process->start( "uic", arguments ); // it's a elegant way to pass parameters. uic generates
                                        // new code to standard output.
}

void ProcessDialog::handleError(QProcess::ProcessError _error)
{
    ui->textEdit->append( QString( "<p><b>ProcessError: (%1)</b><p>" ).arg( _error ) );
}

void ProcessDialog::handleFinish(int code, QProcess::ExitStatus status)
{
    QString statusText;

    switch( status )
    {
    case QProcess::NormalExit:
      statusText = "Normal exit";
      break;
    case QProcess::CrashExit:
      statusText = "Crash exit";
      break;
    }

    ui->textEdit->append( QString( "<p><b>%1 (%2)</b><p>" )
    .arg( statusText )
    .arg( code ) );
}

void ProcessDialog::handleReadStandardError()
{
    ui->textEdit->append( QString( "<p><b>ReadStandardError: (%1)</b><p>" ).arg( strerror(errno) ) );
}

void ProcessDialog::handleReadStandardOutput()
{
    ui->textEdit->append( QString( "<p><b>ReadStandardOutput</b><p>" ) );
}

void ProcessDialog::handleStarted()
{
    ui->textEdit->append( QString( "<p><b>handleStarted</b><p>" ) );
}

void ProcessDialog::handleStateChange(QProcess::ProcessState _state)
{
    ui->textEdit->append( QString( "<p><b>handleStateChange (%1)</b><p>" ).arg( _state ) );
}

void ProcessDialog::on_uicButton_clicked()
{
    runUic();
}
