#ifndef LIFEPUMP_H
#define LIFEPUMP_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {

/**
 * @brief The Lifepump class represents a lifepump-building in the game.
 *
 * The lifepump produces 1 lifewater per turn
 * Can only be built on a spring
 */
class Lifepump : public CustomBuildingBase
{
public:
    Lifepump() = delete;

    explicit Lifepump(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const AdvancedResourceMap& buildcost = LIFEPUMP_COST,
            const AdvancedResourceMap& production = LIFEPUMP_PRODUCE,
            int health =5,
            int attack = 0

            );
    /**
     * @brief Default destructor.
     */
    ~Lifepump() override = default;
     std::string getType() const override;

}; // class Lifepump

} // namespace Whiskas

#endif // LIFEPUMP_H
