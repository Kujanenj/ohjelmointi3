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
    setDescription("MeleeChampion","A fiersome warrior from the heart\n"
                                   " of Hervanta. Not shy\n to get physical. This is your frontline unit. \n"
                                   "* Deals 2 damage per attack\n"
                                   "* 5 Health\n"
                                   "* Range/movement 1\n"
                                   "* Can attack twice Per turn\n"
                                   "* Takes 1 less damage from attacks ");

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
