#include "attackable.h"
#include <QDebug>
attackable::attackable(int health, int attack,int boundID)
{
healthValue_=health;
attackValue_=attack;
boundID_=boundID;

}

int attackable::getHealth()
{
    return healthValue_;
}

int attackable::getAttack()
{
    return  attackValue_;
}

int attackable::getBoundID()
{
    return boundID_;
}

void attackable::modifyAttack(int AModifier)
{
    attackValue_+=AModifier;
}

bool attackable::modifyHealth(int hModifier)
{
    healthValue_+=hModifier;
    if(healthValue_<=0){
        return true;
    }
    return false;
}

