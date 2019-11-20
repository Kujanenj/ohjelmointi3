#ifndef UNIT_H
#define UNIT_H

namespace Whiskas {

class Unit
{
public:
    Unit(int movement);
    int getMoveValue();
    void setMoved(bool hasMoved);
    bool getMoved();
protected:
    int movement_;
    bool hasMoved_=false;
};

}
#endif // UNIT_H
