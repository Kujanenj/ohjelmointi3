#include "turn.h"

#include <utility>
namespace Whiskas {
Turn::Turn(const std::shared_ptr<gameManager>& manager)
{
playerInTurn_=manager->getPlayerPair().first;
manager_=manager;
}

std::shared_ptr<LeaguePlayer> Turn::getInTurn()
{
    return playerInTurn_;
}

void Turn::swapTurn()
{

    turnCounter_+=1;
    for(const auto& it:manager_->getMinionVector()){
        it->setMoved(false);


        it->setAttacked(false);
    }



    for(const auto& it:manager_->getBuildingVector()){
        qDebug()<<"buildings about to give you shit";
        if(it->getOwner()==playerInTurn_){
        playerInTurn_->setPlayerItems(mergeAdvancedMaps(playerInTurn_->getItems(),
                                                        it->getAdvancedProduction()));
    }}
    for(const auto& it:manager_->getBuildingVector()){ //UPGRADE MINONS
        it->doSpecialAction();
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

int Turn::getTurnCounter()
{
    return turnCounter_;
}

void Turn::setInTurn(std::shared_ptr<LeaguePlayer> ToBeInTurn)
{
    playerInTurn_=std::move(ToBeInTurn);
}
}
