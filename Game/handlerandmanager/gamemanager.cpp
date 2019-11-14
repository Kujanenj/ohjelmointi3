#include "gamemanager.h"


#include <QDebug>
#include <QString>
gameManager::gameManager()
{
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
    return(alltiles_.at(0));
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
    std::shared_ptr<minion> testMinion = std::make_shared<minion>(handler, manager, owner);
    testMinion->setLocationTile(location);
    location->addWorker(testMinion);
    qDebug()<<"adding minion to gamemanager vector";
    addMinion(testMinion);

    qDebug()<<"gamemanager minion vector has size of";
    qDebug()<<allminions_.size();

}

void gameManager::spawnNexus(std::shared_ptr<gameEventHandler> handler,
                             std::shared_ptr<gameManager> manager,
                             std::shared_ptr<Course::PlayerBase> owner,
                             std::shared_ptr<Course::TileBase> location)
{
    std::shared_ptr<Nexus> testNexus = std::make_shared<Nexus>(handler, manager, owner);
    location->addBuilding(testNexus);
    allbuildings_.push_back(testNexus);
    qDebug()<<location->ID<<"has a nexus now";
}

void gameManager::move(std::shared_ptr<minion> minionToMove, std::shared_ptr<Course::TileBase> targetTile)
{
    if(targetTile->getWorkerCount()==0){ //ADD OR STATEMENT FOR ENEMIEEEES

       Course::Coordinate deltaC=minionToMove->getCoordinate()-
               targetTile->getCoordinate();
       qDebug()<<abs(deltaC.x())+abs(deltaC.y());
       if(abs(deltaC.x())+abs(deltaC.y())<=minionToMove->getMoveValue()){
            minionToMove->currentLocationTile()->removeWorker(minionToMove);
            minionToMove->setLocationTile(targetTile);
            minionToMove->currentLocationTile()->addWorker(minionToMove);
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
