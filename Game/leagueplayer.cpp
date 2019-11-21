#include "leagueplayer.h"
#include <QDebug>
namespace Whiskas {


LeaguePlayer::LeaguePlayer(std::string name,
                           AdvancedResourceMap playerItems):
    Course::PlayerBase(name),
    playerItems_(playerItems)
{
    qDebug()<<"league player";
}

void LeaguePlayer::getItems()
{
    std::map<AdvancedResources, int>::iterator it;
    for(it=playerItems_.begin(); it!=playerItems_.end(); it++){
        qDebug()<<it->first<<it->second;
    }
}
}
