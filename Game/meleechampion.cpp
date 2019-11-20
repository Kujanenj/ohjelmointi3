#include "meleechampion.h"

namespace Whiskas {

MeleeChampion::MeleeChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                             const std::shared_ptr<Course::iObjectManager>& manager,
                             const std::shared_ptr<Course::PlayerBase>& owner,
                             int movement):
              Minion(handler,manager,owner,movement)
{
    movement_=movement;
    qDebug()<<"champion says hi";

}

std::string MeleeChampion::getType() const
{
    return "MeleeChampion";
}

}
