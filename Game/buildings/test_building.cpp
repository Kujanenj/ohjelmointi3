#include "test_building.h"

namespace Whiskas {

test_building::test_building(
        const std::shared_ptr<gameEventHandler>& eventhandler,
        const std::shared_ptr<gameManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production,
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

std::string test_building::getType() const
{
    return "Nexus";
}

void test_building::onBuildAction()
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

Course::ResourceMap test_building::getProduction()
{
    // Outpost has only negative production effect.
    // Ze hold markerz, zey do nothing.
    return PRODUCTION_EFFECT;
}

}
