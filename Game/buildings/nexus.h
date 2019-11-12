#ifndef NEXUS_H
#define NEXUS_H

#include "buildings/buildingbase.h"
#include "core/resourcemaps.h"

#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"

#include "core/playerbase.h"


class gameManager;
class gameEventHandler;

static const Course::ResourceMap OUTPOST_PRODUCTIONMAP = {
  {Course::BasicResource::MONEY, -10}
};

/**
 * @brief The Outpost class represents a player's Outpost-building.
 *
 * It can be constructed on any tile that has not been claimed by any other
 * player. \n
 * Effects: Claims surrounding unclaimed tiles. \n
 * Radius: 1 tiles\n
 * Production: -10 money (upkeep)\n
 *
 */
class Nexus : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Nexus() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    Nexus(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::OUTPOST_BUILD_COST,
            const Course::ResourceMap& production = Course::ConstResourceMaps::OUTPOST_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Nexus() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Sets neighbouring Tiles' ownership to this building's
     * ownership in 1 tile-radius, if the Tiles don't already have an owner.
     * @post Exception guarantee: Basic
     */
    virtual void onBuildAction() override;

    /**
     * @brief getProduction
     * @return
     * @post Exception guarantee: Basic
     */
    virtual Course::ResourceMap getProduction() override;

}; // class Outpost

 // namespace Course


#endif // OUTPOST_H
