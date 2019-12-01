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
    setDescription("mage","An old Teekkari from Kampus\n"
                          "Legends say he has been in\n"
                          "TTY for n years!\n"
                          "5 damage! (INSANE OP)\n"
                          "1 attack\n"
                          "2 health (Not so op)\n"
                          "2 movement/range\n"
                          "Has a radius attack\n"
                          "Deals no dmg to buildings,\n"
                          "or the primary target.\n"
                          "Can damage friendlies aswell");
}

std::string MagicChampion::getType() const
{
return "mage";
}
}
