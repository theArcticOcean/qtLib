#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "textedit.h"

#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMainWindow>
#include <QResizeEvent>
#include <QStatusBar>
#include <QTextDocumentWriter>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    m_ApplicationPtr( nullptr ),
    m_TextBrowser( nullptr ),
    m_LastPos( -1 )
{
    ui->setupUi(this);

    m_TextEdit = new TextEdit(this);
    m_TextEdit->hide();

    connect( m_TextEdit, SIGNAL(closed()), this, SLOT(on_textEditClosed()) );
    m_ApplicationDirPath = QCoreApplication::applicationDirPath();
}

MainWidget::~MainWidget()
{
    delete ui;
    ClearLabels();
    ClearMovies();
    if( m_TextBrowser )
    {
        delete m_TextBrowser;
        m_TextBrowser = nullptr;
    }
}

void MainWidget::FetchApplicationPtr(QApplication *app)
{
    m_ApplicationPtr = app;
}

void MainWidget::ClearLabels()
{
    std::for_each( m_Labels.begin(), m_Labels.end(), []( QLabel* label ){
        if( label ) {
            delete label;
            label = nullptr;
        } } );
    m_Labels.clear();
}

void MainWidget::ClearMovies()
{
    std::for_each( m_Movies.begin(), m_Movies.end(), []( QMovie* movie ){
        if( movie ) {
            delete movie;
            movie = nullptr;
        } } );
    m_Movies.clear();
}

void MainWidget::AdjustHeights(const int &height)
{
    if( m_TextBrowser )
    {
        m_TextBrowser->setMaximumHeight( height );
    }
    for( int i = 0; i < m_Labels.size(); ++i )
    {
        m_Labels[i]->setMaximumHeight( height );
    }
}

bool MainWidget::CheckPagePathExist()
{
    QString path = ui->pathValueLabel->text();
    return QFile::exists( path );
}

int MainWidget::GetAvaliableHeight()
{
    int height = ui->widget->height();
    int countOfElements = 0;
    if( m_TextBrowser )
    {
        countOfElements++;
    }
    countOfElements += m_Labels.size();
    return int( height * 1.0 / ( countOfElements + 1 ) );
}

void MainWidget::on_textEditClosed()
{
    if( !CheckPagePathExist() )
    {
        qDebug( "[%s, %d]: page path is empty", __FUNCTION__, __LINE__ );
        return ;
    }

    QTextDocumentWriter writer( m_HtmlPath );
    bool success = writer.write( m_TextEdit->textEdit->document());
    qDebug( "[%s, %d]: success: %d", __FUNCTION__, __LINE__, success );
    if (success) {
        m_TextEdit->textEdit->document()->setModified(false);
        m_TextEdit->statusBar()->showMessage(tr("Wrote \"%1\"").arg(QDir::toNativeSeparators( m_HtmlPath )));
    } else {
        m_TextEdit->statusBar()->showMessage(tr("Could not write to file \"%1\"")
                                 .arg(QDir::toNativeSeparators( m_HtmlPath )));
    }

    QString htmlContent = m_TextEdit->textEdit->toHtml();
    if( !m_TextBrowser )
    {
        m_TextBrowser = new QTextBrowser( ui->widget );
    }
    m_TextBrowser->setHtml( htmlContent );
    ui->verticalLayout_2->addWidget( m_TextBrowser, 1 ); //, Qt::AlignVertical_Mask
    //m_VerticalLayout->addWidget( m_TextBrowser );
    m_TextBrowser->show();
}

void MainWidget::on_AddTextButton_clicked()
{
    m_TextEdit->setGeometry( 100, 100, 800, 600 );
//    if (!m_TextEdit->load("E:\\project\\private\\qtLib\\Introduce\\demo.html"))
    if (!m_TextEdit->load(":/example.html"))
        m_TextEdit->fileNew();

    m_TextEdit->show();
}

void MainWidget::on_AddImagesButton_clicked()
{
    if( !CheckPagePathExist() )
    {
        qDebug( "[%s, %d]: page path is empty", __FUNCTION__, __LINE__ );
        return ;
    }
//    m_VerticalLayout = dynamic_cast<QVBoxLayout *>( ui->stackedWidget->currentWidget()->layout() );
//    qDebug( "layout: %p\n", m_VerticalLayout );
    qDebug() << "m_ApplicationDirPath: " << m_ApplicationDirPath;  // exe file path
    QFileDialog dialog(this);
    dialog.setWindowTitle( tr("Choose Images") );
    QStringList filters;
    filters << "*.png" << "*.jpeg" << "*.bmp" << "*.gif";
    dialog.setNameFilters( filters );
    dialog.setFileMode( QFileDialog::ExistingFiles );
    dialog.setViewMode( QFileDialog::Detail );
    QStringList fileList;
    if( QDialog::Accepted == dialog.exec() )
    {
        fileList = dialog.selectedFiles();
    }
    else // QDialog::Rejected
    {
        return ;
    }

    if( fileList.count() > 0 )  // "C:/Users/Stephen Wei/Desktop/mail.PNG"
    {
        for( auto it: fileList )
        {
            const QString fileName = it.split("/").last();
            QString newfile = ui->pathValueLabel->text() + "/" + fileName;
            if( QFile::copy( it, newfile ) )
            {
                int height = GetAvaliableHeight();
                int width = ui->widget->width();
                AdjustHeights( height );
                QLabel *label = new QLabel( ui->widget );
                m_Labels.push_back( label );
                m_Labels.last()->setParent( ui->widget );
                ui->verticalLayout_2->addWidget( m_Labels.last(), 1 ); //Qt::AlignVertical_Mask

                if( fileName.endsWith(".gif") || fileName.endsWith(".GIF") )
                {
                    QMovie *movie = new QMovie( newfile );
                    movie->setScaledSize( QSize(width, height) );
                    movie->start();
                    label->setMovie( movie );
                    m_Movies.push_back( movie );
                }
                else
                {
                    //label->setPixmap( QPixmap( newfile ) );
    //                label->setMaximumWidth( ui->widget->width() );
    //                label->setMaximumHeight( label->size().height() );
                    label->setPixmap( QPixmap( newfile ).scaled( width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) );
                    label->setScaledContents( true );
                }
                m_ImagesPath.push_back( newfile );
            }
        }
    }
}

void MainWidget::on_AddEntryButton_clicked()
{
    QMap<int, QString> filesMap;
    int countOfWidgets = ui->verticalLayout->count();
    int index = 0;
    for( int i = 0; i < countOfWidgets; ++i )
    {
        QLayoutItem *item = ui->verticalLayout->takeAt( i );
        if( (void *)item == (void *)m_TextBrowser )
        {
            filesMap[i] = m_HtmlPath;
        }
        else {
            filesMap[i] = m_ImagesPath[ index++ ];
        }
    }
    // to do: write json file.
}

void MainWidget::resizeEvent(QResizeEvent *event)
{
    qDebug( "resizeEvent" );
    QWidget::resizeEvent( event );
}
void MainWidget::on_pageFolderButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setWindowTitle( tr("Choose Page Directory") );
    dialog.setFileMode( QFileDialog::DirectoryOnly );
    dialog.setViewMode( QFileDialog::Detail );
    QStringList fileList;
    if( QDialog::Accepted == dialog.exec() )
    {
        fileList = dialog.selectedFiles();
    }
    qDebug() << "on_pageFolderButton_clicked: " << fileList;

    ui->pathValueLabel->setText( fileList[0] );
    m_HtmlPath = fileList[0] + "/introduce.html";
}
