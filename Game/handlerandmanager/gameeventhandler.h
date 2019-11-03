#ifndef gameEventHandler_H
#define gameEventHandler_H
#include "interfaces/igameeventhandler.h"

#include <QDebug>

using namespace Course;
class gameEventHandler : public iGameEventHandler
{
public:
    gameEventHandler();
    bool modifyResources(std::shared_ptr<PlayerBase> player, ResourceMap resources) override;
    bool modifyResource(std::shared_ptr<PlayerBase> player, BasicResource resource, int amount) override;

};

#endif // gameEventHandler_H
