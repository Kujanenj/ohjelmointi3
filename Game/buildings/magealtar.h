#ifndef MAGEALTAR_H
#define MAGEALTAR_H
#include "AltarBase.h"
namespace Whiskas {


/**
 * @brief The MageAltar class is an altar, that upgrades minions to mages.
 */
class MageAltar : public AltarBase
{
public:
    MageAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
              const std::shared_ptr<gameManager>& objectmanager,
              const std::shared_ptr<Course::PlayerBase>& owner);
  void upgradeMinion() override;
  std::string getType() const override;
};
}
#endif // MAGEALTAR_H
