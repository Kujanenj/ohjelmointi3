#include "minion.h"

namespace Whiskas {

Minion::Minion(const std::shared_ptr<gameEventHandler>& handler,
               const std::shared_ptr<gameManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               int movement,
               int health,
               int attack):
    Course::WorkerBase(handler, manager, owner),
    Unit(movement),
    Attackable(health,attack, ID)
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

}
