#ifndef CUSTOMBUILDINGBASE_H
#define CUSTOMBUILDINGBASE_H

#include "buildings/buildingbase.h"

#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"

#include "attackable.h"
#include "AdvancedResourcses/AdvancedResourceMaps.h"

namespace Whiskas {

class gameEventHandler;
class gameManager;
class CustomBuildingBase : public Course::BuildingBase, public Attackable
{
public:

   CustomBuildingBase() = delete;

    explicit CustomBuildingBase(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = {},
           const AdvancedResourceMap production = {},
            int health=3,
            int attack=0
            );


   virtual AdvancedResourceMap getAdvancedProduction();
   virtual void doSpecialAction() override;
protected:
   AdvancedResourceMap production_;
};

}

#endif // BUILDINGBASE_H
