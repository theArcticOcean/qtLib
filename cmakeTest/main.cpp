#include <iostream>
#include <QApplication>

#include "mainwindow.h"
using namespace std;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );
    MainWindow win;
    win.show();
    return app.exec();
}
