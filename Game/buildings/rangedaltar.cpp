#include "rangedaltar.h"
namespace Whiskas {


RangedAltar::RangedAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                         const std::shared_ptr<gameManager>& objectmanager,
                         const std::shared_ptr<Course::PlayerBase>& owner,
                         const int& tilespaces,
                         const AdvancedResourceMap buildcost,
                         const AdvancedResourceMap production):
      AltarBase(eventhandler,objectmanager,owner)
{

}

void RangedAltar::upgradeMinion()
{
    qDebug()<<"Upgrading ranged minion";
     for(auto it: manager_->getMinionVector()){

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
     }
     qDebug()<<"Nothing to upgrade on ranged altar";

}

std::string RangedAltar::getType() const
{
    return "Ranged Altar";
}
}
