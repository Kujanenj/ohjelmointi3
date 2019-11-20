#include "turn.h"
namespace Whiskas {
Turn::Turn(std::shared_ptr<gameManager> manager)
{
playerInTurn_=manager->getPlayerPair().first;
manager_=manager;
}

std::shared_ptr<Course::PlayerBase> Turn::getInTurn()
{
    return playerInTurn_;
}

void Turn::swapTurn()
{

    for(auto it:manager_->getMinionVector()){
        it->setMoved(false);
        it->setAttacked(false);
    }





    //swawp active player
    if(playerInTurn_==manager_->getPlayerPair().first){
        playerInTurn_=manager_->getPlayerPair().second;
    }
    else{
        playerInTurn_=manager_->getPlayerPair().first;
    }
    qDebug()<<"Active player is now"<<QString::fromStdString(
                  playerInTurn_->getName());
}
}
