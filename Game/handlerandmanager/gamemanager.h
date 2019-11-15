#ifndef TESTTILEMANAGER_H
#define TESTTILEMANAGER_H
#include "interfaces/iobjectmanager.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "core/worldgenerator.h"
#include "buildings/buildingbase.h"
#include "minion/minion.h"
#include "gameeventhandler.h"
#include <vector>

#include "buildings/nexus.h"
#include "graphics/mapitem.h"

class minion;
class gameEventHandler;
class gameManager : public Course::iObjectManager

{
public:
    explicit gameManager(std::shared_ptr<GameScene>& m_gamescene);


    void addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles) override;
    std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId &id) override;

    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate &coordinate) override;

    std::vector<std::shared_ptr<Course::TileBase> > getTiles(const std::vector<Course::Coordinate> &coordinates) override;

    std::vector<std::shared_ptr<Course::TileBase> > returntilevector();
    /*!
     * \brief get vector of all the minions in excistance. In every multiverse.
     * \return
     */
    std::vector<std::shared_ptr<minion>> getMinionVector();
    /*!
     * \brief adds the building to the allbuildings_ vector
     * \param Building
     * \return
     */
    bool addBuilding(std::shared_ptr<Course::BuildingBase>& building);
    /*!
     * \brief adds a minion to allMinions_ vector
     * \param minion
     * \return
     */
    bool addMinion(std::shared_ptr<minion>& minion);
    /*!
     * \brief spawns a new minion object to latest active tile.
     * \param handler <-- minions new handler
     * \param manager <-- minions new manager
     * \param owner  <-- player who owns the minion
     * \param location <-- tile where the minion spawns
     */
    void spawnMinion(std::shared_ptr<gameEventHandler> handler,
                                        std::shared_ptr<gameManager> manager,
                                        std::shared_ptr<Course::PlayerBase> owner,
                                        std::shared_ptr<Course::TileBase> location);

    void spawnNexus(std::shared_ptr<gameEventHandler> handler,
                                        std::shared_ptr<gameManager> manager,
                                        std::shared_ptr<Course::PlayerBase> owner,
                                        std::shared_ptr<Course::TileBase> location);
private:
    std::vector<std::shared_ptr<Course::TileBase> > alltiles_;
    //Contains a pointer too all building in all tiles. This keeps the weak ptrs in tilebase
    //alive....This is just a workaround.
    std::vector<std::shared_ptr<Course::BuildingBase>> allbuildings_;
    std::vector<std::shared_ptr<minion>> allminions_;

    std::shared_ptr<GameScene> manager_gamescene;
};

#endif // TESTTILEMANAGER_H
