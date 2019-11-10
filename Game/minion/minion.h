#ifndef MINION_H
#define MINION_H

#include "core/placeablegameobject.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"
#include "core/playerbase.h"
#include "core/coordinate.h"
class minion : public Course::PlaceableGameObject
{
public:
    minion()=delete;
    minion(const std::shared_ptr<gameEventHandler>& handler,
           const std::shared_ptr<gameManager>& manager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const std::shared_ptr<Course::Coordinate>& coordinate);
    virtual ~minion() = default;
};

#endif // MINION_H
