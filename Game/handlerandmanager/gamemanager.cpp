#include "gamemanager.h"


#include <QDebug>
#include <QString>

namespace Whiskas {

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

std::vector<std::shared_ptr<Minion> > gameManager::getMinionVector()
{
    return allminions_;
}

bool gameManager::addBuilding(std::shared_ptr<CustomBuildingBase> &Building)
{
    allbuildings_.push_back(Building);
    qDebug()<<allbuildings_.size()<<"allbuildings.size";
    allattackablestest_.push_back(Building);

    return true;
}

bool gameManager::addMinion(std::shared_ptr<Minion> &minion)
{
    allminions_.push_back(minion);
     allattackablestest_.push_back(minion);
    return true;
}

void gameManager::spawnMinion(std::shared_ptr<gameEventHandler> handler,
                                                 std::shared_ptr<gameManager> manager,
                                                 std::shared_ptr<Course::PlayerBase> owner,
                                                 std::shared_ptr<Course::TileBase> location)
{
    std::shared_ptr<Minion> testMinion = std::make_shared<Minion>(handler,
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


    //qDebug()<<location->ID<<"has a drawn"<< QString::fromStdString(testMinion->getType());

}





void gameManager::move(std::shared_ptr<Minion> minionToMove, std::shared_ptr<Course::TileBase> targetTile)
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

void gameManager::attack(std::shared_ptr<Minion> minionToMove,
                         std::shared_ptr<Attackable> toAttack)
{

    if(toAttack==nullptr){
        qDebug()<<"Target was nullptr, we shant attack nothing";
        return;
    }
    qDebug()<<"commencing attack";
    qDebug()<<minionToMove->getAttack()<<"attack value";
    qDebug()<<toAttack->getHealth()<<"health value";
    if(toAttack->modifyHealth(-minionToMove->getAttack())){


        destroyObject(toAttack);
    }

}

bool gameManager::checkForEnemies(std::shared_ptr<Minion> minionTomove,
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
        qDebug()<<QString::fromStdString(it->getType());
        if(!(minionTomove->hasSameOwnerAs(it))){
            qDebug()<<"Found enemy building";
            return true;
        }
    }
    return false;
}

std::shared_ptr<Attackable> gameManager::selectAttackTarget(
        std::shared_ptr<Course::TileBase> targetTile)
{


        qDebug()<<"getting the target!"<<"loop all attackble ID,s";
        for(auto it:allattackablestest_){
            qDebug()<<it->getBoundID()<<"bound id of all objects loop";
            if(targetTile->getWorkerCount()!=0){
                qDebug()<<"Target tile contains workers of some sort";
            if(it->getBoundID()==targetTile->getWorkers().at(0)->ID){

                return it;

            }}
            if(targetTile->getBuildingCount()!=0){
                qDebug()<<"not a minon";
                qDebug()<<targetTile->getBuildings().at(0)->ID<<"building id";
                if(it->getBoundID()==targetTile->getBuildings().at(0)->ID){

                    qDebug()<<"building";
                    return it;
            }
          }
        }

    qDebug()<<"returning nullptr, not good";
    return nullptr;
}

void gameManager::destroyObject(std::shared_ptr<Attackable> objectToDestroy)

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
         manager_gamescene->removeItem(tempMinionToRemove);
        qDebug()<<"removing minion from tile";
         tempMinionToRemove->currentLocationTile()->removeWorker(tempMinionToRemove);
         qDebug()<<allminions_.size()<<"allminions size before erease";

            for(auto it : allminions_){
                qDebug()<<it->ID<<"minion ID´s";
            }
         qDebug()<<"trying to erease minion";
         allminions_.erase(allminions_.begin()+index);
         qDebug()<<allminions_.size()<<"afther erease";

         for(auto it : allminions_){
             qDebug()<<it->ID<<"minion ID´s afther destruction";

         }

     }

        if(buildingFound){
         qDebug()<<"trying to remove building from scene";
         manager_gamescene->removeItem(tempBuildingToRemove);
        qDebug()<<"removing building from tile";
         tempBuildingToRemove->currentLocationTile()->removeBuilding(tempBuildingToRemove);
         qDebug()<<allbuildings_.size()<<"building vector size before removal";

            for(auto it : allbuildings_){
                qDebug()<<it->ID<<"building ID´s";
            }
         qDebug()<<"trying to erease building";
         allbuildings_.erase(allbuildings_.begin()+index);
         qDebug()<<allbuildings_.size()<<"afther erease";

         for(auto it : allbuildings_){
             qDebug()<<it->ID<<"building ID´s afther destruction";
         }
     }
     qDebug()<<"================== ";
     qDebug()<<"================== ";
}

} // NAMESPACE OVER HERE
