#include "functions.h"
#include <vector>
#include <QDebug>
using namespace Course;


void makeWorldGenerator(int mapsize_x, int mapsize_y, int seed,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager){

    WorldGenerator& wgenerator=WorldGenerator::getInstance();
    wgenerator.addConstructor<Forest>(10);
    wgenerator.addConstructor<Grassland>(10);
    wgenerator.generateMap(mapsize_x,mapsize_y,seed,manager,handler);

}
void startGame(int mapsize_x, int mapsize_y, int seed){
    std::shared_ptr<gameEventHandler> handler =  std::make_shared<gameEventHandler>();
    std::shared_ptr<gameManager> manager =  std::make_shared<gameManager>();
    makeWorldGenerator(mapsize_x,mapsize_y, seed, handler, manager);

}

