#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "tiles/tilebase.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"


namespace Whiskas {


/**
 * @brief The Mountain class represents Mountain in the gameworld.
 *
 * Forest has BasicProduction: \n
 * * Money = 1
 * * Food = 3
 * * Wood = 5
 * * Stone = 1
 * * Ore = 0
 *
 * Building in the forest takes time. So buildings get extra hold-marker.
 *
 * Tile supports 2 buildings.
 */
class Mountain : public Course::TileBase
{
public:
    Mountain() = delete;


    explicit Mountain(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
                      const Course::ResourceMap& production = {});

    virtual ~Mountain() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Mountain

} // namespace Whiskas




#endif // MOUNTAIN_H
