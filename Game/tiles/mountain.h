#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "tiles/tilebase.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"


namespace Whiskas {



class Mountain : public Course::TileBase
{
public:
    Mountain() = delete;


    explicit Mountain(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 1,
                      const Course::ResourceMap& production = {});

    virtual ~Mountain() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Mountain

} // namespace Whiskas




#endif // MOUNTAIN_H
