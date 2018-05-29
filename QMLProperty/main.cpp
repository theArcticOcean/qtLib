#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datasource.h"

// Define the singleton type provider function (callback).
static QObject *singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)    // Q_UNUSED is used to avoid unused warning info
    Q_UNUSED(scriptEngine)

    return new DataSource();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qRegisterMetaType<char *>("const char *");
    qmlRegisterSingletonType<DataSource>( "Wei.Spacing", 1, 0, "DataSource", singletontype_provider );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
