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
    void getItems();
private:
    AdvancedResourceMap playerItems_;
};
}
#endif // LEAGUEPLAYER_H
