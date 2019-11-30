#ifndef MELEEALTAR_H
#define MELEEALTAR_H

#include "AltarBase.h"
namespace Whiskas {

/**
 * @brief The MeleeAltar class is an altar that upgrades minions to melee champs
 */
class MeleeAltar :public AltarBase
{
public:
    MeleeAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
               const std::shared_ptr<gameManager>& objectmanager,
               const std::shared_ptr<Course::PlayerBase>& owner);

    void upgradeMinion() override;
    std::string getType() const override;
};
}
#endif // MELEEALTAR_H
