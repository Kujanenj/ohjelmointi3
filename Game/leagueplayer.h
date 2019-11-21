#ifndef LEAGUEPLAYER_H
#define LEAGUEPLAYER_H

#include "core/playerbase.h"
namespace Whiskas {


class LeaguePlayer : public Course::PlayerBase
{
public:
    LeaguePlayer(std::string name);
};
}
#endif // LEAGUEPLAYER_H
