#include "magealtar.h"
namespace Whiskas {


MageAltar::MageAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                     const std::shared_ptr<gameManager>& objectmanager,
                     const std::shared_ptr<Course::PlayerBase>& owner,
                     const int& tilespaces,
                     const Course::ResourceMap& buildcost,
                     const AdvancedResourceMap production):
  AltarBase(eventhandler,objectmanager,owner)
{

}

void MageAltar::upgradeMinion()
{
    {
        {
         for(auto it: manager_->getMinionVector()){
             if(currentLocationTile()->getWorkerCount()!=0){
             if(it==currentLocationTile()->getWorkers().at(0) && it->getType()=="Minion"){
                 manager_->destroyObject(it);
                 manager_->spawnMinion(handler_,
                                       manager_,
                                       owner_,
                                       currentLocationTile(),
                                       "mage");
                 return;
             }}
         }
        }
    }
}

std::string MageAltar::getType() const
{
    return "Mage Altar";
}
}
