#ifndef TURN_H
#define TURN_H


#include "handlerandmanager/gamemanager.h"

namespace Whiskas {

class gameManager;
class LeaguePlayer;
class Turn
{
public:
    Turn(std::shared_ptr<gameManager> manager);

    std::shared_ptr<LeaguePlayer> getInTurn();
    void swapTurn();
private:
    std::shared_ptr<LeaguePlayer> playerInTurn_=nullptr;
    std::shared_ptr<gameManager> manager_=nullptr;
};
}
#endif // TURN_H
