#ifndef TESTTILEMANAGER_H
#define TESTTILEMANAGER_H
#include "interfaces/iobjectmanager.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "core/worldgenerator.h"
#include "buildings/buildingbase.h"
#include <vector>

class GameEventHandler;
class gameManager : public Course::iObjectManager

{
public:
    gameManager();


    void addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles) override;
    std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId &id) override;

    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate &coordinate) override;

    std::vector<std::shared_ptr<Course::TileBase> > getTiles(const std::vector<Course::Coordinate> &coordinates) override;

    std::vector<std::shared_ptr<Course::TileBase> > returntilevector();
    /*!
     * \brief adds the building to the allbuildings_ vector
     * \param Building
     * \return
     */
    bool addBuilding(std::shared_ptr<Course::BuildingBase>& building);
private:
    std::vector<std::shared_ptr<Course::TileBase> > alltiles_;
    //Contains a pointer too all building in all tiles. This keeps the weak ptrs in tilebase
    //alive....This is just a workaround.
    std::vector<std::shared_ptr<Course::BuildingBase>> allbuildings_;
};

#endif // TESTTILEMANAGER_H
