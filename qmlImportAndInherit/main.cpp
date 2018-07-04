#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType(QUrl(QStringLiteral("qrc:/source/intList.qml")), "Source.Core", 1, 0, "intList");
    qmlRegisterType(QUrl(QStringLiteral("qrc:/source/myItem.qml")), "Source.Core", 1, 0, "myItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/test.qml")));
    return app.exec();
}
