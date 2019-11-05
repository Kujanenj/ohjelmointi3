#ifndef gameEventHandler_H
#define gameEventHandler_H
#include "interfaces/igameeventhandler.h"

#include <QDebug>


class gameEventHandler : public Course::iGameEventHandler
{
public:
    gameEventHandler();
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources) override;
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount) override;

};

#endif // gameEventHandler_H
