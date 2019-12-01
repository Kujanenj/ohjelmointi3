#include "jungle.h"

namespace Whiskas {

Jungle::Jungle(const Course::Coordinate& location,
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
    setDescription("Jungle","A lush jungle."
                            "A Sawmill can \nbe constructed here, "
                            "no\nmatter what enviromentalist say.\n"
                            "Ranged Altar can also be constructed\nhere,"
                            "since you know, Wood.");
}

std::string Jungle::getType() const
{
    return "Jungle";
}

/*
void Jungle::addBuilding(const std::shared_ptr<Course::BuildingBase>& building)
{
    TileBase::addBuilding(building);
    building->addHoldMarkers(1);
}*/

} // namespace Whiskas
