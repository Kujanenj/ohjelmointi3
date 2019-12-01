#include <QtTest>
#include "handlerandmanager/gameeventhandler.h"
#include "buildings/nexus.h"
#include "buildings/lifepump.h"
#include "buildings/meleealtar.h"
// add necessary includes here
using namespace Whiskas;

template<typename buildingType>

bool gameManager::spawnBuilding(std::shared_ptr<gameEventHandler> handler,
                   std::shared_ptr<gameManager> manager,
                   std::shared_ptr<LeaguePlayer> player){
    {
        if(handler->getActiveTile()==nullptr){
            qDebug()<<"error, active tile is a nullptr";
            return false;
        }
        qDebug()<<"Trying to spawn a building pointer in functions";
        std::shared_ptr<CustomBuildingBase> Building = std::make_shared<buildingType>(handler,manager,player);
        if(!(handler->subtractPlayerResources(player,Building->getAdvancedCost()))){
            return false; // NOT ENOUGH MONEY

        }
        qDebug() << QString::fromStdString(Building->getType());
        handler->getActiveTile()->addBuilding(Building);
        manager->addBuilding(Building);
        if(manager_gamescene!=nullptr){
        manager_gamescene->drawItem(Building);}
        return true;

    }

}

class testHandler : public QObject
{
    Q_OBJECT

public:
    testHandler();
    ~testHandler();

private slots:
    void test_subtractAdvanced();
    void test_endTurn();
    void test_Subtract_noMoney();
    void test_upgradeMinion();
private:
    std::shared_ptr<GameScene>scene=nullptr;
    std::shared_ptr<QTextBrowser> textBrowser=nullptr;
    std::shared_ptr<gameManager> manager=std::make_shared<gameManager>(scene, textBrowser);
    std::shared_ptr<Turn> turn=std::make_shared<Turn>(manager);
    std::shared_ptr<gameEventHandler> handler = std::make_shared<gameEventHandler>(turn, textBrowser);
    std::shared_ptr<LeaguePlayer> player= std::make_shared<LeaguePlayer>("player1");
    std::shared_ptr<LeaguePlayer> player2= std::make_shared<LeaguePlayer>("player2");

};

testHandler::testHandler()
{

}

testHandler::~testHandler()
{

}

void testHandler::test_subtractAdvanced()
{
    AdvancedResourceMap finite={
        {IRON, 10},
        {WOOD, 10},
        {CRYSTAL,10},
        {LIFEWATER,10}
    };
    player2->setPlayerItems(finite);
    handler->subtractPlayerResources(player2,finite);
    QCOMPARE(player2->getItems()[IRON],0);

}
void testHandler::test_endTurn(){
    AdvancedResourceMap infinite={
        {IRON, 1000},
        {WOOD, 1000},
        {CRYSTAL,1000},
        {LIFEWATER,1000}
    };
    std::pair<std::shared_ptr<LeaguePlayer>, std::shared_ptr<LeaguePlayer>> playerpair(player,player2);
    manager->addPlayer(playerpair);
    player2->setPlayerItems(infinite);
    Course::Coordinate loc=Course::Coordinate(0,0);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->addTile(tile);
    handler->setActiveTile(manager->getTileVector().front());
    manager->spawnBuilding<Nexus>(handler,manager,player2);

    player->setPlayerItems(infinite);
    Course::Coordinate loc2=Course::Coordinate(1,1);
    std::shared_ptr<Course::TileBase>tile2=std::make_shared<Course::TileBase>(loc2,handler,manager);
    manager->addTile(tile2);
    handler->setActiveTile(manager->getTileVector().at(1));
    manager->spawnBuilding<Nexus>(handler,manager,player);

    handler->getTurn()->setInTurn(player);
    handler->endTurn(manager,handler);
    QCOMPARE(manager->getMinionVector().size(),2);
    QCOMPARE(handler->getTurn()->getInTurn(),player2);
}
void testHandler::test_Subtract_noMoney(){
    AdvancedResourceMap null={
        {IRON, 0},
        {WOOD, 0},
        {CRYSTAL,0},
        {LIFEWATER,0}
    };
    player->setPlayerItems(null);
    QCOMPARE(handler->subtractPlayerResources(player,LIFEPUMP_COST),false);
    QCOMPARE(player->getItems(),null);
}
void testHandler::test_upgradeMinion(){
    Course::Coordinate loc=Course::Coordinate(5,5);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->addTile(tile);
    handler->setActiveTile(manager->getTileVector().at(2));
    manager->spawnBuilding<MeleeAltar>(handler,manager,player2);
    manager->spawnMinion(handler,manager,player2,handler->getActiveTile(),"minion");
    handler->endTurn(manager,handler);
    QCOMPARE(manager->getMinionVector().back()->getType(),"MeleeChampion");
}
QTEST_APPLESS_MAIN(testHandler)

#include "tst_testhandler.moc"
