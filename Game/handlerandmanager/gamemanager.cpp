#include "gamemanager.h"


#include <QDebug>
#include <QString>
#include <utility>

namespace Whiskas {

gameManager::gameManager(std::shared_ptr<GameScene>& m_gamescene, std::shared_ptr<QTextBrowser> textBrowser):
    manager_gamescene(m_gamescene)
    ,textBrowser(std::move(textBrowser))
{
}


void gameManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles){
    alltiles_=tiles;
}

void gameManager::addTile(const std::shared_ptr<Course::TileBase>& tile)
{
    alltiles_.push_back(tile);
}

std::shared_ptr<Course::TileBase> gameManager::getTile(const Course::ObjectId &id)
{
    for(auto it :alltiles_){
        if(it->ID==id){
            qDebug()<<"Current actice tile has ID"<<it->ID;
            qDebug()<<"It has"<<it->getBuildingCount()<<"buildings";

            return it;
        }
    }
    return nullptr;
}

std::shared_ptr<Course::TileBase> gameManager::getTile(const Course::Coordinate &coordinate)
{
    for(auto it :alltiles_){
        if(it->getCoordinate() == coordinate){
            return it;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Course::TileBase> > gameManager::getTiles(const std::vector<Course::Coordinate>
                                                                      &coordinates)
{
    return alltiles_;
}
std::vector<std::shared_ptr<Course::TileBase> > gameManager::getTileVector(){
    return alltiles_;
}

std::vector<std::shared_ptr<Minion> > gameManager::getMinionVector()
{
    return allminions_;
}
std::vector<std::shared_ptr<CustomBuildingBase>> gameManager::getBuildingVector(){
    return allbuildings_;
}
std::pair<std::shared_ptr<Whiskas::LeaguePlayer>, std::shared_ptr<Whiskas::LeaguePlayer> > gameManager::getPlayerPair()
{
    return players_;
}

void gameManager::addBuilding(std::shared_ptr<CustomBuildingBase> &Building)
{
    allbuildings_.push_back(Building);
    qDebug()<<allbuildings_.size()<<"allbuildings.size";
    allattackables_.push_back(Building);
}

void gameManager::addPlayer(std::pair<
                            std::shared_ptr<Whiskas::LeaguePlayer>,
                            std::shared_ptr<Whiskas::LeaguePlayer>> &players)
{
    qDebug()<<"Check this";
     qDebug()<<QString::fromStdString(players.first->getName());
    players_=players;
}

void gameManager::addMinion(const std::shared_ptr<Minion>& minion)
{
    allminions_.push_back(minion);
     allattackables_.push_back(minion);
}

bool gameManager::spawnMinion(const std::shared_ptr<gameEventHandler>& handler,
                                                 const std::shared_ptr<Course::iObjectManager>& manager,
                                                 const std::shared_ptr<Course::PlayerBase>& owner,
                                                 const std::shared_ptr<Course::TileBase>& location,
                                                 const std::string& type)
{

    if(location!=nullptr){
    std::shared_ptr<Minion> testMinion=nullptr;
    if(type=="minion"){

        testMinion=std::make_shared<Minion>(handler,
                                            manager,
                                            owner);
    }
    if(type=="champ"){


        testMinion = std::make_shared<MeleeChampion>(handler,
                                                    manager,
                                                    owner);
    }
    if(type=="Ranged"){
        testMinion=std::make_shared<RangedChampion>(handler,
                                                    manager,
                                                    owner);
    }
    if(type=="mage"){
        testMinion=std::make_shared<MagicChampion>(handler,
                                                   manager,
                                                   owner);
    }
    testMinion->setLocationTile(location);
    location->addWorker(testMinion);
    qDebug()<<"adding minion to gamemanager vector";
    addMinion(testMinion);


    qDebug()<<"gamemanager minion vector has size of";
    qDebug()<<allminions_.size();
    if(manager_gamescene!=nullptr){
        manager_gamescene->drawItem(testMinion);
        manager_gamescene->update();
        textBrowser->append(QString(QString::fromStdString(testMinion->getOwner()->getName()) + " minion spawned"));

    return true;
    }}



    return false;

}





void gameManager::move(const std::shared_ptr<Minion>& minionToMove, const std::shared_ptr<Course::TileBase>& targetTile)
{

    if(targetTile->getWorkerCount()==0 ||
            checkForEnemies(minionToMove,
                            targetTile)){
        qDebug()<<"no minions, or there are enemies present, so we shall proceed";
       Course::Coordinate deltaC=minionToMove->getCoordinate()-
               targetTile->getCoordinate();
       qDebug()<<abs(deltaC.x())+abs(deltaC.y())<<"Distance to move";
       if(abs(deltaC.x())+abs(deltaC.y())<=minionToMove->getMoveValue()){
            if(checkForEnemies(minionToMove,targetTile)){
                /*if(minionToMove->getAttacked()){
                    qDebug()<<"has attacked";
                    return;
                }*/
                qDebug()<<"trying to attack in move command";
                if(minionToMove->getAttacked()){
                    qDebug()<<"UNIT HAS ATTACKED MAX NUMBER OF TIMES THIS TURN, GET THE HELL OUT!";
                    textBrowser->append("This unit can't attack anymore this turn");
                    return;
                }
                if(textBrowser!=nullptr){
                textBrowser->append(QString(QString::fromStdString(minionToMove->getOwner()->getName()) + " has attacked"));}
                if(minionToMove->getType()=="mage"){
                    attackMultiple(minionToMove,targetTile);
                }
                else{
                attack(minionToMove,selectAttackTarget(targetTile));
                }

                qDebug()<<"we attacked";


                minionToMove->setAttacked(true);

                return;
            }
            if(minionToMove->getMoved()){
                if(textBrowser!=nullptr){
                textBrowser->append("This unit can't move anymore this turn");}
                return;
            }
            minionToMove->currentLocationTile()->removeWorker(minionToMove);
            minionToMove->setLocationTile(targetTile);
            minionToMove->currentLocationTile()->addWorker(minionToMove);
            if(manager_gamescene!=nullptr){
            manager_gamescene->updateItem(minionToMove);
            }
            qDebug()<<"WE MOVED";
            if(textBrowser!=nullptr){
            textBrowser->append(QString(QString::fromStdString(minionToMove->getOwner()->getName()) + " has moved a minion"));
            }
            minionToMove->setMoved(true);
            minionToMove->setAttacked(true);

           }

       else{
           qDebug()<<"TOO FAR";
           return;
       }

       }
    else{
        if(textBrowser!=nullptr){
    textBrowser->append("You can't trample your minions");}
    qDebug()<<"there were minions";
    }
}

void gameManager::attack(const std::shared_ptr<Minion>& minionToAttack,
                         const std::shared_ptr<Attackable>& target)
{

    if(target==nullptr){
        qDebug()<<"Target was nullptr, we shant attack nothing";
        return;
    }
    qDebug()<<"commencing attack";
    qDebug()<<minionToAttack->getAttack()<<"attack value";
    qDebug()<<target->getHealth()<<"health value";
    if(target->modifyHealth(-minionToAttack->getAttack())){
        destroyObject(target);
        if(textBrowser!=nullptr){
        textBrowser->append(QString(QString::fromStdString(minionToAttack->getOwner()->getName())
                                    + " has destroyed their target"));}
    }

}

bool gameManager::checkForEnemies(const std::shared_ptr<Minion>& minionTomove,
                                  const std::shared_ptr<Course::TileBase>& targetTile)
{
    qDebug()<<"starting to check for enemies";
    for(const auto& it: targetTile->getWorkers()){
        if(!(minionTomove->hasSameOwnerAs(it))){
            qDebug()<<"Found enemy minion";
            return true;

        }
    }
    for(const auto& it: targetTile->getBuildings()){
        qDebug()<<QString::fromStdString(it->getType());
        if(!(minionTomove->hasSameOwnerAs(it))){
            qDebug()<<"Found enemy building";
            return true;
        }
    }
    return false;
}

std::shared_ptr<Attackable> gameManager::selectAttackTarget(
        const std::shared_ptr<Course::TileBase>& targetTile)
{
     qDebug()<<"getting the target!"<<"loop all attackble ID,s";

    if(targetTile->getWorkerCount()!=0){
         qDebug()<<"Target tile contains workers of some sort";
        for(auto it:allminions_){
            if(it==targetTile->getWorkers().at(0)){
                 qDebug()<<"Returning minion";
                    return std::move(it);
        }
        }

    }
    else{
        qDebug()<<"not a minon";
        for(auto it : allbuildings_){
            if(it->ID==targetTile->getBuildings().at(0)->ID){
                qDebug()<<"building";
                return std::move(it);
            }
        }
    }
    qDebug()<<"returning nullptr, not good";
    return nullptr;
}

void gameManager::attackMultiple(const std::shared_ptr<Minion>& minionToAttack, const std::shared_ptr<Course::TileBase>& targetTile)
{
    Course::Coordinate targetCoord = targetTile->getCoordinate();
    qDebug()<<"Target coord"<<targetCoord.x()<<targetCoord.y();
    std::vector<Course::Coordinate>neigbours=targetCoord.neighbours();
    std::shared_ptr<Attackable> targetAttackable=nullptr;
    int outer=0;
    int inner=0;
    for(const auto& it:neigbours){
        outer+=1;
        inner=0;
        qDebug()<<"looping neighbours";
        if(getTile(it)!=nullptr){
            qDebug()<<"OUTER"<<outer;
            qDebug()<<"current target tile coord"<<getTile(it)->getCoordinate().x()<<getTile(it)->getCoordinate().y();
            for(const auto& it_target:allminions_){

                inner+=1;
                qDebug()<<inner<<"INNER";
                if(it_target->currentLocationTile()==getTile(it)){
                    if(it_target==minionToAttack){
                        qDebug()<<"DONT ATTACK YOURSELF YOU FOOL";
                        break;
                    }
                    qDebug()<<"MULTIPLE ATTACK!";
                    attack(minionToAttack,it_target);
                    qDebug()<<"MULTIPLE ATTACK done";
                    break;

                }
            }
        }


    }
}

void gameManager::destroyObject(const std::shared_ptr<Attackable>& objectToDestroy)

{
    qDebug()<<"================== ";
    qDebug()<<"================== ";
    qDebug()<<"starting the 5destruction apocalypse";


    std::shared_ptr<CustomBuildingBase> tempBuildingToRemove=nullptr;

    std::shared_ptr<Minion> tempMinionToRemove=nullptr;

    unsigned int index=0;
    bool minionFound=false;
    bool buildingFound=false;



     for(unsigned int i=0; i<allminions_.size();i++){
         qDebug()<<i<<"minion indexses";
        if(objectToDestroy==allminions_.at(i)){
            tempMinionToRemove=allminions_.at(i);
            qDebug()<<tempMinionToRemove->ID;
            qDebug()<<"target minion found, with index of"<<i;
            index=i;
            minionFound=true;
            break;
        }
    }
     if(!minionFound){
        for(unsigned int i=0; i<allbuildings_.size(); i++){
             qDebug()<<i<<"building indexses";
             if(objectToDestroy->getBoundID()==allbuildings_.at(i)->ID){
                 tempBuildingToRemove=allbuildings_.at(i);
                 qDebug()<<tempBuildingToRemove->ID;
                 qDebug()<<"target building found, with index of"<<i;
                 index=i;
                 buildingFound=true;
                 break;
             }
         }
     }
     if(minionFound){
         qDebug()<<"trying to remove minion from scene";
         if(manager_gamescene!=nullptr){
         manager_gamescene->removeItem(tempMinionToRemove);}
        qDebug()<<"removing minion from tile";
         tempMinionToRemove->currentLocationTile()->removeWorker(tempMinionToRemove);
         qDebug()<<allminions_.size()<<"allminions size before erease";

            for(const auto& it : allminions_){
                qDebug()<<it->ID<<"minion ID´s";
            }
         qDebug()<<"trying to erease minion";
         allminions_.erase(allminions_.begin()+index);
         qDebug()<<allminions_.size()<<"afther erease";

         for(const auto& it : allminions_){
             qDebug()<<it->ID<<"minion ID´s afther destruction";

         }

     }

        if(buildingFound){
         qDebug()<<"trying to remove building from scene";
         if(manager_gamescene!=nullptr){
         manager_gamescene->removeItem(tempBuildingToRemove);}
        qDebug()<<"removing building from tile";
         tempBuildingToRemove->currentLocationTile()->removeBuilding(tempBuildingToRemove);

         qDebug()<<allbuildings_.size()<<"building vector size before removal";

            for(const auto& it : allbuildings_){
                qDebug()<<it->ID<<"building ID´s";
            }
         qDebug()<<"trying to erease building";
         allbuildings_.erase(allbuildings_.begin()+index);
         qDebug()<<allbuildings_.size()<<"afther erease";

         for(const auto& it : allbuildings_){
             qDebug()<<it->ID<<"building ID´s afther destruction";
         }
         if(tempBuildingToRemove->getType()=="Nexus"){
          if(tempBuildingToRemove->getOwner()==players_.first){
              winner_=(players_.second);

          }
          else{
              winner_=(players_.first);
          }
         }
     }
     qDebug()<<"================== ";
     qDebug()<<"================== ";
}

std::shared_ptr<Course::TileBase> gameManager::getNexusLocation(const std::shared_ptr<LeaguePlayer>& owner)
{
    for(const auto& it : allbuildings_){
        if(it->getType()=="Nexus" && it->getOwner()==owner){
            qDebug()<<"nexsus loc found";
            return it->currentLocationTile();
        }
    }
    return nullptr;
}

std::shared_ptr<LeaguePlayer> gameManager::getWinner()
{
    return winner_;
}

bool gameManager::checkBuildingAvailability(const std::shared_ptr<Course::TileBase> &targetTile, const std::string &type)
{
    if(targetTile->getBuildingCount()!=0){
        textBrowser->append("This tile already contains a building");
        return false;
    }
    for(const auto& it: buildingAvailability.at(type)){
        if(it==targetTile->getType()){
            qDebug()<<"Legit placement for "<<QString::fromStdString(type);
            return true;
        }
    }
    textBrowser->append(QString("You can't build a " + QString::fromStdString(type) + " on a " +
                                  QString::fromStdString(targetTile->getType())  ));
     qDebug()<<"UNLegit placement for "<<QString::fromStdString(type);
     return false;
}



} // NAMESPACE OVER HERE
