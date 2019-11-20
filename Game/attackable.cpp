#include "attackable.h"
#include <QDebug>

namespace Whiskas {

Attackable::Attackable(int health, int attack,int numberOfAttacks,int boundID)
{
healthValue_=health;
attackValue_=attack;
numberOfAttacks_=numberOfAttacks;
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

bool Attackable::getAttacked()
{
    return HasAttacked_;
}

bool Attackable::modifyHealth(int hModifier)
{
    healthValue_+=hModifier;
    if(healthValue_<=0){
        return true;
    }
    return false;
}

void Attackable::setAttacked(bool hasAttacked)
{
    if(hasAttacked==false){
        numberOfAttacksDone_=0;
    }
    numberOfAttacksDone_+=1;
    if(numberOfAttacksDone_==numberOfAttacks_){
        HasAttacked_=true;
    }
}

}
