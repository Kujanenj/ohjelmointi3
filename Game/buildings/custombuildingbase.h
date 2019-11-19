#ifndef CUSTOMBUILDINGBASE_H
#define CUSTOMBUILDINGBASE_H

#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"

#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"

#include "core/playerbase.h"

namespace Whiskas {


class CustomBuildingBase : public Course::BuildingBase, public Attackable
{
public:

   CustomBuildingBase() = delete;

    explicit CustomBuildingBase(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::OUTPOST_BUILD_COST,
            const Course::ResourceMap& production = Course::ConstResourceMaps::OUTPOST_PRODUCTION,
            int health=3
            );
};

}

#endif // BUILDINGBASE_H
