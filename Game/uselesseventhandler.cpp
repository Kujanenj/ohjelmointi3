#include "uselesseventhandler.h"

uselessEventHandler::uselessEventHandler()
{

}

bool uselessEventHandler::modifyResources(std::shared_ptr<PlayerBase> player, ResourceMap resources)
{
    return true;
}

bool uselessEventHandler::modifyResource(std::shared_ptr<PlayerBase> player, BasicResource resource, int amount)
{
    return true;
}
