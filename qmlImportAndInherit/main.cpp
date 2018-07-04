#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    int result;
    result =
            qmlRegisterType(QUrl(QStringLiteral("qrc:/source/intList.qml")), "Source.Core", 1, 0, "myItem");
    qDebug() << result;

    result =
            qmlRegisterType(QUrl(QStringLiteral("qrc:/source/intList.qml")), "Source.Core", 1, 0, "intList");
    qDebug() << result;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/test.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/source/myItem.qml")));
    return app.exec();
}
