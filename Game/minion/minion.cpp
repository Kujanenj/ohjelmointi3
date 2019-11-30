#include "minion.h"

namespace Whiskas {

Minion::Minion(const std::shared_ptr<Course::iGameEventHandler>& handler,
               const std::shared_ptr<Course::iObjectManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               int movement,
               int health,
               int attack,
               int attacks,
               const AdvancedResourceMap& cost):
    Course::WorkerBase(handler, manager, owner),
    Unit(movement),
    Attackable(health,attack,attacks, ID)
{

    setDescription("Minion", "A basic fuksi/minion \n"
                             "Buildings can only be constructed\n"
                             "on top of minions.\n"
                             "Can be upgraded using altars\n"
                             "3 Health\n"
                             "1 Damage\n"
                             "1 Attack\n"
                             "1 Range/movement\n"
                             "has less than 300 fuksipoints");
    testCost_=cost;

    qDebug()<<"minion got made";

}

void Minion::doSpecialAction()
{
    qDebug()<<"nada";
}

std::string Minion::getType() const
{
    return "Minion";
}

bool Minion::modifyHealth(int hModifier)
{
    if(hModifier>=2){
        return true;
    }
    healthValue_+=hModifier;
    return healthValue_<=0;
}





}
