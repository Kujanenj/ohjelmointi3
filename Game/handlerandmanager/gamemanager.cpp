#include "gamemanager.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "core/worldgenerator.h"
#include <QDebug>
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


