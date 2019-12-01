#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "core/gameobject.h"

#include "tiles/desert.h"
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
// Map containing types of tiles a building can be built on
/*const std::map<std::string, std::vector<std::string>> buildingAvailability={
    {"Nexus",{"Desert","Jungle","Mountain","Spring"}},
    {{"Melee Altar"},{"Desert", "Mountain"}},
    {{"Ranged Altar"},{"Jungle"}},
    {{"Mage Altar"},{"Spring"}},
    {{"Quarry"},{"Mountain"}},
    {{"Sawmill"},{"Jungle"}},
    {{"Lifepump"},{"Spring"}}
};*/





/*!
 * \brief selectBuildingTypef selects the type of building to be built
 * \param type the type of building
 * \param handler gameHandler
 * \param manager Gamemanager
 * \param player  the owner of the new building
 */
void selectBuildingTypef(const std::string& type, const std::shared_ptr<gameEventHandler>& handler,
                        const std::shared_ptr<gameManager>& manager,
                        const std::shared_ptr<LeaguePlayer>& player);


/*!
 * \brief checkBuildingAvailability checks if building can be built on tile
 * \param targetTile
 * \param type the type of building to be checked
 * \return true if can be built, false if not
 */
bool checkBuildingAvailability(const std::shared_ptr<Course::TileBase> &targetTile,
                               const std::string &type);
/*!
 * \brief makeAdvancedWGenerator generates the coordinates for the map. If a generated tile
 * is touching a desert or a spring, it is more likely to be generated as such aswell
 * \param mapsize
 * \param handler gamehandler
 * \param manager gameManager
 */
void makeAdvancedWGenerator(int mapsize,
                                const std::shared_ptr<gameEventHandler>& handler,
                                const std::shared_ptr<gameManager>& manager);
template<typename TileType>
/*!
 * \brief makeAdvancedWorld spawns the tiles on desired location
 * \param loc coordinate where the tile is
 * \param handler
 * \param manager
 */
void makeAdvancedWorld(Course::Coordinate loc,
                       std::shared_ptr<gameEventHandler> handler,
                       std::shared_ptr<gameManager> manager);
}
#endif // FUNCTIONS_H

