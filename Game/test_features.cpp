#include "test_features.h"
#include <vector>
#include <QDebug>
using namespace Course;


void make_test_wgenerator()
{

    std::shared_ptr<testTileManager> tilemanager=std::make_shared<testTileManager>();
    std::shared_ptr<uselessEventHandler> defaultmanager= std::make_shared<uselessEventHandler>();



    WorldGenerator& test_generator = WorldGenerator::getInstance();
    test_generator.addConstructor<Forest>(1);
    test_generator.generateMap(5,5,5,tilemanager,defaultmanager);

    //std::vector<std::shared_ptr<TileBase>> to_draw;
    //to_draw=tilemanager->getTestVector();
   // qDebug()<<to_draw.size();
    return;




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
