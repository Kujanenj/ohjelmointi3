#include "desert.h"

namespace Whiskas {

Desert::Desert(const Course::Coordinate& location,
               const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
               const std::shared_ptr<Course::iObjectManager>& objectmanager,
               const unsigned int& max_build,
               const unsigned int& max_work,
               const Course::ResourceMap& production):
    TileBase(location,
             eventhandler,
             objectmanager,
             max_build,
             max_work,
             production)
{
    setDescription("Desert","Barren wasteland.\n"
                            "Only a fool would try\n"
                            " to live here.\n"
                            "Melee Altar can\n"
                            "Be constructed here.");
}

std::string Desert::getType() const
{
    return "Desert";
}

void Desert::addBuilding(const std::shared_ptr<Course::BuildingBase>& building)
{
    TileBase::addBuilding(building);
    building->addHoldMarkers(1);
}

} // namespace Whiskas
