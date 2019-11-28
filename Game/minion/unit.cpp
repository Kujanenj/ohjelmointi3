#include "unit.h"

namespace Whiskas {

Unit::Unit(int movement)
{
    movement_=movement;
}

int Unit::getMoveValue()
{
    return movement_;
}

void Unit::setMoved(bool moved)
{
    hasMoved_=moved;
}

bool Unit::getMoved()
{
    return hasMoved_;
}

}
