#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splitter = new QSplitter( this );
    //splitter->setSizePolicy( QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum) );
    m_Label = new QLabel( "hello", this );
    m_Label->setStyleSheet( "background-color: red" );
    m_Label1 = new QLabel( "hello", this );
    m_Label1->setStyleSheet( "background-color: black" );
    m_Label2 = new QLabel( "hello", this );

    splitter->addWidget(m_Label);
    splitter->addWidget(m_Label1);
    splitter->addWidget(m_Label2);

    splitter->setSizes(QList<int>({1, 1, 1}));
    splitter->setOrientation( Qt::Vertical );

    splitter->show();
    setCentralWidget( splitter );

    connect( splitter, SIGNAL( splitterMoved(int, int) ), this, SLOT(onSplitterMoved(int, int)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSplitterMoved(int pos, int index)
{
    qDebug( "pos: %d, index: %d", pos, index );
}
