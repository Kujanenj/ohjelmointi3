#ifndef RANGEDCHAMPION_H
#define RANGEDCHAMPION_H

#include "minion.h"
namespace Whiskas {

/**
 * @brief The RangedChampion class Has a ranged attack and higher movement
 */
class RangedChampion : public Minion
{
public:
    RangedChampion()=delete;
    RangedChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                   const std::shared_ptr<Course::iObjectManager>& manager,
                   const std::shared_ptr<Course::PlayerBase>& owner,
                   int movement=3,
                   int health=3,
                   int attack=1,
                   int numberOfAttacks=3);
     std::string getType() const override;
};
}
#endif // RANGEDCHAMPION_H
