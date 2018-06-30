#include "plugin.h"
#include <QMessageBox>

Plugin::Plugin(QObject *parent) : QObject(parent)
{

}

void Plugin::SayHello(QWidget *parent)
{
    QMessageBox::information(parent, "Plugin", "hello, I'm dynamically loaded.");
}
