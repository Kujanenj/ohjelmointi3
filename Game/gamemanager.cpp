#include "gamemanager.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "core/worldgenerator.h"
#include <QDebug>
gameManager::gameManager()
{
 qDebug()<<"TEST TILE MANAGER";
}


void gameManager::addTiles(const std::vector<std::shared_ptr<TileBase> > &tiles){
    alltiles_=tiles;
}

std::shared_ptr<TileBase> gameManager::getTile(const ObjectId &id)
{
    return(alltiles_.at(0));
}

std::shared_ptr<TileBase> gameManager::getTile(const Coordinate &coordinate)
{
    return(alltiles_.at(0));
}

std::vector<std::shared_ptr<TileBase> > gameManager::getTiles(const std::vector<Coordinate> &coordinates)
{
    return alltiles_;
}
std::vector<std::shared_ptr<TileBase> > gameManager::returntilevector(){
    return alltiles_;
}


