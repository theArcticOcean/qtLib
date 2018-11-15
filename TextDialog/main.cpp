#include "textdialog.h"
#include <QApplication>

#include "textandnumber.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<TextAndNumber>("TextAndNumber");

    QApplication a(argc, argv);
    TextDialog w;
    w.show();

    return a.exec();
}
