#include "functions.h"

#include "buildings/farm.h"
#include <vector>
#include <QDebug>



void makeWorldGenerator(int mapsize_x, int mapsize_y, int seed,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager){

    Course::WorldGenerator& wgenerator=Course::WorldGenerator::getInstance();
    wgenerator.addConstructor<Course::Forest>(10);
    wgenerator.addConstructor<Course::Grassland>(10);
    wgenerator.generateMap(mapsize_x,mapsize_y,seed,manager,handler);

}
void startGame(int mapsize_x, int mapsize_y, int seed){
    std::shared_ptr<gameEventHandler> handler =  std::make_shared<gameEventHandler>();
    std::shared_ptr<gameManager> manager =  std::make_shared<gameManager>();
    makeWorldGenerator(mapsize_x,mapsize_y, seed, handler, manager);

}



std::shared_ptr<Course::BuildingBase> spawnBuilding(std::shared_ptr<gameEventHandler> handler, std::shared_ptr<gameManager> manager, std::shared_ptr<Course::PlayerBase> player)
{
    qDebug()<<"Trying to spawn a building pointer in functions";
    std::shared_ptr<Course::BuildingBase> testBuilding = std::make_shared<Course::Farm>(handler,manager,player);

    qDebug() << QString::fromStdString(testBuilding->getType());
    return testBuilding;
}
