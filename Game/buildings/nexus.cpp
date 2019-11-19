#include "nexus.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"

#include "tiles/tilebase.h"

#include "buildings/buildingbase.h"

namespace Whiskas {

Nexus::Nexus(
        const std::shared_ptr<gameEventHandler>& eventhandler,
        const std::shared_ptr<gameManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production
        ):
    Course::BuildingBase(eventhandler,
                 objectmanager,
                 owner,
                 tilespaces,
                 buildcost,
                 production)
{
}

std::string Nexus::getType() const
{
    return "Nexus";
}

void Nexus::onBuildAction()
{
    std::vector< std::shared_ptr<Course::TileBase> > neighbours =
            lockObjectManager()->getTiles(getCoordinatePtr()->neighbours(1));

    for(auto it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        // If the Tile doesn't have owner, set it's owner to buildings owner.
        if( not (*it)->getOwner() )
        {
            (*it)->setOwner(getOwner());
        }
    }
}

Course::ResourceMap Nexus::getProduction()
{
    // Outpost has only negative production effect.
    // Ze hold markerz, zey do nothing.
    return PRODUCTION_EFFECT;
}

} // namespace Whiskas
