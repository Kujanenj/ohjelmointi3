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

void gameEventHandler::handleMwindowClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager, QMouseEvent event)
{
    if(event.button()==Qt::LeftButton){
        handleLeftClick(scene,manager);
    }
    if(event.button()==Qt::RightButton){
        handleRightClick(manager, scene);
    }
}

void gameEventHandler::handleLeftClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager){
    qDebug()<<"handling mwindow click";
    if(scene->getLastID()!=-1){


        activeTile_= manager->getTile(scene->getLastID());

        if (activeTile_->getWorkers().size()!=0){
            for(auto it: manager->getMinionVector()){

                if(activeTile_->getWorkers().front()==it){
                    activeMinion_=it;
                    qDebug()<<"We got it";
                }

            }
        }


    }
}
void gameEventHandler::handleRightClick(std::shared_ptr<gameManager> manager, std::shared_ptr<GameScene> scene)
{
    std::shared_ptr<Course::TileBase> targetTile=manager->getTile(scene->getLastID());
    if(activeMinion_!=nullptr){
        activeMinion_->currentLocationTile()->removeWorker(activeMinion_);
        activeMinion_->setLocationTile(targetTile);
        activeMinion_->currentLocationTile()->addWorker(activeMinion_);

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
