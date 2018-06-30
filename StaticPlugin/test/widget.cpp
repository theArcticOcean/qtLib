#include "widget.h"
#include "ui_widget.h"
#include "../plugin/plugin.h"
#include <QPluginLoader>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    PluginInterface *p_PluginInterface = nullptr;
    //QPluginLoader::staticInstances Returns a list of static plugin instances
    foreach (QObject *plugin, QPluginLoader::staticInstances()) {
        p_PluginInterface = qobject_cast<PluginInterface*>(plugin);  // PluginInterface is what we need.
        qDebug( "p_PluginInterface: %p\n", p_PluginInterface );
        if( p_PluginInterface )
        {
            p_PluginInterface->SayHello(this);
        }
    }
}
