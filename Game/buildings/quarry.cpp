#include "quarry.h"

#include "nexus.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"



namespace Whiskas {

Quarry::Quarry(
        const std::shared_ptr<gameEventHandler>& eventhandler,
        const std::shared_ptr<gameManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const  AdvancedResourceMap buildcost,
        const AdvancedResourceMap production,
        int health,
        int attack
        ):
    CustomBuildingBase(eventhandler,
                 objectmanager,
                 owner,
                 tilespaces,
                 buildcost,
                 production,
                 health,
                 attack)

{
}

std::string Quarry::getType() const
{
    return "Quarry";
}

} // namespace Whiskas
