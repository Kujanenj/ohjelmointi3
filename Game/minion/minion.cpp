#include "minion.h"

minion::minion(const std::shared_ptr<gameEventHandler>& handler,
               const std::shared_ptr<gameManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               const std::shared_ptr<Course::Coordinate>& coordinate):
    Course::PlaceableGameObject(handler, manager, owner)
{

}
