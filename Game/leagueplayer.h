#ifndef LEAGUEPLAYER_H
#define LEAGUEPLAYER_H

#include "core/playerbase.h"
#include "AdvancedResourcses/AdvancedResourceMaps.h"
namespace Whiskas {

/**
 * @brief The LeaguePlayer class The playerClass for this game.
 */
class LeaguePlayer : public Course::PlayerBase
{
public:
    /**
     * @brief LeaguePlayer Constructor
     * @param name
     * @param playerItems Resource the player has at the start of the game
     */
    LeaguePlayer(const std::string& name,
                 AdvancedResourceMap playerItems=PLAYER_ITEMS);
    AdvancedResourceMap getItems();
    /**
     * @brief setPlayerItems sets the player items to be equal to the parameter map
     * @param toSet New items
     */
    void setPlayerItems(AdvancedResourceMap toSet);
private:
    AdvancedResourceMap playerItems_;

};
}
#endif // LEAGUEPLAYER_H
