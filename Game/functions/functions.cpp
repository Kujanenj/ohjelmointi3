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


    if(type=="Nexus" && checkBuildingAvailability(handler->getActiveTile(),"Nexus")){
        manager->spawnBuilding<Nexus>(handler,manager,player);
    }
    if(type=="Melee Altar" && checkBuildingAvailability(handler->getActiveTile(),"Melee Altar")){
        manager->spawnBuilding<MeleeAltar>(handler,manager,player);
    }
    if(type=="Ranged Altar" && checkBuildingAvailability(handler->getActiveTile(),"Ranged Altar")){
        manager->spawnBuilding<RangedAltar>(handler,manager,player);
    }
    if(type=="Mage Altar" && checkBuildingAvailability(handler->getActiveTile(),"Mage Altar")){
        manager->spawnBuilding<MageAltar>(handler,manager,player);
    }
    if(type=="Quarry" && checkBuildingAvailability(handler->getActiveTile(),"Quarry")){
        manager->spawnBuilding<Quarry>(handler,manager,player);
    }
    if(type=="Sawmill" && checkBuildingAvailability(handler->getActiveTile(),"Sawmill")){
        manager->spawnBuilding<Sawmill>(handler,manager,player);
    }
    if(type=="Lifepump" && checkBuildingAvailability(handler->getActiveTile(),"Lifepump")){
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
                qDebug()<<"error, active tile has no minion";
                return false;
            }
            if(handler->getActiveTile()->getWorkers().at(0)->getOwner() != player) {
                qDebug()<<"error, minion isn't yours, hands off";
                return false;
            }
        }
        qDebug()<<"Trying to spawn a building pointer in functions";
        //std::shared_ptr<CustomBuildingBase> testBuilding = std::make_shared<buildingType>(handler,manager,player);
        if(!(handler->subtractPlayerResources(player, building->getAdvancedCost()))){
            return false; // NOT ENOUGH MONEY
        }
        qDebug() << QString::fromStdString(building->getType());
        handler->getActiveTile()->addBuilding(building);
        manager->addBuilding(building);
        manager_gamescene->drawItem(building);
        return true;

    }

}

bool checkBuildingAvailability(const std::shared_ptr<Course::TileBase> &targetTile, const std::string &type)
{

 //HANDLER FOR STD OUT OF RANGE?
    if(targetTile->getBuildingCount()!=0){
        return false;
    }
    for(const auto& it: buildingAvailability.at(type)){
        if(it==targetTile->getType()){
            qDebug()<<"Legit placement for "<<QString::fromStdString(type);
            return true;
        }
    }
     qDebug()<<"UNLegit placement for "<<QString::fromStdString(type);
     return false;
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
