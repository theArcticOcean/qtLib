#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include "../test/interface.h"

class Plugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "plugin.json")
    Q_INTERFACES(PluginInterface)
public:
    explicit Plugin(QObject *parent = nullptr);
    virtual void SayHello( QWidget *parent ) Q_DECL_OVERRIDE;
signals:

public slots:
};

#endif // PLUGIN_H
