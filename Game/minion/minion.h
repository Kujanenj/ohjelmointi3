#ifndef MINION_H
#define MINION_H

#include "core/placeablegameobject.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"
#include "core/playerbase.h"
#include "core/coordinate.h"
#include "core/playerbase.h"
class gameManager;
class gameEventHandler;
class minion : public Course::WorkerBase
{
public:
    minion()=delete;
    minion(const std::shared_ptr<gameEventHandler>& handler,
           const std::shared_ptr<gameManager>& manager,
           const std::shared_ptr<Course::PlayerBase>& owner);

    void doSpecialAction() override;
    virtual ~minion() = default;
    int getMoveValue();
    void setMoved(bool hasMoved);
    bool getMoved();

private:
    std::weak_ptr<Course::TileBase> currentTile_;
private:
    int movement_=1;
    bool hasMoved_=false;
};

#endif // MINION_H
