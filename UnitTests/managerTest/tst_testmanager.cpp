#include <QtTest>




//using namespace Whiskas;
// add necessary includes here
#include "handlerandmanager/gamemanager.h"
#include "buildings/lifepump.h"
#include "buildings/nexus.h"

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

class testManager : public QObject
{
    Q_OBJECT

public:
    testManager();
    ~testManager();

private slots:
    void test_addTile();
    void test_getTile();
    void test_spawnMinion();
    void test_move_basic();
    void test_move_TooFar();
    void test_attack();
    void test_checkForEnemies();
    void test_move_attack();
    void test_selectAttackTarget_Minion();
    void test_DestroyObject();
    void test_spawnBuilding();
    void test_selectAttackTarget_Building();
    void test_destroyBuilding();
    void test_addPlayers();
    void test_destroyNexus();
    void test_attackMultipleFullDamage();
    void test_attackMultipleEdge();

private:
    std::shared_ptr<GameScene>scene=nullptr;
    std::shared_ptr<QTextBrowser> textBrowser=nullptr;
    std::shared_ptr<gameManager> manager=std::make_shared<gameManager>(scene, textBrowser);
    std::shared_ptr<Turn> turn=std::make_shared<Turn>(manager);
    std::shared_ptr<gameEventHandler> handler = std::make_shared<gameEventHandler>(turn, textBrowser);
    std::shared_ptr<LeaguePlayer> player= std::make_shared<LeaguePlayer>("player1");
    std::shared_ptr<LeaguePlayer> player2= std::make_shared<LeaguePlayer>("player2");




};



testManager::testManager()
{

}

testManager::~testManager()
{

}

void testManager::test_addTile()
{
    Course::Coordinate loc=Course::Coordinate(0,0);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->addTile(tile);
    QVERIFY(manager->getTileVector().size()==1);

}
void testManager::test_getTile(){
    Course::Coordinate loc=Course::Coordinate(1,0);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->addTile(tile);
    qDebug()<<manager->getTileVector().size();
    QVERIFY(tile==manager->getTile(loc));
}
void testManager::test_spawnMinion(){
    manager->spawnMinion(handler,manager,player,manager->getTileVector().front(),"minion");
    QVERIFY(manager->getMinionVector().front()->getType()=="Minion");
}
void testManager::test_move_basic(){
    manager->move(manager->getMinionVector().front(),manager->getTileVector().at(1));
    QVERIFY(manager->getMinionVector().front()->currentLocationTile()==manager->getTileVector().at(1));

}
void testManager::test_move_TooFar(){
    Course::Coordinate loc=Course::Coordinate(3,0);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->getMinionVector().front()->setMoved(false);
    manager->move(manager->getMinionVector().front(),tile);
     QVERIFY(manager->getMinionVector().front()->currentLocationTile()==manager->getTileVector().at(1));
}
void testManager::test_attack(){
    manager->spawnMinion(handler,manager,player2,manager->getTileVector().front(),"minion");
    manager->attack(manager->getMinionVector().front(),manager->getMinionVector().at(1));
    QVERIFY(manager->getMinionVector().at(1)->getHealth()==2);
}
void testManager::test_checkForEnemies(){
    QVERIFY(manager->checkForEnemies(manager->
                                      getMinionVector().at(0),manager->
                                      getTileVector().front())==true);

}
void testManager::test_move_attack(){
   manager->getMinionVector().at(0)->setAttacked(false);
     manager->move(manager->getMinionVector().at(0),manager->
                   getTileVector().front());
     QVERIFY(manager->getMinionVector().at(1)->getHealth()==1);
}
void testManager::test_selectAttackTarget_Minion(){
    QVERIFY(manager->selectAttackTarget(manager->getTileVector().at(0))->getBoundID()==manager->getMinionVector()
             .at(1)->ID);
}
void testManager::test_DestroyObject(){
    manager->destroyObject(manager->getMinionVector()
                           .at(1));
    QVERIFY(manager->getMinionVector().size()==1);

}
void testManager::test_spawnBuilding(){
    AdvancedResourceMap infinite={
        {IRON, 1000},
        {WOOD, 1000},
        {CRYSTAL,1000},
        {LIFEWATER,1000}
    };
    player2->setPlayerItems(infinite);
    handler->setActiveTile(manager->getTileVector().front());
    manager->spawnBuilding<Lifepump>(handler,manager,player2);
    QVERIFY(manager->getBuildingVector().size()==1);
}
void testManager::test_selectAttackTarget_Building(){
    QVERIFY(manager->selectAttackTarget(manager->getTileVector().at(0))->getBoundID()==manager->getBuildingVector()
                 .at(0)->ID);
}
void testManager::test_destroyBuilding(){
    manager->destroyObject(manager->getBuildingVector().front());
    QVERIFY(manager->getBuildingVector().size()==0);
}
void testManager::test_addPlayers(){
    std::pair<std::shared_ptr<LeaguePlayer>, std::shared_ptr<LeaguePlayer>> playerpair(player,player2);
    manager->addPlayer(playerpair);
    QVERIFY(manager->getPlayerPair().first->getName()=="player1");
}
void testManager::test_destroyNexus(){
    manager->spawnBuilding<Nexus>(handler,manager,player2);
    manager->destroyObject(manager->getBuildingVector().front());
    QVERIFY(manager->getWinner()==manager->getPlayerPair().first);
}
void testManager::test_attackMultipleFullDamage(){
    for(int x=2;x<5;x++){
        for(int y=0;y<3;y++){
            Course::Coordinate loc=Course::Coordinate(x,y);
            std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
            manager->addTile(tile);
            manager->spawnMinion(handler,manager,player,tile,"minion");

        }
    }
     Course::Coordinate loc=Course::Coordinate(3,3);
     std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
     manager->addTile(tile);
     manager->spawnMinion(handler,manager,player,tile,"mage");
     Course::Coordinate target=Course::Coordinate(3,1);
     manager->attackMultiple(manager->getMinionVector().at(10),manager->getTile(target));
     QVERIFY(manager->getMinionVector().size()==3);


}
void testManager::test_attackMultipleEdge(){
    for(int x=10;x<12;x++){

            Course::Coordinate loc=Course::Coordinate(x,10);
            std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
            manager->addTile(tile);
            manager->spawnMinion(handler,manager,player,tile,"minion");
    }

    Course::Coordinate loc=Course::Coordinate(13,10);
    std::shared_ptr<Course::TileBase>tile=std::make_shared<Course::TileBase>(loc,handler,manager);
    manager->addTile(tile);
    manager->spawnMinion(handler,manager,player,tile,"mage");
    Course::Coordinate target=Course::Coordinate(11,10);
    manager->attackMultiple(manager->getMinionVector().at(5),manager->getTile(target));
    QVERIFY(manager->getMinionVector().size()==5);
}
QTEST_APPLESS_MAIN(testManager)

#include "tst_testmanager.moc"
