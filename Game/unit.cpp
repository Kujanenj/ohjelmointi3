#include "unit.h"

unit::unit(int movement)
{
    movement_=movement;
}

int unit::getMoveValue()
{
    return movement_;
}

void unit::setMoved(bool moved)
{
    hasMoved_=moved;
}

bool unit::getMoved()
{
    return hasMoved_;
}
