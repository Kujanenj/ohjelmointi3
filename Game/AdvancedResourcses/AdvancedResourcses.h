#ifndef ADVANCEDRESOURCSES_H
#define ADVANCEDRESOURCSES_H
#include <map>
namespace Whiskas {


enum AdvancedResources{
    NONE=1,
    IRON=2,
    WOOD=3,
    CRYSTAL=4,
    LIFEWATER=5

};

using AdvancedResourceMap= std::map<AdvancedResources, int>;


AdvancedResourceMap mergeAdvancedMaps(const AdvancedResourceMap& left,
                          const AdvancedResourceMap& right);






}
#endif // ADVANCEDRESOURCSES_H
