#include "rangedchampion.h"
namespace Whiskas {


RangedChampion::RangedChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                                const std::shared_ptr<Course::iObjectManager>& manager,
                                const std::shared_ptr<Course::PlayerBase>& owner,
                                int movement,
                                int health,
                                int attack,
                                int attacks):
                 Minion(handler,manager,owner,movement, health, attack, attacks)

{

}

std::string RangedChampion::getType() const
{
 return "Ranged";
}
}
