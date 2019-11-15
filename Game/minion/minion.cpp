#include "minion.h"

minion::minion(const std::shared_ptr<gameEventHandler>& handler,
               const std::shared_ptr<gameManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               int movement,
               int health,
               int attack):
    Course::WorkerBase(handler, manager, owner),
    unit(movement),
    attackable(health,attack)
{

    lockEventHandler();
    qDebug()<<"minion got made";
}

void minion::doSpecialAction()
{
    qDebug()<<"nada";
}


