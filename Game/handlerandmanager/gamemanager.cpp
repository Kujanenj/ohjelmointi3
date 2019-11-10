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

bool gameManager::addBuilding(std::shared_ptr<Course::BuildingBase>& Building)
{
    allbuildings_.push_back(Building);
    return true;
}



