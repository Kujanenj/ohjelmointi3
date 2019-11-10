#include "gameeventhandler.h"

gameEventHandler::gameEventHandler()
{

}

bool gameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    return true;
}

bool gameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{
    return true;
}

void gameEventHandler::handleMwindowClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager){
    if(scene->getLastID()!=-1){



        activeTile= manager->getTile(scene->getLastID());
    }
}

std::shared_ptr<Course::TileBase> gameEventHandler::getActiveTile(){
    return activeTile;

}

bool gameEventHandler::spawnBuilding(std::shared_ptr<Course::BuildingBase> building,
                                     std::shared_ptr<gameManager> manager)
{
    if(activeTile==nullptr){
        qDebug()<<"error, active tile is a nullptr";
        return false;
    }
    activeTile->addBuilding(building);
    activeTile->getBuildings();
    manager->addBuilding(building);

    return true;
}
