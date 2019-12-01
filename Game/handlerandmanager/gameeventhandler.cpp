#include "gameeventhandler.h"

namespace Whiskas {

gameEventHandler::gameEventHandler(std::shared_ptr<Turn> turn, std::shared_ptr<QTextBrowser> textBrowserRight):
    turn_(turn),
    textBrowserRight(textBrowserRight)
{
qDebug()<<"new event handler";
//turn_=turn;
}

bool gameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    return true;
}



bool gameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{
    return true;
}

bool gameEventHandler::subtractPlayerResources(const std::shared_ptr<LeaguePlayer>& player,AdvancedResourceMap costs)
{
    AdvancedResourceMap TempMap=player->getItems();
    for(auto & cost : costs){
        auto ToModify=TempMap.find(cost.first);
        if(ToModify!=TempMap.end()){
            if(ToModify->second<cost.second){
                qDebug()<<"Not enough dough";
                return false;
            }
            ToModify->second-=cost.second;
        }
        else{
            qDebug()<<"Required resource nto found";
            return false;
        }

    }
    player->setPlayerItems(TempMap);
    return true;
}

void gameEventHandler::handleMwindowClick(const std::shared_ptr<GameScene>& scene, const std::shared_ptr<gameManager>& manager, const QMouseEvent& event)
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

void gameEventHandler::handleLeftClick(const std::shared_ptr<GameScene>& scene,
                                       const std::shared_ptr<gameManager>& manager){
        textBrowserRight->clear();
        activeTile_ = manager->getTile(*scene->getLastCoordinate());

        textBrowserRight->append(QString(
               "Coordinates \n X:" + QString::number(activeTile_->getCoordinatePtr()->x())
              + "  Y: " + QString::number(activeTile_->getCoordinatePtr()->y())));

        // Figuring out the active minion
        // And printing out clicked minion information
        if (!activeTile_->getWorkers().empty()){
            for(const auto& it: manager->getMinionVector()){
                if(activeTile_->getWorkers().front()==it){

                    textBrowserRight->append(QString(
                           "\nMinion \n   HP:"
                           + QString::number(it->getHealth())
                          + "\n   Type:" + QString::fromStdString(it->getType())));

                    if (it->getOwner()==turn_->getInTurn()) {
                        activeMinion_=it;
                    }
                }
            }
        }
        else{
            activeMinion_=nullptr;
        }

        // Printing out building information
        if (!activeTile_->getBuildings().empty()){
            for(const auto& it: manager->getBuildingVector()){
                if(activeTile_->getBuildings().front()==it){
                    textBrowserRight->append(QString("\n" +
                           QString::fromStdString(it->getType()) + "\n   HP:"
                           + QString::number(it->getHealth())));
                    if (it->getType() == "Mage Altar" || it->getType() == "Melee Altar"
                            || it->getType() == "Ranged Altar"){
                        int cooldown = it->getCooldown();
                        if (cooldown < 0) {
                            cooldown = 0;
                        }
                        textBrowserRight->append(QString("\n" +
                               QString::fromStdString(it->getType()) + "\n   Cooldown:"
                               + QString::number(cooldown)));
                    }
                }
            }
        }
}

void gameEventHandler::handleRightClick(const std::shared_ptr<gameManager>& manager, const std::shared_ptr<GameScene>& scene)
{
    std::shared_ptr<Course::TileBase> targetTile=manager->getTile(*scene->getLastCoordinate());
    if(activeMinion_!=nullptr){
        manager->move(activeMinion_,targetTile);
    }
}

std::shared_ptr<Course::TileBase> gameEventHandler::getActiveTile(){
    return activeTile_;

}

void gameEventHandler::setActiveTile(std::shared_ptr<Course::TileBase> activeTile)
{
    activeTile_=std::move(activeTile);
}

std::shared_ptr<Minion> gameEventHandler::getActiveMinion()
{
    return activeMinion_;
}

std::shared_ptr<Turn> gameEventHandler::getTurn()
{
    return turn_;
}

void gameEventHandler::endTurn(const std::shared_ptr<gameManager>& manager, const std::shared_ptr<gameEventHandler>& handler)
{

 turn_->swapTurn();
 qDebug()<<turn_->getTurnCounter()<<"TURN COUNTER";
 if(turn_->getTurnCounter()==1||turn_->getTurnCounter() % 4==0){
     std::shared_ptr<Course::TileBase> nexsusLoc;
     nexsusLoc=manager->getNexusLocation(manager->getPlayerPair().first);
     if(nexsusLoc!=nullptr && nexsusLoc->getWorkerCount()==0){
        manager->spawnMinion(handler,manager,manager->getPlayerPair().first,nexsusLoc,"minion");
     }
     nexsusLoc=manager->getNexusLocation(manager->getPlayerPair().second);
     if(nexsusLoc!=nullptr && nexsusLoc->getWorkerCount()==0){
        manager->spawnMinion(handler,manager,manager->getPlayerPair().second,nexsusLoc,"minion");
     }
 }
 activeMinion_=nullptr;
}



}
