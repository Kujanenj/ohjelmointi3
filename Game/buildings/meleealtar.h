#ifndef MELEEALTAR_H
#define MELEEALTAR_H

#include "AltarBase.h"
namespace Whiskas {


class MeleeAltar :public AltarBase
{
public:
    MeleeAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
               const std::shared_ptr<gameManager>& objectmanager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               const int& tilespaces = 1,
               const AdvancedResourceMap buildcost = {},
               const AdvancedResourceMap production ={});
public:
    void upgradeMinion() override;
};
}
#endif // MELEEALTAR_H
