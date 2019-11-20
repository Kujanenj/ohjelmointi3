#include "meleechampion.h"

namespace Whiskas {

MeleeChampion::MeleeChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                             const std::shared_ptr<Course::iObjectManager>& manager,
                             const std::shared_ptr<Course::PlayerBase>& owner,
                             int movement,
                             int health,
                             int attack,
                             int attacks):
              Minion(handler,manager,owner,movement, health, attack, attacks)
{
    movement_=movement;
    qDebug()<<"champion says hi";

}

std::string MeleeChampion::getType() const
{
    return "MeleeChampion";
}

bool MeleeChampion::modifyHealth(int hModifier)
{
    healthValue_+=hModifier+1;
    if(healthValue_<=0){
        return true;
    }
    return false;
}

}
