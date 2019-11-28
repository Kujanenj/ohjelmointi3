#ifndef UNIT_H
#define UNIT_H

namespace Whiskas {
/**
 * @brief The Unit class handles the move values
 */
class Unit
{
public:
    Unit(int movement);
    /**
     * @brief getMoveValue
     * @return unit move value
     */
    int getMoveValue();
    /**
     * @brief setMoved modifies moved boolean
     * @param hasMoved
     */
    void setMoved(bool hasMoved);
    bool getMoved();
protected:
    int movement_;
    bool hasMoved_=false;
};

}
#endif // UNIT_H
