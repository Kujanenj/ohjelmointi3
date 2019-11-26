#ifndef MAGICCHAMPION_H
#define MAGICCHAMPION_H

#include "minion.h"
namespace Whiskas {

/**
 * @brief The MagicChampion class Subminion, has a higher dmg and an area attack
 */
class MagicChampion : public Minion
{
public:
    MagicChampion()=delete;
    MagicChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                  const std::shared_ptr<Course::iObjectManager>& manager,
                  const std::shared_ptr<Course::PlayerBase>& owner,
                  int movement=2,
                  int health=2,
                  int attack=5,
                  int numberOfAttacks=1);
    std::string getType() const override;
};
}
#endif // MAGICCHAMPION_H
