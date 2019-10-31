#ifndef USELESSEVENTHANDLER_H
#define USELESSEVENTHANDLER_H
#include "interfaces/igameeventhandler.h"

using namespace Course;
class uselessEventHandler : public iGameEventHandler
{
public:
    uselessEventHandler();
    bool modifyResources(std::shared_ptr<PlayerBase> player, ResourceMap resources) override;
    bool modifyResource(std::shared_ptr<PlayerBase> player, BasicResource resource, int amount) override;
};

#endif // USELESSEVENTHANDLER_H
