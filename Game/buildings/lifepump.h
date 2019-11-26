#ifndef LIFEPUMP_H
#define LIFEPUMP_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {


class Lifepump : public CustomBuildingBase

{
public:
    Lifepump() = delete;

    explicit Lifepump(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const AdvancedResourceMap buildcost = NEXUS_PRODUCE,
            const AdvancedResourceMap production = NEXUS_PRODUCE,
            int health =5,
            int attack = 0

            );

    virtual ~Lifepump() = default;
    virtual std::string getType() const override;

}; // class Lifepump

} // namespace Whiskas

#endif // LIFEPUMP_H
