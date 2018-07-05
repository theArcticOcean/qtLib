#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "buttonbase.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ButtonBase>( "Share.core", 1, 0, "ButtonBase" );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
