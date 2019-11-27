#include <QtTest>

#include "handlerandmanager/gamemanager.h"
// add necessary includes here

class testManager : public QObject
{
    Q_OBJECT

public:
    testManager();
    ~testManager();

private slots:
    void test_case1();

};

testManager::testManager()
{

}

testManager::~testManager()
{

}

void testManager::test_case1()
{

}

QTEST_APPLESS_MAIN(testManager)

#include "tst_testmanager.moc"
