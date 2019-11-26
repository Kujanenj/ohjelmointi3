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
#include "leagueplayer.h"
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
    /**
     * @brief gameManager is a class that manages the game logic.
     * It has access to allmost all the classes included in this game.
     * @param m_gamescene for easier access to graphics
     */
    explicit gameManager(std::shared_ptr<GameScene>& m_gamescene);

    /*!
     * \brief Copies the tilesvector to managers own private vector
     * \param vector to be copied
     * \post  Exception guarantee: strong
     */
    void addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles) override;
    /**
     * @brief Adds a single tile to the private tile vector
     * @param tile to be added
     */
    void addTile(std::shared_ptr<Course::TileBase> tile);
    /**
     * @brief Return a tile matching the object ID
     * @param ID
     * @return matching tile
     */
    std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId &id) override;
    /**
     * @brief Return a tile matching the Coordinate
     * @param coordinate
     * @return matching tile
     */

    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate &coordinate) override;

    /**
     * @brief getTiles returns all tiles. This is a placeholder since this method is never used anywhere
     * @param coordinates unused
     * @return  all tiles in a vector
     */
    std::vector<std::shared_ptr<Course::TileBase> > getTiles(const std::vector<Course::Coordinate> &coordinates) override;

    /**
     * @brief getTileVector returns all tiles the gamemanager has.
     * @return Vector containing all the tiles.
     */

    std::vector<std::shared_ptr<Course::TileBase> > getTileVector();
    /**
     * @brief getBuildingVector returns all the bulding the gamemanager has.
     * @return Vector containing all the buildings
     */
    std::vector<std::shared_ptr<CustomBuildingBase>>getBuildingVector();
    /*!
     * \brief Returns a  vector of all the minions in excistance. In every multiverse.
     * \return Vector containing all the minions.
     */
    std::vector<std::shared_ptr<Minion>> getMinionVector();
    /**
     * @brief getPlayerPair Returns both players in the game
     * @return a pair containing both players
     */
    std::pair<std::shared_ptr<Whiskas::LeaguePlayer>,
    std::shared_ptr<Whiskas::LeaguePlayer>> getPlayerPair();
    /**
     * @brief addBuilding adds a building pointer to the building vector and all attackables
     * vector. (Since buildings are attackable).
     * @param building to be added
     */
    void addBuilding(std::shared_ptr<CustomBuildingBase>& building);
    /**
     * @brief Copies the player pair for managers own use
     * @param player to be copied
     */
   void addPlayer(std::pair<
                   std::shared_ptr<Whiskas::LeaguePlayer>,
                   std::shared_ptr<Whiskas::LeaguePlayer>>& player);


   /**
     * @brief addMinion adds a minion ptr to gameManagers own minion vector and attackables
     * vector
     * @param Minion to be added
     */
    void addMinion(std::shared_ptr<Minion> Minion);
    /**
     * @brief spawnMinion Spawns a new minion to desired tile.
     * @param handler minions own handler
     * @param manager Recieves the minion
     * @param owner Who controls the minion
     * @param location where the minion spawns
     * @param type of minion to be spawned(Eg:minion,mage..)
     * @return true if succefull, false otherwise
     */
    bool spawnMinion(std::shared_ptr<gameEventHandler> handler,
                                        std::shared_ptr<Course::iObjectManager> manager,
                                        std::shared_ptr<Course::PlayerBase> owner,
                                        std::shared_ptr<Course::TileBase> location,
                                        std::string type);



    //The type of building to be created
    template<typename buildingType>
    /**
     * @brief spawnBuilding  Spawns a new building of specific type.
     * IMPLEMENTATION IN FUNCTIONS.CPP
     * @param handler buildings handler
     * @param manager recieves the tile
     * @param player who owns the tile
     * @return false if failed, true otherwise
     */
    bool spawnBuilding(std::shared_ptr<gameEventHandler> handler,
                       std::shared_ptr<gameManager> manager,
                       std::shared_ptr<Course::PlayerBase> player);
    /**
     * @brief move Tries to move a minion to the target tile. Checks for movement range,
     * collision and possible enemies. If enemies are found, tries to attack them.
     * @param minionToMove The minion doing the moving
     * @param targetTile Destination
     */
    void move(std::shared_ptr<Minion> minionToMove,
              std::shared_ptr<Course::TileBase> targetTile);

    /**
     * @brief attack Select minion tries to deal its damage to target attackable.
     * If target hp goes to 0, tries to destroy it
     * @param minionToAttack Minion doing the attacking
     * @param toAttack The target
     */
    void attack(std::shared_ptr<Minion> minionToAttack,
                std::shared_ptr<Attackable> toAttack);
    /**
     * @brief checkForEnemies Check if target tile contains minions or buildings
     * of the other player
     * @param minionTomove Minion doing the moving
     * @param targetTile Destination
     * @return true if enemies, false if no
     */
    bool checkForEnemies(std::shared_ptr<Minion>minionTomove,
                         std::shared_ptr<Course::TileBase>targetTile);
    /**
     * @brief selectAttackTarget Returns a attackable ptr for someone to attack. Minions have priority.
     * @param targetTile
     * @return Attcable ptr if succsefull, nullptr if something goes wrong
     */
    std::shared_ptr<Attackable> selectAttackTarget(std::shared_ptr<Course::TileBase> targetTile);
    /**
     * @brief attackMultiple Used by the mage minion to attack in an area. Attacks all minions in a radius of 1.
     * @param minionToAttack Minion doing the attacking
     * @param targetTile
     */
    void attackMultiple(std::shared_ptr<Minion> minionToAttack, std::shared_ptr<Course::TileBase> targetTile);
    /**
     * @brief destroyObject Takes an attackable object, and removes it from all databases.
     * (Gamemanager vectors, tileWorkers, Tilebuildings, scene_items...)
     * Also checks if the destroyed object is a Nexus. If it is, win the game.
     * @param ObjectToDestroy the object to be destroyed
     */
    void destroyObject(std::shared_ptr<Attackable> ObjectToDestroy);
    /**
     * @brief getNexusLocation Returns a tile containing the nexus of the desired player
     * @param owner Desired player
     * @return  Tile containing the Nexus
     */
    std::shared_ptr<Course::TileBase> getNexusLocation(std::shared_ptr<LeaguePlayer> owner);
    /**
     * @brief getWinner Get the winning player
      * @return ptr to the player who won the game
     */
    std::shared_ptr<LeaguePlayer> getWinner();


private:
    std::vector<std::shared_ptr<Course::TileBase> > alltiles_;

    std::vector<std::shared_ptr<CustomBuildingBase>> allbuildings_;
    std::vector<std::shared_ptr<Minion>> allminions_;
    std::vector<std::shared_ptr<Attackable>> allattackables_;
    std::pair<std::shared_ptr<Whiskas::LeaguePlayer>,std::shared_ptr<Whiskas::LeaguePlayer>> players_;
    std::shared_ptr<GameScene> manager_gamescene; //The game scene
    std::shared_ptr<LeaguePlayer>winner_=nullptr;
};

}

#endif // TESTTILEMANAGER_H
