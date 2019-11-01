#ifndef TEST_FEATURES_H
#define TEST_FEATURES_H

#include "core/gameobject.h"
#include "mapwindow.hh"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "core/coordinate.h"
#include "core/worldgenerator.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"
#include "gamemanager.h"
#include "tiles/tilebase.h"
#include "gameeventhandler.h"
using namespace Course;

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


void startGame();


#endif // TEST_FEATURES_H

