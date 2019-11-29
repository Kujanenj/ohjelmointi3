#ifndef DESERT_H
#define DESERT_H

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
class Desert : public Course::TileBase
{
public:
    Desert() = delete;


    explicit Desert(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 2,
           const unsigned int& max_work = 3,
           const Course::ResourceMap& production = {});

    ~Desert() override = default;

    std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Jungle

} // namespace Whiskas


#endif // DESERT_H
