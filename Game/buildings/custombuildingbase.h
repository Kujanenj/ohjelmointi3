#ifndef CUSTOMBUILDINGBASE_H
#define CUSTOMBUILDINGBASE_H

#include "buildings/buildingbase.h"

#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"

#include "minion/attackable.h"
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
            const int& tilespaces = 2,
            const AdvancedResourceMap& buildcost = {},
           const AdvancedResourceMap& production = {},
            int health=3,
            int attack=0
            );

   /**
    * @brief Returns building's production as AdvancedResourceMap
    */
   virtual AdvancedResourceMap getAdvancedProduction();

   /**
   * @brief Returns building's cost as AdvancedResourceMap
   */
   virtual AdvancedResourceMap getAdvancedCost();

    void doSpecialAction() override;

    /**
    * @brief returns altar's cooldown
    */
    virtual int getCooldown();

protected:
   AdvancedResourceMap production_;
   AdvancedResourceMap buildcost_;
   int cooldown_=-1;
};

}

#endif // BUILDINGBASE_H
