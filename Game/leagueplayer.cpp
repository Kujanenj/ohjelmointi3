#include "leagueplayer.h"
#include <QDebug>
#include <utility>
namespace Whiskas {


LeaguePlayer::LeaguePlayer(const std::string& name,
                           AdvancedResourceMap playerItems):
    Course::PlayerBase(name),
    playerItems_(std::move(playerItems))
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
    qDebug()<<"setting player"<<QString::fromStdString(getName());
    playerItems_=std::move(toSet);
    qDebug()<<"afther set";
    std::map<AdvancedResources, int>::iterator it;
    for(it=playerItems_.begin(); it!=playerItems_.end(); it++){
        qDebug()<<it->first<<it->second;
    }
}
}
