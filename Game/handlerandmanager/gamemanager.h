#ifndef TESTTILEMANAGER_H
#define TESTTILEMANAGER_H
#include "interfaces/iobjectmanager.h"
//#include "tiles/forest.h"
//#include "tiles/grassland.h"
#include "core/worldgenerator.h"
#include "buildings/custombuildingbase.h"
#include "minion/minion.h"
#include "gameeventhandler.h"
#include <vector>

#include "graphics/mapitem.h"

namespace Whiskas {

class CustomBuildingBase;
class Attackable;
//class MeleeChampion;
//class Minion;
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
    std::vector<std::shared_ptr<Minion>> getMinionVector();
    /*!
     * \brief adds the building to the allbuildings_ vector
     * \param Building
     * \return
     */
    std::pair<std::shared_ptr<Course::PlayerBase>,
    std::shared_ptr<Course::PlayerBase>> getPlayerPair();
    bool addBuilding(std::shared_ptr<CustomBuildingBase>& building);
    /*!
     * \brief adds a minion to allMinions_ vector
     * \param minion
     * \return
     */

    bool addPlayer(std::pair<
                   std::shared_ptr<Course::PlayerBase>,
                   std::shared_ptr<Course::PlayerBase>>& player);


    bool addMinion(std::shared_ptr<Minion> Minion);

    /*!
     * \brief spawns a new minion object to latest active tile.
     * \param handler <-- minions new handler
     * \param manager <-- minions new manager
     * \param owner  <-- player who owns the minion
     * \param location <-- tile where the minion spawns
     */
    void spawnMinion(std::shared_ptr<Course::iGameEventHandler> handler,
                                        std::shared_ptr<Course::iObjectManager> manager,
                                        std::shared_ptr<Course::PlayerBase> owner,
                                        std::shared_ptr<Course::TileBase> location,
                                        std::string type);




    template<typename buildingType>
    bool spawnBuilding(std::shared_ptr<gameEventHandler> handler,
                       std::shared_ptr<gameManager> manager,
                       std::shared_ptr<Course::PlayerBase> player);
    /*!
     * \brief Takes a minion object, and tries to move it to the target tile. Checks for other objects. (CURRENTLY ONLY MINIONS!)
     * \param minionToMove
     * \param targetTile
     */
    void move(std::shared_ptr<Minion> minionToMove,
              std::shared_ptr<Course::TileBase> targetTile);

    void attack(std::shared_ptr<Minion> minionToMove,
                std::shared_ptr<Attackable> toAttack);
    bool checkForEnemies(std::shared_ptr<Minion>minionTomove,
                         std::shared_ptr<Course::TileBase>targetTile);
    std::shared_ptr<Attackable> selectAttackTarget(std::shared_ptr<Course::TileBase> targetTile);


    void destroyObject(std::shared_ptr<Attackable> minionToDestroy);

private:
    std::vector<std::shared_ptr<Course::TileBase> > alltiles_;
    //Contains a pointer too all building in all tiles. This keeps the weak ptrs in tilebase
    //alive....This is just a workaround.
    std::vector<std::shared_ptr<CustomBuildingBase>> allbuildings_;
    std::vector<std::shared_ptr<Minion>> allminions_;
    std::vector<std::shared_ptr<Attackable>> allattackables_;
    std::pair<std::shared_ptr<Course::PlayerBase>,std::shared_ptr<Course::PlayerBase>> players_;
    std::shared_ptr<GameScene> manager_gamescene;
};

}

#endif // TESTTILEMANAGER_H
