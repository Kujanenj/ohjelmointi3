#ifndef NEXUS_H
#define NEXUS_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {

/**
 * @brief The Nexus class represents a Nexus-building in the game.
 *
 * The Nexus produces 1 of each resource per turn
 * The Nexus also spawns a minion at the start of the game
 * and every 5 turns
 */
class Nexus : public CustomBuildingBase
{
public:
    Nexus() = delete;

    explicit Nexus(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const AdvancedResourceMap buildcost = {},
            const AdvancedResourceMap production = NEXUS_PRODUCE,
            int health =5,
            int attack = 0

            );

    /**
     * @brief Default destructor.
     */
    ~Nexus() override= default;
     std::string getType() const override;

}; // class Nexus

} // namespace Whiskas


#endif // NEXUS_H
