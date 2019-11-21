#ifndef NEXUS_H
#define NEXUS_H

#include "buildings/custombuildingbase.h"
#include "core/resourcemaps.h"

namespace Whiskas {



static const Course::ResourceMap OUTPOST_PRODUCTIONMAP = {
  {Course::BasicResource::MONEY, -10}
};



class Nexus : public CustomBuildingBase

{
public:
    Nexus() = delete;

    explicit Nexus(
            const std::shared_ptr<gameEventHandler>& eventhandler,
            const std::shared_ptr<gameManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Course::ConstResourceMaps::OUTPOST_BUILD_COST,
            const AdvancedResourceMap production = TEST_BUILDING_PRODUCE,
            int health =5,
            int attack = 0

            );

    /**
     * @brief Default destructor.
     */
    virtual ~Nexus() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
    virtual void onBuildAction() override;

    /**
     * @brief getProduction
     * @return
     * @post Exception guarantee: Basic
     */
    virtual Course::ResourceMap getProduction() override;

}; // class Nexus

} // namespace Whiskas


#endif // NEXUS_H
