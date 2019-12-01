#include "managertest.h"

ManagerTest::ManagerTest(QObject *parent) : QObject(parent)
{

}

void ManagerTest::simpleTest()
{
    std::string testString="TESTI";
    QCOMPARE(testString,std::string("TESTI"));
}
