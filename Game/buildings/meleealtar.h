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
               const Course::ResourceMap& buildcost = Course::ConstResourceMaps::OUTPOST_BUILD_COST,
               const AdvancedResourceMap production ={});

    void upgradeMinion() override;
    std::string getType() const override;
};
}
#endif // MELEEALTAR_H
