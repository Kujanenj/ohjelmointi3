#include "meleechampion.h"

namespace Whiskas {

MeleeChampion::MeleeChampion(const std::shared_ptr<gameEventHandler>& handler,
                             const std::shared_ptr<gameManager>& manager,
                             const std::shared_ptr<Course::PlayerBase>& owner,
                             int movement):
              Minion(handler,manager,owner,movement)
{
    movement_=movement;
    qDebug()<<"champion says hi";

}

}
