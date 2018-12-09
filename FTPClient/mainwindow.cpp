#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file = nullptr;

    connect( ui->connectButton, &QPushButton::clicked,
           this, &MainWindow::connectClicked );
    connect( ui->disconnectButton, &QPushButton::clicked,
           this, &MainWindow::disconnectClicked );
    connect( ui->cdButton, &QPushButton::clicked,
           this, &MainWindow::cdClicked );
    connect( ui->upButton, &QPushButton::clicked,
           this, &MainWindow::upClicked );
    connect( ui->getButton, &QPushButton::clicked,
           this, &MainWindow::getClicked );
    connect( ui->dirList, &QListWidget::itemSelectionChanged,
           this, &MainWindow::selectionChanged );
    connect( &ftp, &QFtp::commandFinished,
           this, &MainWindow::ftpFinished );
    connect( &ftp, &QFtp::listInfo,
           this, &MainWindow::ftpListInfo );
    connect( &ftp, &QFtp::dataTransferProgress,
           this, &MainWindow::ftpProgress );

    ui->disconnectButton->setEnabled( false );
    ui->cdButton->setEnabled( false );
    ui->upButton->setEnabled( false );
    ui->getButton->setEnabled( false );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectClicked()
{
    ui->connectButton->setEnabled( false );
    ftp.connectToHost( "ftp.trolltech.com" );
    //ftp.connectToHost( "123.57.149.197" );
    //qDebug() << "ftp.log: " << ftp.login( QString(""), QString("") );
    ui->statusLabel->setText( tr("Connecting to host...") );
}

void MainWindow::disconnectClicked()
{
    ui->disconnectButton->setEnabled( false );
    ui->cdButton->setEnabled( false );
    ui->upButton->setEnabled( false );
    ui->getButton->setEnabled( false );

    ftp.close();
}

void MainWindow::cdClicked()
{
    ui->disconnectButton->setEnabled( false );
    ui->cdButton->setEnabled( false );
    ui->upButton->setEnabled( false );
    ui->getButton->setEnabled( false );
    ftp.cd( ui->dirList->selectedItems()[0]->text() );
    ui->statusLabel->setText( tr("Changing directory...") );
}

void MainWindow::upClicked()
{
    ui->disconnectButton->setEnabled( false );
    ui->cdButton->setEnabled( false );
    ui->upButton->setEnabled( false );
    ui->getButton->setEnabled( false );
    ftp.cd("..");
    ui->statusLabel->setText( tr("Changing directory...") );
}

void MainWindow::getClicked()
{
    QString fileName = QFileDialog::getSaveFileName( this, tr("Get File"),
                                  ui->dirList->selectedItems()[0]->text() );
    if( fileName.isEmpty() )
    {
        return;
    }
    file = new QFile( fileName, this );
    if( !file->open( QIODevice::WriteOnly|QIODevice::Truncate ) )
    {
        QMessageBox::warning( this, tr("Error"),
                              tr("Failed to open file %1 for writing.").arg( fileName ) );
        delete file;
        file = nullptr;
        return;
    }
    ui->disconnectButton->setEnabled( false );
    ui->cdButton->setEnabled( false );
    ui->upButton->setEnabled( false );
    ui->getButton->setEnabled( false );

    ftp.get( ui->dirList->selectedItems()[0]->text(), file );
    ui->statusLabel->setText( tr("Downloading file...") );
}

void MainWindow::selectionChanged()
{
    if( !ui->dirList->selectedItems().isEmpty() )
    {
        if( files.indexOf( ui->dirList->selectedItems()[0]->text() ) == -1 )
        {
            ui->cdButton->setEnabled( ui->disconnectButton->isEnabled() );
            ui->getButton->setEnabled( false );
        }
        else
        {
            ui->cdButton->setEnabled( false );
            ui->getButton->setEnabled( ui->disconnectButton->isEnabled() );
        }
    }
    else {
        ui->cdButton->setEnabled( false );
        ui->getButton->setEnabled( false );
    }
}

void MainWindow::ftpFinished(int request, bool error)
{
    // Handle errors depending on the command causing it
    if( error )
    {
        qDebug() << "ftp command: " << ftp.currentCommand();
        switch( ftp.currentCommand() )
        {
            case QFtp::ConnectToHost:
                QMessageBox::warning( this, tr("Error"), tr("Failed to connect to host.") );
                ui->connectButton->setEnabled( true );
                break;
            case QFtp::Login:
                QMessageBox::warning( this, tr("Error"), tr("Failed to login.") );
                ui->connectButton->setEnabled( true );
                break;
            case QFtp::List:
                QMessageBox::warning( this, tr("Error"),
                  tr("Failed to get file list.\nClosing connection.") );
                ftp.close();
                break;
            case QFtp::Cd:
                QMessageBox::warning( this, tr("Error"), tr("Failed to change directory.") );
                getFileList();
                break;
            case QFtp::Get:
                QMessageBox::warning( this, tr("Error"), tr("Failed to get file?") );
                file->close();
                file->remove();
                delete file;
                file = nullptr;
                ui->disconnectButton->setEnabled( true );
                ui->upButton->setEnabled( true );
                selectionChanged();
                break;
            default:
                break;
        }
        ui->statusLabel->setText( tr("Ready.") );
    }
    else
    {
        switch( ftp.currentCommand() )
        {
            case QFtp::ConnectToHost:
                ftp.login();
                break;
            case QFtp::Login:
                getFileList();
                break;
            case QFtp::Close:
                ui->connectButton->setEnabled( true );
                getFileList();
                break;
            case QFtp::List:
                ui->disconnectButton->setEnabled( true );
                ui->upButton->setEnabled( true );
                ui->statusLabel->setText( tr("Ready.") );
                break;
            case QFtp::Cd:
                getFileList();
                break;
            case QFtp::Get:
                file->close();
                delete file;
                file = nullptr;
                ui->disconnectButton->setEnabled( true );
                ui->upButton->setEnabled( true );
                selectionChanged();
                ui->statusLabel->setText( tr("Ready.") );
                break;
            default:
                break;
        }
    }
}

void MainWindow::ftpListInfo(const QUrlInfo &info)
{
    ui->dirList->addItem( info.name() );
    if( info.isFile() )
    {
        files << info.name();
    }
}

void MainWindow::ftpProgress(qint64 done, qint64 total)
{
    if( total == 0 )
    {
        return;
    }
    ui->statusLabel->setText( tr("Downloading file... (%1%)").
                              arg( QString::number( done*100.0/total, 'f', 1 ) ) );
}

void MainWindow::getFileList()
{
    ui->disconnectButton->setEnabled( false );
    ui->cdButton->setEnabled( false );
    ui->upButton->setEnabled( false );
    ui->getButton->setEnabled( false );
    ui->dirList->clear();
    files.clear();
    if( ftp.state() == QFtp::LoggedIn )
        ftp.list();
}
