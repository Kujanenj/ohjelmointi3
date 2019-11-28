#include <QtTest>


//#include "handlerandmanager/gamemanager.h"
//#include "graphics/gamescene.h"

//using namespace Whiskas;
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
    //std::shared_ptr<gameManager> manager = std::make_shared<gameManager>(nullptr);
}

QTEST_APPLESS_MAIN(testManager)

#include "tst_testmanager.moc"
