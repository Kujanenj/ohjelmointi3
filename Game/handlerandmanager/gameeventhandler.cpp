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

            qDebug()<<scene->getLastID();

        manager->getTile(scene->getLastID());
    }
}

