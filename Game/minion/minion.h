#ifndef MINION_H
#define MINION_H

#include "core/placeablegameobject.h"
#include "handlerandmanager/gameeventhandler.h"
#include "handlerandmanager/gamemanager.h"
#include "core/playerbase.h"
#include "core/coordinate.h"
#include "core/playerbase.h"
#include "unit.h"
#include "attackable.h"

namespace Whiskas {

class gameManager;
class gameEventHandler;
class Minion : public Course::WorkerBase, public Unit, public Attackable
{
public:
    Minion()=delete;
    Minion(const std::shared_ptr<gameEventHandler>& handler,
           const std::shared_ptr<gameManager>& manager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           int movement=1,
           int health=3,
           int attack=1);

    void doSpecialAction() override;
    virtual ~Minion() = default;

    virtual std::string getType() const override;
protected:
    std::shared_ptr<gameManager> manager_;
private:
    std::weak_ptr<Course::TileBase> currentTile_;


};

}
#endif // MINION_H
