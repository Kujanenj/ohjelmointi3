#include "minion.h"

minion::minion(const std::shared_ptr<gameEventHandler>& handler,
               const std::shared_ptr<gameManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner):
    Course::WorkerBase(handler, manager, owner)
{
    qDebug()<<"minion got made";
}

void minion::doSpecialAction()
{
 qDebug()<<"nada";
}
