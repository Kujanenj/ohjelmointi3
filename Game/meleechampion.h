#ifndef MELEECHAMPION_H
#define MELEECHAMPION_H

#include "minion/minion.h"
#include <QDebug>

namespace Whiskas {


class MeleeChampion : public Minion
{
public:
    MeleeChampion()=delete;
    MeleeChampion(const std::shared_ptr<Course::iGameEventHandler>& handler,
                  const std::shared_ptr<Course::iObjectManager>& manager,
                  const std::shared_ptr<Course::PlayerBase>& owner,
                  int movement=1,
                  int health=5,
                  int attack=2,
                  int numberOfAttacks=2);

    virtual std::string getType() const override;
    bool modifyHealth(int hModifier) override;
private:


};
}
#endif // MELEECHAMPION_H
