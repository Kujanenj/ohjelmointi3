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
    qDebug()<<"handling mwindow click";
    if(scene->getLastID()!=-1){


        activeTile_= manager->getTile(scene->getLastID());

        if (manager->getMinionVector().size()!=0){

            for(auto it: manager->getMinionVector()){
             qDebug()<<it->ID<<"minion ID";
             qDebug()<<it->currentLocationTile()->ID<<"minion tile";
             qDebug()<<activeTile_->ID<<"Comparing to this";
                if(it->currentLocationTile()==activeTile_){
                    activeMinion_=it;
                    qDebug()<<"match found";
                    break;

                }
                qDebug()<<"none of the minions are on this tile";
            }
        }
        qDebug()<<"activeminion is nullptr";
    }
}

std::shared_ptr<Course::TileBase> gameEventHandler::getActiveTile(){
    return activeTile_;

}



bool gameEventHandler::spawnBuilding(std::shared_ptr<Course::BuildingBase> building,
                                     std::shared_ptr<gameManager> manager)
{
    if(activeTile_==nullptr){
        qDebug()<<"error, active tile is a nullptr";
        return false;
    }
    activeTile_->addBuilding(building);

    manager->addBuilding(building);

    return true;
}
