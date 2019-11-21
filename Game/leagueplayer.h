#ifndef LEAGUEPLAYER_H
#define LEAGUEPLAYER_H

#include "core/playerbase.h"
#include "AdvancedResourcses/AdvancedResourceMaps.h"
namespace Whiskas {


class LeaguePlayer : public Course::PlayerBase
{
public:
    LeaguePlayer(std::string name,
                 AdvancedResourceMap playerItems=PLAYER_ITEMS);
    AdvancedResourceMap getItems();
    void setPlayerItems(AdvancedResourceMap toSet);
private:
    AdvancedResourceMap playerItems_;
};
}
#endif // LEAGUEPLAYER_H
