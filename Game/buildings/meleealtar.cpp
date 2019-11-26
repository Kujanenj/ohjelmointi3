#include "meleealtar.h"
namespace Whiskas {


MeleeAltar::MeleeAltar(const std::shared_ptr<gameEventHandler>& eventhandler,
                       const std::shared_ptr<gameManager>& objectmanager,
                       const std::shared_ptr<Course::PlayerBase>& owner,
                       const int& tilespaces,
                       const AdvancedResourceMap buildcost,
                       const AdvancedResourceMap production):
    AltarBase(eventhandler,objectmanager,owner)
{
cooldown_=10;
}

void MeleeAltar::upgradeMinion()
{
    if(cooldown_=0){
 for(auto it: manager_->getMinionVector()){
     if(currentLocationTile()->getWorkerCount()!=0){
     if(it==currentLocationTile()->getWorkers().at(0) && it->getType()=="Minion"){
         manager_->destroyObject(it);
         manager_->spawnMinion(handler_,
                               manager_,
                               owner_,
                               currentLocationTile(),
                               "champ");
         cooldown_=10;
         return;
     }}
 }}
    cooldown_-=1;
}

std::string MeleeAltar::getType() const
{
    return "Melee Altar";
}
}
