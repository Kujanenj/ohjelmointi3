#ifndef DESERT_H
#define DESERT_H

#include "tiles/tilebase.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"

namespace Whiskas {



class Desert : public Course::TileBase
{
public:
    Desert() = delete;


    explicit Desert(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 1,
           const Course::ResourceMap& production = {});

    virtual ~Desert() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Desert

} // namespace Whiskas


#endif // DESERT_H
