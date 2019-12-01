#ifndef SPRING_H
#define SPRING_H

#include "tiles/tilebase.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"


namespace Whiskas {



class Spring : public Course::TileBase
{
public:
    Spring() = delete;


    explicit Spring(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 1,
           const unsigned int& max_work = 1,
                    const Course::ResourceMap& production = {});

    virtual ~Spring() = default;

     std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;

}; // class Spring

} // namespace Whiskas


#endif // SPRING_H
