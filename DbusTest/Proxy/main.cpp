#include <QCoreApplication>
#include "testproxy.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestProxy tProxy;
    return a.exec();
}
