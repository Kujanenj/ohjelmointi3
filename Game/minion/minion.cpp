#include "minion.h"

minion::minion(const std::shared_ptr<gameEventHandler>& handler,
               const std::shared_ptr<gameManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner):
    Course::WorkerBase(handler, manager, owner)
{
    lockEventHandler();
    qDebug()<<"minion got made";
}

void minion::doSpecialAction()
{
    qDebug()<<"nada";
}

int minion::getMoveValue()
{
    return movement_;
}

void minion::setMoved(bool setMoved)
{
    hasMoved_=setMoved;
}

bool minion::getMoved(){
    return hasMoved_;
}

