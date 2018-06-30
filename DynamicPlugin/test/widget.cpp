#include "widget.h"
#include "ui_widget.h"
#include "../plugin/plugin.h"
#include <QPluginLoader>
#include <QDir>
#include <QDebug>

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
    PluginInterface *p_Interface = nullptr;  // Using nullptr avoid compiler converts NULL to 0.
    QString path = QDir::currentPath();
    path = path + "/../plugin/libplugin.dylib";
    qDebug() << path;
    QPluginLoader pluginLoader( path );     // load dynamic file
    QObject *plugin = pluginLoader.instance();
    if(plugin)
    {
        p_Interface = qobject_cast<PluginInterface*>(plugin);
        if(p_Interface)
        {
            p_Interface->SayHello(this);    // call plugin's function.
        }
    }
}
