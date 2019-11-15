#include "attackable.h"

attackable::attackable(int health, int attack)
{
healthValue_=health;
attackValue_=attack;
}

int attackable::getHealth()
{
    return healthValue_;
}

int attackable::getAttack()
{
    return  attackValue_;
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

