#include "magealtar.h"
namespace Whiskas {


MageAltar::MageAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                     const std::shared_ptr<gameManager>& objectmanager,
                     const std::shared_ptr<Course::PlayerBase>& owner,
                     const int& tilespaces,
                     const AdvancedResourceMap buildcost,
                     const AdvancedResourceMap production):
  AltarBase(eventhandler,objectmanager,owner)
{
cooldown_=20;
}

void MageAltar::upgradeMinion()
{
    if(cooldown_==0){


         for(auto it: manager_->getMinionVector()){
             if(currentLocationTile()->getWorkerCount()!=0){
             if(it==currentLocationTile()->getWorkers().at(0) && it->getType()=="Minion"){
                 manager_->destroyObject(it);
                 manager_->spawnMinion(handler_,
                                       manager_,
                                       owner_,
                                       currentLocationTile(),
                                       "mage");
                 cooldown_=20;
                 return;
             }}
         }
        }
    cooldown_-=1;
}

std::string MageAltar::getType() const
{
    return "Mage Altar";
}
}
