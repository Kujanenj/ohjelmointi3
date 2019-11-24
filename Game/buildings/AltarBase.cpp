#include "AltarBase.h"
namespace Whiskas {

AltarBase::AltarBase(const std::shared_ptr<gameEventHandler>& eventhandler,
                                       const std::shared_ptr<gameManager>& objectmanager,
                                       const std::shared_ptr<Course::PlayerBase>& owner,
                                       const int& tilespaces,
                                       const Course::ResourceMap& buildcost,
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
                                                attack),
                                   manager_(objectmanager),
                                 handler_(eventhandler),
                                 owner_(owner)
{

}
}
std::string Whiskas::AltarBase::getType() const
{
    return "Altar";
}

void Whiskas::AltarBase::doSpecialAction()
{
    upgradeMinion();
}
