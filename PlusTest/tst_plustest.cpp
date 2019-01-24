#include <QtTest>
#include <QDebug>

// add necessary includes here

class PlusTest : public QObject
{
    Q_OBJECT

public:
    PlusTest();
    ~PlusTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void TestCases_data();
    void TestCases();
};

PlusTest::PlusTest()
{

}

PlusTest::~PlusTest()
{

}

void PlusTest::initTestCase()
{

}

void PlusTest::cleanupTestCase()
{

}

void PlusTest::TestCases_data()
{
    QTest::addColumn<int>("number1");
    QTest::addColumn<int>("number2");
    QTest::addColumn<int>("result");

    QTest::newRow("test1") << 1 << 1 << 2;
    QTest::newRow("test2") << 2 << 2 << 4;
    QTest::newRow("test3") << 1 << 2 << 3;
}

void PlusTest::TestCases()
{
    QFETCH(int, number1);    // take data from table
    QFETCH(int, number2);
    QFETCH(int, result);

    QCOMPARE(number1+number2, result);
}

QTEST_APPLESS_MAIN(PlusTest)

#include "tst_plustest.moc"
