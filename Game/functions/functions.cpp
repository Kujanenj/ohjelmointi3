#include "functions.h"

#include "buildings/magealtar.h"
#include "buildings/rangedaltar.h"
#include "buildings/quarry.h"
#include "buildings/sawmill.h"
#include "buildings/lifepump.h"

#include <vector>
#include <QDebug>
#include <ctime>

#include "handlerandmanager/gamemanager.h"


namespace Whiskas {




void selectBuildingTypef(const std::string& type,
                        const std::shared_ptr<gameEventHandler>& handler,
                        const std::shared_ptr<gameManager>& manager,
                        const std::shared_ptr<LeaguePlayer>& player)
{


    if(type=="Nexus" && manager->checkBuildingAvailability(handler->getActiveTile(),"Nexus")){
        manager->spawnBuilding<Nexus>(handler,manager,player);
    }
    if(type=="Melee Altar" && manager->checkBuildingAvailability(handler->getActiveTile(),"Melee Altar")){
        manager->spawnBuilding<MeleeAltar>(handler,manager,player);
    }
    if(type=="Ranged Altar" && manager->checkBuildingAvailability(handler->getActiveTile(),"Ranged Altar")){
        manager->spawnBuilding<RangedAltar>(handler,manager,player);
    }
    if(type=="Mage Altar" && manager->checkBuildingAvailability(handler->getActiveTile(),"Mage Altar")){
        manager->spawnBuilding<MageAltar>(handler,manager,player);
    }
    if(type=="Quarry" && manager->checkBuildingAvailability(handler->getActiveTile(),"Quarry")){
        manager->spawnBuilding<Quarry>(handler,manager,player);
    }
    if(type=="Sawmill" && manager->checkBuildingAvailability(handler->getActiveTile(),"Sawmill")){
        manager->spawnBuilding<Sawmill>(handler,manager,player);
    }
    if(type=="Lifepump" && manager->checkBuildingAvailability(handler->getActiveTile(),"Lifepump")){
        manager->spawnBuilding<Lifepump>(handler,manager,player);
    }
}


template<typename buildingType>

bool gameManager::spawnBuilding(std::shared_ptr<gameEventHandler> handler,
                   std::shared_ptr<gameManager> manager,
                   std::shared_ptr<LeaguePlayer> player){
    {
        if(handler->getActiveTile()==nullptr){
            qDebug()<<"error, active tile is a nullptr";
            return false;
        }
        std::shared_ptr<CustomBuildingBase> building = std::make_shared<buildingType>(handler,manager,player);
        if (building->getType() != "Nexus") {
            if(handler->getActiveTile()->getWorkers().empty()) {
                textBrowser->append("You can't build on a minionless tile");
                qDebug()<<"error, active tile has no minion";
                return false;
            }
            if(handler->getActiveTile()->getWorkers().at(0)->getOwner() != player) {
                textBrowser->append("You can't build with an enemy minion");
                qDebug()<<"error, minion isn't yours, hands off";
                return false;
            }
        }
        qDebug()<<"Trying to spawn a building pointer in functions";
        //std::shared_ptr<CustomBuildingBase> testBuilding = std::make_shared<buildingType>(handler,manager,player);
        if(!(handler->subtractPlayerResources(player, building->getAdvancedCost()))){
            textBrowser->append("You don't have enough resources");
            return false; // NOT ENOUGH MONEY
        }
        qDebug() << QString::fromStdString(building->getType());
        handler->getActiveTile()->addBuilding(building);
        manager->addBuilding(building);
        manager_gamescene->drawItem(building);

        textBrowser->append(QString(QString::fromStdString(building->getOwner()->getName()) + " has built a " + QString::fromStdString(building->getType())));
        return true;

    }

}


void makeAdvancedWGenerator(int mapsize,
                                const std::shared_ptr<gameEventHandler>& handler,
                                const std::shared_ptr<gameManager>& manager)

{
   int ran;
   srand (time(nullptr));
    for(int x = 0; x< mapsize; x++){
        for(int y=0; y<mapsize; y++){
            ran=rand()%4;
            Course::Coordinate loc=Course::Coordinate(x,y);
            qDebug()<<"Building coord"<<x<<y;
            if(x!=0 && y!=0){
            for(const auto& it :loc.neighbours()){
                if(it.x()<=x &&it.y()<=y){
                    qDebug()<<"Checking coor"<<it.x()<<it.y();
                 if(manager->getTile(it)->getType()=="Jungle"){
                     ran+=1;
                     break;
                 }
                 if(manager->getTile(it)->getType()=="Spring"){
                     ran-=1;
                     break;

                 }
                }
            }}

            if(ran<=0){
              makeAdvancedWorld<Jungle>(loc,handler,manager);
            }
            if(ran==1){
                makeAdvancedWorld<Mountain>(loc,handler,manager);
            }
            if(ran==2){
                makeAdvancedWorld<Spring>(loc,handler,manager);
            }
            if(ran>=3){
                makeAdvancedWorld<Desert>(loc,handler,manager);
            }

        }
    }

}

template<typename TileType>
void makeAdvancedWorld(Course::Coordinate loc,
                       std::shared_ptr<gameEventHandler> handler,
                       std::shared_ptr<gameManager> manager)
{
    std::shared_ptr<Course::TileBase> testTile=std::make_shared<TileType>(loc,
                                                                          handler,
                                                                          manager);
    qDebug()<<"FOR THE LOVE OF GOD SEE THIS"<<QString::fromStdString(testTile->getType());
    manager->addTile(testTile);

}


}
