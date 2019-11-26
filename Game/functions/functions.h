#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "core/gameobject.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "tiles/mountain.h"
#include "tiles/jungle.h"
#include "tiles/spring.h"

#include "core/coordinate.h"
#include "core/worldgenerator.h"

#include "handlerandmanager/gameeventhandler.h"
#include "tiles/tilebase.h"
#include "handlerandmanager/gamemanager.h"
#include "buildings/headquarters.h"
#include "buildings/nexus.h"
#include "buildings/meleealtar.h"


namespace Whiskas {

const std::map<std::string, std::vector<std::string>> buildingAvailability={
    {"Nexus",{"Forest","Jungle","Mountain","Spring"}},
    {{"Melee"},{"Forest"}},
    {{"Ranged"},{"Forest"}},
    {{"Mage"},{"Forest"}}
};
/*!
 * \brief makeWorldGenerator
 * Initializes a worldgenerator class, and genereates a random map.
 * \param mapsize_x
 * \param mapsize_y
 * \param seed
 * \param handler
 * \param manager
 *  manager recieves a vector of all map tiles
 */
void makeWorldGenerator(int mapsize_x, int mapsize_y, int seed,
                        std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager);





void selectBuildingTypef(std::string type, std::shared_ptr<gameEventHandler> handler,
                        std::shared_ptr<gameManager> manager,
                        std::shared_ptr<Course::PlayerBase> player);



bool checkBuildingAvailability(std::shared_ptr<Course::TileBase> targetTile,
                               std::string type);

void makeAdvancedWGenerator(int mapsize,
                                std::shared_ptr<gameEventHandler> handler,
                                std::shared_ptr<gameManager> manager);
template<typename TileType>
void makeAdvancedWorld(Course::Coordinate loc,
                       std::shared_ptr<gameEventHandler> handler,
                       std::shared_ptr<gameManager> manager);
}
#endif // FUNCTIONS_H

