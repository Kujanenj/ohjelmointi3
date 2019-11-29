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
    return healthValue_<=0;
}


void Attackable::setAttacked(bool hasAttacked)
{
    qDebug()<<"trying to set attack with boolean"<<hasAttacked;
    qDebug()<<"NUMBER OF ATTACKS DONE"<<numberOfAttacksDone_;
    if(!hasAttacked){
        numberOfAttacksDone_=0;
        HasAttacked_=false;
        qDebug()<<"nubmer of attacks done is now"<<numberOfAttacksDone_;
        return;
    }
    numberOfAttacksDone_+=1;
    if(numberOfAttacksDone_==numberOfAttacks_){
        HasAttacked_=true;
    }
    qDebug()<<"nubmer of attacks done is now"<<numberOfAttacksDone_;

}

}
