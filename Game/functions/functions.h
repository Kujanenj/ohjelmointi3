#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "core/gameobject.h"

#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "core/coordinate.h"
#include "core/worldgenerator.h"

#include "handlerandmanager/gameeventhandler.h"
#include "tiles/tilebase.h"
#include "handlerandmanager/gamemanager.h"


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



/*!
 * \brief spawnBuilding
 * spanws and returns a building object. Type of bulding is passed by template.
 * \param handler
 * \param manager
 * \param player
 * \return
 */
template<typename buildingType>
std::shared_ptr<Course::BuildingBase> spawnBuilding(std::shared_ptr<gameEventHandler> handler,
                                                    std::shared_ptr<gameManager> manager,
                                                    std::shared_ptr<Course::PlayerBase> player){
    {
        qDebug()<<"Trying to spawn a building pointer in functions";
        std::shared_ptr<Course::BuildingBase> testBuilding = std::make_shared<buildingType>(handler,manager,player);

        qDebug() << QString::fromStdString(testBuilding->getType());
        return testBuilding;
    }

}
#endif // FUNCTIONS_H

