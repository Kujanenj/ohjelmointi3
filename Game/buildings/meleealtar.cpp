#include "meleealtar.h"
namespace Whiskas {


MeleeAltar::MeleeAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                       const std::shared_ptr<gameManager>& objectmanager,
                       const std::shared_ptr<Course::PlayerBase>& owner,
                       const int& tilespaces,
                       const Course::ResourceMap& buildcost,
                       const AdvancedResourceMap production):
    AltarBase(eventhandler,objectmanager,owner)
{

}

void MeleeAltar::upgradeMinion()
{
 for(auto it: manager_->getMinionVector()){
     if(it==currentLocationTile()->getWorkers().at(0) && it->getType()=="Minion"){
         manager_->destroyObject(it);
         manager_->spawnMinion(handler_,
                               manager_,
                               owner_,
                               currentLocationTile(),
                               "champ");
         return;
     }
 }
}
}
