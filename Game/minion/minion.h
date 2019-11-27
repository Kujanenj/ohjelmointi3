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
/**
 * @brief The Minion class is a subtype of worker
 * It can be upgraded to champions using altars
 * Is attackable and a unit (so it can attack and move)
 */
class Minion : public Course::WorkerBase, public Unit, public Attackable
{
public:
    Minion()=delete; //Delete default constructor


    Minion(const std::shared_ptr<Course::iGameEventHandler>& handler,
           const std::shared_ptr<Course::iObjectManager>& manager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           int movement=1,
           int health=3,
           int attack=1,
           int numberOfattacks=1,
           const AdvancedResourceMap cost={});
    /**
     * @brief doSpecialAction does nothing, nada. Need to declare it for inheritance
     */
    void doSpecialAction() override;
    virtual ~Minion() = default;

    virtual std::string getType() const override;
    /**
     * @brief modifyHealth if a minion takes more than 1 dmg from an attack,
     * its instantly slain. Weaklings
     * @param hModifier
     * @return true if dead, false otherwise
     */
    virtual bool modifyHealth(int hModifier) override;



protected:
    std::shared_ptr<gameManager> manager_;
   AdvancedResourceMap testCost_;

private:
    std::weak_ptr<Course::TileBase> currentTile_;



};

}
#endif // MINION_H
