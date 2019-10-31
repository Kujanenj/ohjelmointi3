#include "testtilemanager.h"

testTileManager::testTileManager()
{

}
void testTileManager::addTiles(const std::vector<std::shared_ptr<TileBase> > &tiles){
    test_vector=tiles;
}

std::shared_ptr<TileBase> testTileManager::getTile(const ObjectId &id)
{
    return(test_vector.at(0));
}

std::shared_ptr<TileBase> testTileManager::getTile(const Coordinate &coordinate)
{
    return(test_vector.at(0));
}

std::vector<std::shared_ptr<TileBase> > testTileManager::getTiles(const std::vector<Coordinate> &coordinates)
{
    return test_vector;
}


