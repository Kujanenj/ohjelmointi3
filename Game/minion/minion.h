#ifndef MINION_H
#define MINION_H

#include "core/placeablegameobject.h"

#include "core/playerbase.h"
#include "core/coordinate.h"
#include "workers/workerbase.h"
#include "unit.h"
#include "attackable.h"

#include <QDebug>



#include "AdvancedResourcses/AdvancedResourceMaps.h"
namespace Whiskas {

class gameManager;
class gameEventHandler;

class Minion : public Course::WorkerBase, public Unit, public Attackable
{
public:
    Minion()=delete;
    Minion(const std::shared_ptr<Course::iGameEventHandler>& handler,
           const std::shared_ptr<Course::iObjectManager>& manager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           int movement=1,
           int health=3,
           int attack=1,
           int numberOfattacks=1,
           const TestMap cost=MINION_COST);

    void doSpecialAction() override;
    virtual ~Minion() = default;

    virtual std::string getType() const override;
    virtual bool modifyHealth(int hModifier) override;
    void getCosts();

protected:
    std::shared_ptr<gameManager> manager_;
    TestMap testCost_;

private:
    std::weak_ptr<Course::TileBase> currentTile_;



};

}
#endif // MINION_H
