#ifndef gameEventHandler_H
#define gameEventHandler_H
#include "interfaces/igameeventhandler.h"
#include "gamescene.h"
#include "gamemanager.h"

#include <QDebug>



class gameEventHandler : public Course::iGameEventHandler
{
public:
    gameEventHandler();
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources) override;
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount) override;
    void handleMwindowClick(std::shared_ptr<GameScene> scene, std::shared_ptr<gameManager> manager);
    std::shared_ptr<Course::TileBase> getActiveTile();
private:
    std::shared_ptr<Course::TileBase> activeTile = nullptr;

};

#endif // gameEventHandler_H
