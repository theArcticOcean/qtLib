#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType( QUrl("qrc:/source/MyRectangle.qml"), "Source.Core", 1, 0, "MyRectangle" );
    qmlRegisterType( QUrl("qrc:/source/Ball.qml"), "Source.Core", 1, 0, "Ball" );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
