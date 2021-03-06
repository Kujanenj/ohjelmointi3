#include "spring.h"


namespace Whiskas {

Spring::Spring(const Course::Coordinate& location,
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
    setDescription("Spring", "A spring region.\n"
                             "What is a spring region?\n"
                             "No one knows.\n"
                             "LifePump can be built here.\n"
                             "Mage altar aswell.");
}

std::string Spring::getType() const
{
    return "Spring";
}

void Spring::addBuilding(const std::shared_ptr<Course::BuildingBase>& building)
{
    TileBase::addBuilding(building);
    building->addHoldMarkers(1);
}

} // namespace Course
