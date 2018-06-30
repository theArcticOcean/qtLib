#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

class PluginInterface
{
public:
    virtual void SayHello( QWidget *parent ) = 0;
};

// The class which contains Q_PLUGIN_METADATA must be created defaultly.

#define PluginInterface_iid "qt.dynamic.plugin"

Q_DECLARE_INTERFACE( PluginInterface, PluginInterface_iid )

#endif // INTERFACE_H
