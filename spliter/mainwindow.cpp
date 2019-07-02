#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splitter = new QSplitter( this );
    //splitter->setSizePolicy( QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum) );
    m_Label = new QLabel( this );
    m_Label1 = new QLabel( this );
    m_Label2 = new QLabel( this );

    splitter->addWidget(m_Label);
    splitter->addWidget(m_Label1);
    splitter->addWidget(m_Label2);

    splitter->setSizes(QList<int>({1, 1, 1}));
    splitter->setOrientation( Qt::Vertical );

    splitter->show();
    setCentralWidget( splitter );
}

MainWindow::~MainWindow()
{
    delete ui;
}
