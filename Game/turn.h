#ifndef TURN_H
#define TURN_H


#include "handlerandmanager/gamemanager.h"

namespace Whiskas {

class gameManager;
class LeaguePlayer;
/**
 * @brief The Turn class Handles the turn event. Updates the player inventories, resets
 * attacked and moved for units
 */
class Turn
{
public:
    /**
     * @brief Turn Constructor
     * @param manager The gameManager
     */
    Turn(const std::shared_ptr<gameManager>& manager);
    /**
     * @brief getInTurn Get the current player
     * @return Ptr to current player
     */
    std::shared_ptr<LeaguePlayer> getInTurn();
    /**
     * @brief swapTurn Swap the player in turn, and reset the attacked and moved statuses
     * Generate resources for players
     */
    void swapTurn();
    /**
     * @brief getTurnCounter
     * @return the current turn number
     */
    int getTurnCounter();
    /**
     * @brief setInTurn forfefully modify the current player
     * @param ToBeInTurn
     */
    void setInTurn(std::shared_ptr<LeaguePlayer> ToBeInTurn);

private:
    std::shared_ptr<LeaguePlayer> playerInTurn_=nullptr;
    std::shared_ptr<gameManager> manager_=nullptr;
    int turnCounter_=0;
};
}
#endif // TURN_H
