#ifndef gameEventHandler_H
#define gameEventHandler_H
#include "interfaces/igameeventhandler.h"
#include "graphics/gamescene.h"
#include "gamemanager.h"
#include "minion/minion.h"

#include "minion/magicchampion.h"
#include "minion/rangedchampion.h"
#include "meleechampion.h"
#include "turn.h"
#include <QDebug>
#include <QMouseEvent>
#include "leagueplayer.h"
namespace Whiskas {

class Turn;
class Minion;
class gameManager;
class gameEventHandler : public Course::iGameEventHandler
{
public:
    gameEventHandler(std::shared_ptr<Turn> turn);
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources) override;
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount) override;
    bool subtractPlayerResources(std::shared_ptr<LeaguePlayer> test, AdvancedResourceMap costs);
    /*!
     * \brief Handles both the right click and left click ;)
     * \param scene
     * \param manager
     * \param event
     */
    void handleMwindowClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager, QMouseEvent event);

    void handleLeftClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager);

    void handleRightClick(std::shared_ptr<gameManager> manager, std::shared_ptr<GameScene> scene);

    /*!
     * \brief is called when a click happens in mwindow. Sets the current active tile to the one clicked (if 
     * the click was on a tile) and checks for minions on the tile. If a minion exsist on the tile, set it as active
     * \param scene
     * \param manager
     */
    void handleMwindowClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager);

    std::shared_ptr<Course::TileBase> getActiveTile();
    void setActiveTile(std::shared_ptr<Course::TileBase> activeTile);
    std::shared_ptr<Minion> getActiveMinion();
    std::shared_ptr<Turn> getTurn();
    void endTurn(std::shared_ptr<gameManager> manager, std::shared_ptr<gameEventHandler> handler);

private:
    std::shared_ptr<Course::TileBase> activeTile_ = nullptr;
    std::shared_ptr<Minion> activeMinion_=nullptr;
    std::shared_ptr<Turn> turn_=nullptr;

};


}
#endif // gameEventHandler_H
