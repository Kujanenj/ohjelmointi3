#include "test_features.h"

using namespace Course;


void make_test_wgenerator()
{

    std::shared_ptr<test_tile_manager> test_manager (new test_tile_manager());
    std::shared_ptr<Course::iGameEventHandler> test_handler = nullptr;
    WorldGenerator& test_generator = WorldGenerator::getInstance();
    test_generator.addConstructor<Forest>(1);
    test_generator.generateMap(5,5,5,test_manager,test_handler);
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
       std::shared_ptr<Course::iObjectManager> test_manager = nullptr;
       std::shared_ptr<Course::iGameEventHandler> test_handler = nullptr;
       std::shared_ptr<Course::Forest> test_forest(new Course::Forest(test_coordinate, test_handler, test_manager) );

       return test_forest;
}
