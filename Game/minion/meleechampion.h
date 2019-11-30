#ifndef MELEECHAMPION_H
#define MELEECHAMPION_H

#include "minion/minion.h"
#include <QDebug>

namespace Whiskas {

/**
 * @brief The MeleeChampion class is a minion subtype. Has a melee attack of higher dmg
 * and better defenses
 */
class MeleeChampion : public Minion
{
public:

    MeleeChampion()=delete;
    MeleeChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                  const std::shared_ptr<Course::iObjectManager>& manager,
                  const std::shared_ptr<Course::PlayerBase>& owner,
                  int movement=1,
                  int health=5,
                  int attack=2,
                  int numberOfAttacks=2);

    std::string getType() const override;
    /**
     * @brief modifyHealth Melee Champion takes 1 less damage from attacks
     * @param hModifier
     * @return true if dead, false otherwise
     */
    bool modifyHealth(int hModifier) override;
private:


};
}
#endif // MELEECHAMPION_H
