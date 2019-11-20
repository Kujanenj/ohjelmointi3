#include "minion.h"

namespace Whiskas {

Minion::Minion(const std::shared_ptr<Course::iGameEventHandler>& handler,
               const std::shared_ptr<Course::iObjectManager>& manager,
               const std::shared_ptr<Course::PlayerBase>& owner,
               int movement,
               int health,
               int attack):
    Course::WorkerBase(handler, manager, owner),
    Unit(movement),
    Attackable(health,attack, ID)
{
    /*std::string a = getOwner()->getName();
    QString b = QString::fromStdString(a);
    qDebug()<<"minion got made"<< "owner:"<<b ;*/

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
