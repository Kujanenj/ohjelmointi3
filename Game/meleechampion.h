#ifndef MELEECHAMPION_H
#define MELEECHAMPION_H

#include "minion/minion.h"

class meleeChampion :public minion
{
public:
    meleeChampion()=delete;
    meleeChampion(const std::shared_ptr<gameEventHandler>& handler,
                  const std::shared_ptr<gameManager>& manager,
                  const std::shared_ptr<Course::PlayerBase>& owner,
                  int movement=3);
};

#endif // MELEECHAMPION_H
