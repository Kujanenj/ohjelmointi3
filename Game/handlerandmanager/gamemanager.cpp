#include "gamemanager.h"


#include <QDebug>
#include <QString>
gameManager::gameManager(std::shared_ptr<GameScene>& m_gamescene)
{
 manager_gamescene = m_gamescene;
 qDebug()<<"TEST TILE MANAGER";
}


void gameManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles){
    alltiles_=tiles;
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

std::vector<std::shared_ptr<Course::TileBase> > gameManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    return alltiles_;
}
std::vector<std::shared_ptr<Course::TileBase> > gameManager::returntilevector(){
    return alltiles_;
}

std::vector<std::shared_ptr<minion> > gameManager::getMinionVector()
{
    return allminions_;
}

bool gameManager::addBuilding(std::shared_ptr<Course::BuildingBase>& Building)
{
    allbuildings_.push_back(Building);
    return true;
}

bool gameManager::addMinion(std::shared_ptr<minion> &minion)
{
    allminions_.push_back(minion);
    return true;
}

void gameManager::spawnMinion(std::shared_ptr<gameEventHandler> handler,
                                                 std::shared_ptr<gameManager> manager,
                                                 std::shared_ptr<Course::PlayerBase> owner,
                                                 std::shared_ptr<Course::TileBase> location)
{
    std::shared_ptr<minion> testMinion = std::make_shared<minion>(handler,
                                                                  manager,
                                                                  owner);
    testMinion->setLocationTile(location);
    location->addWorker(testMinion);
    qDebug()<<"adding minion to gamemanager vector";
    addMinion(testMinion);

    qDebug()<<"gamemanager minion vector has size of";
    qDebug()<<allminions_.size();

    manager_gamescene->drawItem(testMinion);
    manager_gamescene->update();

    qDebug()<<location->ID<<"has a drawn"<< QString::fromStdString(testMinion->getType());

}

void gameManager::spawnNexus(std::shared_ptr<gameEventHandler> handler,
                             std::shared_ptr<gameManager> manager,
                             std::shared_ptr<Course::PlayerBase> owner,
                             std::shared_ptr<Course::TileBase> location)
{
    std::shared_ptr<Nexus> testNexus = std::make_shared<Nexus>(handler, manager, owner);
    location->addBuilding(testNexus);
    manager_gamescene->drawItem(testNexus);
    allbuildings_.push_back(testNexus);
    qDebug()<<location->ID<<"has a nexus now";

}

template<typename buildingType>
bool gameManager::spawnBuilding(std::shared_ptr<gameEventHandler> handler,
                   std::shared_ptr<gameManager> manager,
                   std::shared_ptr<Course::PlayerBase> player){
    {
        if(handler->getActiveTile()==nullptr){
            qDebug()<<"error, active tile is a nullptr";
            return false;
        }
        qDebug()<<"Trying to spawn a building pointer in functions";
        std::shared_ptr<Course::BuildingBase> testBuilding = std::make_shared<buildingType>(handler,manager,player);

        qDebug() << QString::fromStdString(testBuilding->getType());
        handler->getActiveTile()->addBuilding(testBuilding);
        manager->addBuilding(testBuilding);
        return true;
    }

}

void gameManager::move(std::shared_ptr<minion> minionToMove, std::shared_ptr<Course::TileBase> targetTile)
{
    if(targetTile->getWorkerCount()==0 ||
            checkForEnemies(minionToMove,
                            targetTile)){ //ADD OR STATEMENT FOR ENEMIEEEES
        qDebug()<<"no minions, or there are enemies present, so we shall proceed";
       Course::Coordinate deltaC=minionToMove->getCoordinate()-
               targetTile->getCoordinate();
       qDebug()<<abs(deltaC.x())+abs(deltaC.y())<<"Distance to move";
       if(abs(deltaC.x())+abs(deltaC.y())<=minionToMove->getMoveValue()){
            if(checkForEnemies(minionToMove,targetTile)){
                qDebug()<<"trying to attack in move command";
                attack(minionToMove,selectAttackTarget(targetTile));
                qDebug()<<"we attacked";
                return;
            }

            minionToMove->currentLocationTile()->removeWorker(minionToMove);
            minionToMove->setLocationTile(targetTile);
            minionToMove->currentLocationTile()->addWorker(minionToMove);
            manager_gamescene->updateItem(minionToMove);
            qDebug()<<"WE MOVED";

           }

       else{
           qDebug()<<"TOO FAR";
           return;
       }

       }
    else{
    qDebug()<<"there were minions";
    }
}

void gameManager::attack(std::shared_ptr<minion> minionToMove,
                         std::shared_ptr<minion> toAttack)
{
    if(toAttack==nullptr){
        qDebug()<<"Target was nullptr, we shant attack nothing";
        return;
    }
    qDebug()<<"commencing attack";
    qDebug()<<minionToMove->getAttack()<<"attack value";
    qDebug()<<toAttack->getHealth()<<"health value";
    if(toAttack->modifyHealth(-minionToMove->getAttack())){


        destroyMinion(toAttack);
    }

}

bool gameManager::checkForEnemies(std::shared_ptr<minion> minionTomove,
                                  std::shared_ptr<Course::TileBase> targetTile)
{
    qDebug()<<"starting to check for enemies";
    for(auto it: targetTile->getWorkers()){
        if(!(minionTomove->hasSameOwnerAs(it))){
            qDebug()<<"Found enemy minion";
            return true;

        }
    }
    for(auto it: targetTile->getBuildings()){
        if(!(minionTomove->hasSameOwnerAs(it))){
            qDebug()<<"Found enemy building";
            return true;
        }
    }
    return false;
}

std::shared_ptr<minion> gameManager::selectAttackTarget(
        std::shared_ptr<Course::TileBase> targetTile)
{
    if(targetTile->getWorkerCount()!=0){
        qDebug()<<"getting the target!";
        for(auto it: getMinionVector()){
            if(it==targetTile->getWorkers().at(0)){
                qDebug()<<"target found, trying to do stdmove";
                 return std::move(it);
            }
        }
    }
    qDebug()<<"returning nullptr, not good";
    return nullptr;
}

void gameManager::destroyMinion(std::shared_ptr<minion> minionToDestroy)
{
    qDebug()<<"starting the minion destruction apocalypse";


    unsigned int index=0;
    bool targetFound=false;
     for(unsigned int i=0; i<allminions_.size();i++){
         qDebug()<<i<<"indexses";
        if(minionToDestroy==allminions_.at(i)){
            qDebug()<<"target found, with index of"<<i;
            index=i;
            targetFound=true;
            break;
        }
    }
     if(targetFound){
         qDebug()<<"removing minion from tile";
         minionToDestroy->currentLocationTile()->removeWorker(minionToDestroy);
         qDebug()<<allminions_.size()<<"allminions size before erease";
         qDebug()<<"trying to erease minion";
         allminions_.erase(allminions_.begin()+index);
         qDebug()<<allminions_.size()<<"afther erease";
     }
}
