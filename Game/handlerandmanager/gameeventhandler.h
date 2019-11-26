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
/**
 * @brief The gameEventHandler class Handles events the game can have. Most notably, the mouse presses.
 */
class gameEventHandler : public Course::iGameEventHandler
{
public:
    /**
     * @brief Constructor
     * @param turn For easier accsess to the turn class
     */
    gameEventHandler(std::shared_ptr<Turn> turn);
    /**
     * @brief modifyResources Does nothing, since the game doesent use Course::resourceMap
     * @param player does nothing
     * @param resources does even less of anything
     * @return  true, but what is the point
     */
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources) override;
    /**
     See above!
     */
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount) override;
    /**
     * @brief subtractPlayerResources Reduces items from the player inventory.
     * @param player Target player
     * @param costs The amount to be reduced
     * @return true if player had enough items, false otherwise.
     */
    bool subtractPlayerResources(std::shared_ptr<LeaguePlayer> player, AdvancedResourceMap costs);
    /**
     * @brief handleMwindowClick checks if the click was right, or left
     * @param scene passed on to other methods
     * @param manager passed on to other methods
     * @param event Right or left Click
     */
    void handleMwindowClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager, QMouseEvent event);
    /**
     * @brief handleLeftClick Handles the left mouse button event, sets active tile and active minion
     * @param scene The game scene
     * @param manager The gameManager
     */
    void handleLeftClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager);
    /**
     * @brief handleRightClick Handles the right mouse button event. Moves minions
     * @param manager The gameManager
     * @param scene The gameScene
     */
    void handleRightClick(std::shared_ptr<gameManager> manager, std::shared_ptr<GameScene> scene);

    /**
     * @brief getActiveTile Gets the last tile that was clicked
     * @return The tile Clicked on
     */
    std::shared_ptr<Course::TileBase> getActiveTile();
    /**
     * @brief setActiveTile Sets the active tile to be a desired tile
     * @param activeTile
     */
    void setActiveTile(std::shared_ptr<Course::TileBase> activeTile);
    /**
     * @brief getActiveMinion returns the last active minion
     * @return ptr to active minion
     */
    std::shared_ptr<Minion> getActiveMinion();
    /**
     * @brief getTurn
     * @return The turn instance
     */
    std::shared_ptr<Turn> getTurn();
    /**
     * @brief endTurn Calls spawn minions on a desired turn
     * @param manager GameManager
     * @param handler HandlerInstance
     */
    void endTurn(std::shared_ptr<gameManager> manager, std::shared_ptr<gameEventHandler> handler);

private:
    std::shared_ptr<Course::TileBase> activeTile_ = nullptr;
    std::shared_ptr<Minion> activeMinion_=nullptr;
    std::shared_ptr<Turn> turn_=nullptr;

};


}
#endif // gameEventHandler_H
