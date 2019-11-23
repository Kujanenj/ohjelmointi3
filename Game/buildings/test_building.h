#ifndef TEST_BUILDING_H
#define TEST_BUILDING_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {


class test_building : public CustomBuildingBase
{
public:
    test_building() = delete;

    explicit test_building(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::OUTPOST_BUILD_COST,
            const AdvancedResourceMap production = {},
            int health = 3,
            int attack = 0
            );

    virtual ~test_building() = default;
    virtual std::string getType() const override;
    virtual void onBuildAction() override;
    virtual Course::ResourceMap getProduction() override;
};

}
#endif // TEST_BUILDING_H
