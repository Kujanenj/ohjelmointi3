#ifndef UNIT_H
#define UNIT_H


class unit
{
public:
    unit(int movement);
    int getMoveValue();
    void setMoved(bool hasMoved);
    bool getMoved();
protected:
    int movement_;
    bool hasMoved_=false;
};

#endif // UNIT_H
