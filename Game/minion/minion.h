#ifndef MINION_H
#define MINION_H

#include "core/placeablegameobject.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"
#include "core/playerbase.h"
#include "core/coordinate.h"

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
private:
    std::weak_ptr<Course::TileBase> currentTile_;
};

#endif // MINION_H
