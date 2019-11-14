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
   if(scene->getLastID()!=-1){
    if(event.button()==Qt::LeftButton){
        handleLeftClick(scene,manager);
    }
    if(event.button()==Qt::RightButton){
        handleRightClick(manager, scene);
    }
    return;
   }
   qDebug()<<"Click outside gameArea";
}

void gameEventHandler::handleLeftClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager){
    qDebug()<<"handling mwindow click";



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
void gameEventHandler::handleRightClick(std::shared_ptr<gameManager> manager, std::shared_ptr<GameScene> scene)
{
    std::shared_ptr<Course::TileBase> targetTile=manager->getTile(scene->getLastID());
    if(activeMinion_!=nullptr && targetTile->getWorkerCount()==0){
        activeMinion_->currentLocationTile()->removeWorker(activeMinion_);
        activeMinion_->setLocationTile(targetTile);
        activeMinion_->currentLocationTile()->addWorker(activeMinion_);

    }
    else{
        qDebug()<<"Active minion was null ptr or target tile contains a minion";

    }
}

std::shared_ptr<Course::TileBase> gameEventHandler::getActiveTile(){
    return activeTile_;

}



