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

AdvancedResourceMap LeaguePlayer::getItems()
{
    qDebug()<<"Getting player items";
    std::map<AdvancedResources, int>::iterator it;
    for(it=playerItems_.begin(); it!=playerItems_.end(); it++){
        qDebug()<<it->first<<it->second;
    }
    return playerItems_;
}

void LeaguePlayer::setPlayerItems(AdvancedResourceMap toSet)
{
    playerItems_=toSet;
    qDebug()<<"afther set";
    std::map<AdvancedResources, int>::iterator it;
    for(it=playerItems_.begin(); it!=playerItems_.end(); it++){
        qDebug()<<it->first<<it->second;
    }
}
}
