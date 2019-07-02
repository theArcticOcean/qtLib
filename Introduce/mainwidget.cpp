#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "textedit.h"

#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    m_ApplicationPtr( nullptr )
{
    ui->setupUi(this);
    m_TextEdit = new TextEdit(this);
    m_TextEdit->hide();
    m_TextBrowser = new QTextBrowser(this);
    m_TextBrowser->hide();

    connect( m_TextEdit, SIGNAL(closed()), this, SLOT(on_textEditClosed()) );
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::FetchApplicationPtr(QApplication *app)
{
    m_ApplicationPtr = app;
}

void MainWidget::on_pushButton_clicked()
{
    m_TextEdit->setGeometry( 100, 100, 800, 600 );
//    if (!m_TextEdit->load("E:\\project\\private\\qtLib\\Introduce\\demo.html"))
    if (!m_TextEdit->load(":/example.html"))
        m_TextEdit->fileNew();

    m_TextEdit->show();
}

void MainWidget::on_textEditClosed()
{
    qDebug() << "on_textEditClosed";
    QString htmlContent = m_TextEdit->textEdit->toHtml();
    m_TextBrowser->setHtml( htmlContent );
    QWidget * widget = ui->stackedWidget->currentWidget();
    QVBoxLayout *verticalLayout = new QVBoxLayout( widget );
    verticalLayout->addWidget( m_TextBrowser, 1 );
    m_TextBrowser->show();
}
