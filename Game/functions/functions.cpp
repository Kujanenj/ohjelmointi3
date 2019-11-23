#include "functions.h"

#include "buildings/farm.h"
#include <vector>
#include <QDebug>

#include "handlerandmanager/gamemanager.h"

namespace Whiskas {

void makeWorldGenerator(int mapsize_x, int mapsize_y, int seed,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager){

    Course::WorldGenerator& wgenerator=Course::WorldGenerator::getInstance();
    wgenerator.addConstructor<Course::Forest>(10);
    wgenerator.addConstructor<Course::Grassland>(10);
    wgenerator.generateMap(mapsize_x,mapsize_y,seed,manager,handler);

}





void selectBuildingTypef(std::string type,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager,
                        std::shared_ptr<Course::PlayerBase> player)
{


    if(type=="Nexus" && checkBuildingAvailability(handler->getActiveTile(),"Nexus")){
        manager->spawnBuilding<Nexus>(handler,manager,player);
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


}
