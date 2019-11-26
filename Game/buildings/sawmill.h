#ifndef SAWMILL_H
#define SAWMILL_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {

class Sawmill : public CustomBuildingBase

{
public:
    Sawmill() = delete;

    explicit Sawmill(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const AdvancedResourceMap buildcost = SAWMILL_COST,
            const AdvancedResourceMap production = SAWMILL_PRODUCE,
            int health =5,
            int attack = 0

            );

    virtual ~Sawmill() = default;
    virtual std::string getType() const override;

}; // class Sawmill

} // namespace Whiskas


#endif // SAWMILL_H
