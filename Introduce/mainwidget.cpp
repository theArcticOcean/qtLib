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

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    m_ApplicationPtr( nullptr ),
    m_TextBrowser( nullptr ),
    m_Splitter( nullptr )
{
    ui->setupUi(this);
    while( ui->stackedWidget->count() > 0 )
    {
        QWidget *widget = ui->stackedWidget->widget( ui->stackedWidget->count() - 1 );
        ui->stackedWidget->removeWidget( widget );
        if( widget )
        {
            delete widget;
            widget = nullptr;
        }
    }
    m_StackPageIndex = -1;

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

void MainWidget::CheckLayoutInWidget()
{
    if( nullptr == ui->stackedWidget->currentWidget()->layout() )
    {
        QWidget * widget = ui->stackedWidget->currentWidget();
        QVBoxLayout *verticalLayout = new QVBoxLayout( widget );
    }
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

void MainWidget::RefreshStackPageLayout()
{
    int count = m_Splitter->count();
    QList<int> sizes;
    for( int i = 0; i < count; ++i )
    {
        sizes << 1; //INT_MAX;
    }
    m_Splitter->setSizes( sizes );
    m_Splitter->repaint();
}

int MainWidget::GetAvaliableHeightInCenterPage()
{
    int height = ui->stackedWidget->currentWidget()->height();
    int elementCount = 0;
    if( m_TextBrowser )
    {
        elementCount++;
    }
    elementCount = elementCount + m_Labels.size();
    height = height * 1.0 / ( elementCount + 1);
    qDebug( "GetAvaliableHeightInCenterPage height: %d", height );
    return height;
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

void MainWidget::on_textEditClosed()
{
    //CheckLayoutInWidget();
    QString htmlContent = m_TextEdit->textEdit->toHtml();
    int validHeight = GetAvaliableHeightInCenterPage();
    AdjustHeights( validHeight );
    if( !m_TextBrowser )
    {
        m_TextBrowser = new QTextBrowser(this);
    }
    m_TextBrowser->setHtml( htmlContent );
    m_Splitter->addWidget( m_TextBrowser );
    m_TextBrowser->setMaximumWidth( ui->stackedWidget->currentWidget()->width() );
    m_TextBrowser->setMaximumHeight( validHeight );
    //m_VerticalLayout->addWidget( m_TextBrowser );
    m_TextBrowser->show();
    RefreshStackPageLayout();
}

void MainWidget::on_AddTextButton_clicked()
{
    if( ui->stackedWidget->count() < 1 )
    {
        qDebug( "%s, %d: here is nullptr", __FUNCTION__, __LINE__  );
        return ;
    }

    m_TextEdit->setGeometry( 100, 100, 800, 600 );
//    if (!m_TextEdit->load("E:\\project\\private\\qtLib\\Introduce\\demo.html"))
    if (!m_TextEdit->load(":/example.html"))
        m_TextEdit->fileNew();

    m_TextEdit->show();
}

void MainWidget::on_AddImagesButton_clicked()
{
    if( ui->stackedWidget->count() < 1 )
    {
        qDebug( "%s, %d: here is nullptr", __FUNCTION__, __LINE__  );
        return ;
    }

    //CheckLayoutInWidget();
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

    if( fileList.count() > 0 && m_Splitter )  // "C:/Users/Stephen Wei/Desktop/mail.PNG"
    {
        for( auto it: fileList )
        {
            const QString fileName = it.split("/").last();
            QString newfile = m_ApplicationDirPath + "/" + fileName;
            QFile::copy( it, newfile );
            QLabel *label = new QLabel( ui->stackedWidget->currentWidget() );
            label->setMaximumWidth( ui->stackedWidget->currentWidget()->width() );
            int avaliableHeight = GetAvaliableHeightInCenterPage();
            label->setMaximumHeight( avaliableHeight );
            AdjustHeights( avaliableHeight );
            m_Labels.push_back( label );
            m_Splitter->addWidget( m_Labels.last() );

            if( fileName.endsWith(".gif") || fileName.endsWith(".GIF") )
            {
                QMovie *movie = new QMovie( newfile );
                movie->start();
                label->setMovie( movie );
                m_Movies.push_back( movie );
                movie->setScaledSize( m_Labels.last()->size() );
            }
            else
            {
                label->setPixmap( QPixmap( newfile ) );
                //label->setPixmap( QPixmap( newfile ).scaled( label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) );
                label->setScaledContents( true );
            }
        }
        RefreshStackPageLayout();
    }
}

void MainWidget::on_AddEntryButton_clicked()
{
//    QMainWindow *newWindow = new QMainWindow( ui->stackedWidget );
    m_Splitter = new QSplitter();
    ui->stackedWidget->addWidget( m_Splitter );
    m_Splitter->setOrientation( Qt::Vertical );
    //m_Splitter->setOpaqueResize( false );
    //newWindow->setCentralWidget( m_Splitter );

    connect( m_Splitter, SIGNAL( splitterMoved(int, int) ), this, SLOT(onSplitterMoved(int, int)) );
}

void MainWidget::onSplitterMoved(int pos, int index)
{
    qDebug( "onSplitterMoved pos: %d, index: %d", pos, index );
    int elementCount = 0;
    if( m_TextBrowser )
    {
        elementCount++;
    }
    elementCount = elementCount + m_Labels.size();
    int height = height * 1.0 / elementCount;
    //AdjustHeights( height );
}
