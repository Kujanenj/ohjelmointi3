#include "rangedaltar.h"
namespace Whiskas {


RangedAltar::RangedAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                         const std::shared_ptr<gameManager>& objectmanager,
                         const std::shared_ptr<Course::PlayerBase>& owner):
      AltarBase(eventhandler,objectmanager,owner)
{
cooldown_=0;
}

void RangedAltar::upgradeMinion()
{
    if(cooldown_<=0){
    qDebug()<<"Upgrading ranged minion";
     for(const auto &it: manager_->getMinionVector()){

         if(currentLocationTile()->getWorkerCount()!=0){
             qDebug()<<"MinionVec not 0";
             qDebug()<<"Comparing"<<it->ID<<"To"<<currentLocationTile()->getWorkers().at(0)->ID;
         if(it->ID==currentLocationTile()->getWorkers().at(0)->ID && it->getType()=="Minion"){
             qDebug()<<"Engage upgrade";
             manager_->destroyObject(it);
             manager_->spawnMinion(handler_,
                                   manager_,
                                   owner_,
                                   currentLocationTile(),
                                   "Ranged");
             return;
         }

         }
     }}
    cooldown_-=1;
     qDebug()<<"Nothing to upgrade on ranged altar";

}

std::string RangedAltar::getType() const
{
    return "Ranged Altar";
}
}
