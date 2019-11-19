#include "attackable.h"
#include <QDebug>

namespace Whiskas {

Attackable::Attackable(int health, int attack,int boundID)
{
healthValue_=health;
attackValue_=attack;
boundID_=boundID;

}

int Attackable::getHealth()
{
    return healthValue_;
}

int Attackable::getAttack()
{
    return attackValue_;
}

int Attackable::getBoundID()
{
    return boundID_;
}

void Attackable::modifyAttack(int AModifier)
{
    attackValue_+=AModifier;
}

bool Attackable::modifyHealth(int hModifier)
{
    healthValue_+=hModifier;
    if(healthValue_<=0){
        return true;
    }
    return false;
}

}
