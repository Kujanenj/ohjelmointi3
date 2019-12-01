#ifndef gameEventHandler_H
#define gameEventHandler_H
#include "interfaces/igameeventhandler.h"
#include "graphics/gamescene.h"
#include "gamemanager.h"
#include "minion/minion.h"

#include "minion/magicchampion.h"
#include "minion/rangedchampion.h"
#include "minion/meleechampion.h"
#include "turn.h"
#include <QDebug>
#include <QMouseEvent>
#include <QTextBrowser>
#include "leagueplayer.h"

namespace Whiskas {

class Turn;
class Minion;
class gameManager;
/**
 * @brief The gameEventHandler class Handles events the game can have. Most notably, the mouse presses.
 * NOTE: The first few methods that have unused variables are there for the reason that course side
 * documentation said that those are required by the course side code. We dont use them but we didnt
 * know if we could remove them.
 */
class gameEventHandler : public Course::iGameEventHandler
{
public:
    /**
     * @brief Constructor
     * @param turn For easier accsess to the turn class
     * @param textBrowserRight for updating the right textBrowser
     */
    gameEventHandler(std::shared_ptr<Turn> turn, std::shared_ptr<QTextBrowser> textBrowserRight);
    /**
     * @brief modifyResources Does nothing, since the game doesent use Course::resourceMap
     * //NOTE: It was unclear if these methods could be removed, since Igameeventhandler defines these,
     * and it *IS" required by the course side.
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
    bool subtractPlayerResources(const std::shared_ptr<LeaguePlayer>& player, AdvancedResourceMap costs);
    /**
     * @brief handleMwindowClick checks if the click was right, or left
     * @param scene passed on to other methods
     * @param manager passed on to other methods
     * @param event Right or left Click
     */
    void handleMwindowClick(const std::shared_ptr<GameScene>& scene, const std::shared_ptr<gameManager>& manager, const QMouseEvent& event);
    /**
     * @brief handleLeftClick Handles the left mouse button event, sets active tile and active minion
     * @param scene The game scene
     * @param manager The gameManager
     */
    void handleLeftClick(const std::shared_ptr<GameScene>& scene, const std::shared_ptr<gameManager>& manager);
    /**
     * @brief handleRightClick Handles the right mouse button event. Moves minions
     * @param manager The gameManager
     * @param scene The gameScene
     */
    void handleRightClick(const std::shared_ptr<gameManager>& manager, const std::shared_ptr<GameScene>& scene);

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
    void endTurn(const std::shared_ptr<gameManager>& manager, const std::shared_ptr<gameEventHandler>& handler);



private:
    std::shared_ptr<Course::TileBase> activeTile_ = nullptr;
    std::shared_ptr<Minion> activeMinion_=nullptr;
    std::shared_ptr<Turn> turn_=nullptr;
    QString message_ = "";
    std::shared_ptr<QTextBrowser> textBrowserRight = nullptr;

};


}
#endif // gameEventHandler_H
