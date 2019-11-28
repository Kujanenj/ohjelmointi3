#include <QtTest>




//using namespace Whiskas;
// add necessary includes here
#include "handlerandmanager/gamemanager.h"

using namespace Whiskas;
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
    std::shared_ptr<GameScene>scene=nullptr;
    std::shared_ptr<gameManager> manager=std::make_shared<gameManager>(scene);
    std::shared_ptr<Turn> turn=std::make_shared<Turn>(manager);
    std::shared_ptr<gameEventHandler> handler = std::make_shared<gameEventHandler>(turn);
    Course::Coordinate loc=Course::Coordinate(0,0);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->addTile(tile);
    QCOMPARE(manager->getTileVector().size(),1);
    //std::shared_ptr<gameManager> manager = std::make_shared<gameManager>(nullptr);
}

QTEST_APPLESS_MAIN(testManager)

#include "tst_testmanager.moc"
