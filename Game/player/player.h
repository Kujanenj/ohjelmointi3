#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"
#include "core/gameobject.h"
class player : public Course::PlayerBase
{
public:
    player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject> > objects ={});
    void alterTurn();
private:
    bool inturn_=false;
    std::string name_="unnamed";
};

#endif // PLAYER_H
