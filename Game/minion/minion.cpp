#include "minion.h"

minion::minion(const std::shared_ptr<gameEventHandler>& handler,
               const std::shared_ptr<gameManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner):
    Course::WorkerBase(handler, manager, owner)
{
    /*std::string a = getOwner()->getName();
    QString b = QString::fromStdString(a);
    qDebug()<<"minion got made"<< "owner:"<<b ;*/
}

void minion::doSpecialAction()
{
 qDebug()<<"nada";
}

std::string minion::getType() const
{
    return "Minion";
}
