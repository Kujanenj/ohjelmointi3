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
setDescription("Ranged","A ranged archer.\n"
                        "Can attack from range.\n"
                        "Since its ranged.\n"
                        "What did you expect?\n"
                        "1 damage\n"
                        "3 attacks\n"
                        "3 health\n"
                        "3 movement/range");
}

std::string RangedChampion::getType() const
{
 return "Ranged";
}
}
