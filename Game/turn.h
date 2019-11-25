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
    int getTurnCounter();
    void setInTurn(std::shared_ptr<LeaguePlayer> ToBeInTurn);

private:
    std::shared_ptr<LeaguePlayer> playerInTurn_=nullptr;
    std::shared_ptr<gameManager> manager_=nullptr;
    int turnCounter_=0;
};
}
#endif // TURN_H
