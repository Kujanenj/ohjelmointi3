#include "gameeventhandler.h"

gameEventHandler::gameEventHandler()
{

}

bool gameEventHandler::modifyResources(std::shared_ptr<PlayerBase> player, ResourceMap resources)
{
    return true;
}

bool gameEventHandler::modifyResource(std::shared_ptr<PlayerBase> player, BasicResource resource, int amount)
{
    return true;
}
