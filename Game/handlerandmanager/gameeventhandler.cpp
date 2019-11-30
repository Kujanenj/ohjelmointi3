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

void gameEventHandler::handleLeftClick(const std::shared_ptr<GameScene>& scene, const std::shared_ptr<gameManager>& manager){
    qDebug()<<"";
    qDebug()<<"";
    qDebug()<<"";
    qDebug()<<"handling mwindow click";




        activeTile_ = manager->getTile(*scene->getLastCoordinate());
        qDebug()<< "================";
        qDebug()<< "HANDLING MWINDOW CLICK";
        qDebug() << "Coordinate X: " << activeTile_->getCoordinatePtr()->x()
                 << ", Y: " << activeTile_->getCoordinatePtr()->y();
        qDebug()<< "the ID is"<< scene->getLastID();
        qDebug()<< "Amount of minions is"<< activeTile_->getWorkers().size();
        qDebug()<< "Amount of buildings is"<< activeTile_->getBuildings().size();
        if (!activeTile_->getBuildings().empty()){
            qDebug()<< "Building is"
                    << QString::fromStdString(activeTile_->getBuildings().at(0)->getType())
                    << "and the owner is"
                    << QString::fromStdString(activeTile_->getBuildings().at(0)->getOwner()->getName());
        }

        if (!activeTile_->getWorkers().empty()){
            for(const auto& it: manager->getMinionVector()){
                if(activeTile_->getWorkers().front()==it && it->getOwner()==turn_->getInTurn()){
                    activeMinion_=it;

                    qDebug()<<"active minion type is"<<QString::fromStdString(it->getType())
                           <<"and its owner is"<<QString::fromStdString(it->getOwner()->getName());
                    message_ = "Active minion type is" + QString::fromStdString(it->getType()) +
                            " and its owner is " + QString::fromStdString(it->getOwner()->getName());
                }

            }
        }
        else{
            activeMinion_=nullptr;
        }
        qDebug()<< "================";



}
void gameEventHandler::handleRightClick(const std::shared_ptr<gameManager>& manager, const std::shared_ptr<GameScene>& scene)
{
    std::shared_ptr<Course::TileBase> targetTile=manager->getTile(*scene->getLastCoordinate());
    if(activeMinion_!=nullptr){
        qDebug()<<" ";
        qDebug()<<" ";
        qDebug()<<" ";
        qDebug()<<"trying to move";
        manager->move(activeMinion_,targetTile);


    }
    else{
        qDebug()<<"Active minion was null ptr or target tile contains a minion";
        message_ = "Target tile contains a minion";

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
 if(turn_->getTurnCounter()==1||turn_->getTurnCounter() % 5==0){
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

QString gameEventHandler::getMessage()
{
    return message_;
}


}
