#include <QString>
#include <QtTest>

class String : public QObject
{
    Q_OBJECT

public:
    String();

private Q_SLOTS:
    void toUpper_data();
    void toUpper();
};

String::String()
{
}

void String::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void String::toUpper()
{
    QFETCH(QString, string);    // take data from table
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

QTEST_APPLESS_MAIN(String)

#include "tst_string.moc"   // compiled from tst_string.cpp by Meta-Object Compiler
