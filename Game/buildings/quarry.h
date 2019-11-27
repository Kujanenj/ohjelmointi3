#ifndef QUARRY_H
#define QUARRY_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {


class Quarry : public CustomBuildingBase

{
public:
    Quarry() = delete;

    explicit Quarry(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const AdvancedResourceMap buildcost = QUARRY_COST,
            const AdvancedResourceMap production = QUARRY_PRODUCE,
            int health =5,
            int attack = 0

            );

    virtual ~Quarry() = default;
    virtual std::string getType() const override;

}; // class Nexus

} // namespace Whiskas



#endif // QUARRY_H
