#include "minion.h"

namespace Whiskas {

Minion::Minion(const std::shared_ptr<Course::iGameEventHandler>& handler,
               const std::shared_ptr<Course::iObjectManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               int movement,
               int health,
               int attack,
               int attacks):
    Course::WorkerBase(handler, manager, owner),
    Unit(movement),
    Attackable(health,attack,attacks, ID)
{


    lockEventHandler();
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
    if(healthValue_<=0){
        return true;
    }
    return false;
}



}
