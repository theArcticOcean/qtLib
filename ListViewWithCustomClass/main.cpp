#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "myclass.h"
#include "mydata.h"
#include "objectlistmodelt.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<MyClass>("Union.Lotto.MyClass", 1, 0, "MyClass");
    //qmlRegisterType<MyData>("Union.Lotto.MyClass", 1, 0, "MyData");
    //qmlRegisterType< ObjectListModelT<MyData*> >("Union.Lotto.MyClass", 1, 0, "ObjectListModelT<MyData*>");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QString str = "hello";
    str.toStdString().c_str();
    return app.exec();
}
