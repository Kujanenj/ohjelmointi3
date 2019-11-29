#ifndef RANGEDALTAR_H
#define RANGEDALTAR_H

#include "AltarBase.h"
namespace Whiskas {

class RangedAltar : public AltarBase
{
public:
    RangedAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                const std::shared_ptr<gameManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner);
    void upgradeMinion() override;
    std::string getType() const override;
};
}
#endif // RANGEDALTAR_H
