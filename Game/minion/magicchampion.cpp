#include "magicchampion.h"
namespace Whiskas {


MagicChampion::MagicChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                             const std::shared_ptr<Course::iObjectManager>& manager,
                             const std::shared_ptr<Course::PlayerBase>& owner,
                             int movement,
                             int health,
                             int attack,
                             int attacks):
              Minion(handler,manager,owner,movement, health, attack, attacks)
{
    setDescription("mage","Mage descript");
}

std::string MagicChampion::getType() const
{
return "mage";
}
}
