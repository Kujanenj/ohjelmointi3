#include "test_features.h"
#include <vector>
#include <QDebug>
using namespace Course;


std::vector<std::shared_ptr<TileBase>> make_test_wgenerator()
{

    std::shared_ptr<testTileManager> tilemanager=std::make_shared<testTileManager>();
    std::shared_ptr<uselessEventHandler> defaultmanager= std::make_shared<uselessEventHandler>();



    WorldGenerator& test_generator = WorldGenerator::getInstance();
    test_generator.addConstructor<Forest>(10);
    test_generator.generateMap(10,10,10,tilemanager,defaultmanager);
    Coordinate to_sub(-5,-5);
    Coordinate to_change(0,0);
    std::shared_ptr<Coordinate> ptr(new Coordinate(0, 0));
    std::vector<std::shared_ptr<TileBase>> to_draw;
    to_draw=tilemanager->returntesttiles();
    for(auto &it : to_draw){
        it->setCoordinate(it->getCoordinate()+to_sub);

    }

    return to_draw;




}





template<typename T>
void WorldGenerator::addConstructor(unsigned int weight)
{
    TileConstructorPointer ctor = std::make_shared<T, Coordinate,
            std::shared_ptr<iGameEventHandler>,
            std::shared_ptr<iObjectManager> >;
    m_ctors.insert(std::make_pair(weight, ctor));
}
 std::shared_ptr<Course::Forest> get_test_tile()
{
    Course::Coordinate test_coordinate = Course::Coordinate(0, 0);
       std::shared_ptr<testTileManager> tilemanager=std::make_shared<testTileManager>();
       std::shared_ptr<Course::iGameEventHandler> test_handler = nullptr;
       std::shared_ptr<Course::Forest> test_forest(new Course::Forest(test_coordinate, test_handler, tilemanager) );

       return test_forest;
}
