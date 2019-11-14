#ifndef gameEventHandler_H
#define gameEventHandler_H
#include "interfaces/igameeventhandler.h"
#include "graphics/gamescene.h"
#include "gamemanager.h"
#include "minion/minion.h"
#include <QDebug>
#include <QMouseEvent>

class minion;
class gameManager;
class gameEventHandler : public Course::iGameEventHandler
{
public:
    gameEventHandler();
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources) override;
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount) override;

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



private:
    std::shared_ptr<Course::TileBase> activeTile_ = nullptr;
    std::shared_ptr<minion> activeMinion_=nullptr;

};

#endif // gameEventHandler_H
