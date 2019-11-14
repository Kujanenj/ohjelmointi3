#include "player.h"

player::player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects ):
               Course::PlayerBase(name, objects)
{

}

void player::alterTurn()
{
    if(inturn_){
        inturn_=false;
        return;
    }
    inturn_=true;
}
