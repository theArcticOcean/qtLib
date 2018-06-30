#include "widget.h"
#include <QApplication>
#include <QtPlugin>

Q_IMPORT_PLUGIN(Plugin) //we need to import static library.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
