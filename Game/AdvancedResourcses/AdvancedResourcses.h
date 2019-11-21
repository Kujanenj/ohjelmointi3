#ifndef ADVANCEDRESOURCSES_H
#define ADVANCEDRESOURCSES_H
#include <map>
namespace Whiskas {


enum AdvancedResources{
    NONE=1,
    TEST_FIRST=2,
    TEST_SECOND=3,
};

using TestMap= std::map<AdvancedResources, int>;


TestMap mergeAdvancedMaps(const TestMap& left,
                          const TestMap& right);






}
#endif // ADVANCEDRESOURCSES_H
