#ifndef JUNGLE_H
#define JUNGLE_H

#include "tiles/tilebase.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"


namespace Whiskas {


/**
 * @brief The Jungle class represents the jungle in the gameworld.
 * The jungle supports ranged altars and sawmills
 */
class Jungle : public Course::TileBase
{
public:
    Jungle() = delete;


    explicit Jungle(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 1,
           const Course::ResourceMap& production = {});

    ~Jungle() override = default;

    std::string getType() const override;

    //void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Jungle

} // namespace Whiskas


#endif // JUNGLE_H
