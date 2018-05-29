#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "brightness.h"

// Define the singleton type provider function (callback).
static QObject *singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

//    BrightNess *ins = new BrightNess();
//    return ins;
    return BrightNess::getInstance();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterSingletonType<BrightNess>("Qt.example.brightNess", 1, 0, "BrightNess", singletontype_provider);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
