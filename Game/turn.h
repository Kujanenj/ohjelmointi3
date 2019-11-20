#ifndef TURN_H
#define TURN_H


#include "handlerandmanager/gamemanager.h"

namespace Whiskas {

class gameManager;

class Turn
{
public:
    Turn(std::shared_ptr<gameManager> manager);

    std::shared_ptr<Course::PlayerBase> getInTurn();
    void swapTurn();
private:
    std::shared_ptr<Course::PlayerBase> playerInTurn_=nullptr;
    std::shared_ptr<gameManager> manager_=nullptr;
};
}
#endif // TURN_H
