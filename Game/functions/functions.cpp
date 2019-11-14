#include "functions.h"

#include "buildings/farm.h"
#include <vector>
#include <QDebug>

#include "handlerandmanager/gamemanager.h"



void makeWorldGenerator(int mapsize_x, int mapsize_y, int seed,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager){

    Course::WorldGenerator& wgenerator=Course::WorldGenerator::getInstance();
    wgenerator.addConstructor<Course::Forest>(10);
    wgenerator.addConstructor<Course::Grassland>(10);
    wgenerator.generateMap(mapsize_x,mapsize_y,seed,manager,handler);

}




