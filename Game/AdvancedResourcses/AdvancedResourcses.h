#ifndef ADVANCEDRESOURCSES_H
#define ADVANCEDRESOURCSES_H
#include <map>
namespace Whiskas {


enum AdvancedResources{
    NONE=1,
    PLACEHOLDER_RESOURCE_FIRST=2,
    PLACEHOLDER_RESOURCE_SECOND=3,
};

using AdvancedResourceMap= std::map<AdvancedResources, int>;


AdvancedResourceMap mergeAdvancedMaps(const AdvancedResourceMap& left,
                          const AdvancedResourceMap& right);






}
#endif // ADVANCEDRESOURCSES_H
