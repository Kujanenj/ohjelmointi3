#include "custombuildingbase.h"

namespace Whiskas {



CustomBuildingBase::CustomBuildingBase(
        const std::shared_ptr<gameEventHandler>& eventhandler,
        const std::shared_ptr<gameManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const AdvancedResourceMap production,
        int health,
        int attack
        ):
    Course::BuildingBase(eventhandler,
                 objectmanager,
                 owner,
                 tilespaces),
    Attackable(health, attack,0, ID),
    production_(production)
{
}

AdvancedResourceMap CustomBuildingBase::getAdvancedProduction()
{
    return production_;
}

void CustomBuildingBase::doSpecialAction()
{
    qDebug()<<"Special action";
}

}
