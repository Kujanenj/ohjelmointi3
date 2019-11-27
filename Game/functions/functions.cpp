#include "functions.h"

#include "buildings/magealtar.h"
#include "buildings/rangedaltar.h"
#include "buildings/quarry.h"
#include "buildings/sawmill.h"
#include "buildings/lifepump.h"

#include <vector>
#include <QDebug>
#include <time.h>

#include "handlerandmanager/gamemanager.h"


namespace Whiskas {




void selectBuildingTypef(std::string type,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager,
                        std::shared_ptr<Course::PlayerBase> player)
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
                   std::shared_ptr<Course::PlayerBase> player){
    {
        if(handler->getActiveTile()==nullptr){
            qDebug()<<"error, active tile is a nullptr";
            return false;
        }
        qDebug()<<"Trying to spawn a building pointer in functions";
        std::shared_ptr<CustomBuildingBase> testBuilding = std::make_shared<buildingType>(handler,manager,player);

        qDebug() << QString::fromStdString(testBuilding->getType());
        handler->getActiveTile()->addBuilding(testBuilding);
        manager->addBuilding(testBuilding);
        manager_gamescene->drawItem(testBuilding);
        return true;

    }

}

bool checkBuildingAvailability(std::shared_ptr<Course::TileBase> targetTile, std::string type)
{

 //HANDLER FOR STD OUT OF RANGE?
    for(auto it: buildingAvailability.at(type)){
        if(it==targetTile->getType()){
            qDebug()<<"Legit placement for "<<QString::fromStdString(type);
            return true;
        }
    }
     qDebug()<<"UNLegit placement for "<<QString::fromStdString(type);
     return false;
}

void makeAdvancedWGenerator(int mapsize,
                                std::shared_ptr<gameEventHandler> handler,
                                std::shared_ptr<gameManager> manager)

{

   int ran;
   srand (time(NULL));
    for(int x = 0; x< mapsize; x++){


        for(int y=0; y<mapsize; y++){
            ran=rand()%4;
            Course::Coordinate loc=Course::Coordinate(x,y);
            qDebug()<<"Building coord"<<x<<y;
            if(x!=0 && y!=0){
            for(auto it :loc.neighbours()){
                if(it.x()<=x &&it.y()<=y){
                    qDebug()<<"Checking coor"<<it.x()<<it.y();
                 if(manager->getTile(it)->getType()=="Forest"){
                     ran+=1;
                     break;
                 }
                 if(manager->getTile(it)->getType()=="Spring"){
                     ran-=1;
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
