#ifndef ATTACKABLE_H
#define ATTACKABLE_H

namespace Whiskas {
/**
 * @brief The Attackable class contains information regarding attacking and dealing damage
 */
class Attackable
{
public:
    /**
     * @brief Attackable Constructor
     * @param health 0=Dead
     * @param attack damage
     * @param numberOfAttacks how many times the unit can attack in a turn
     * @param boundID id of the object this is bound to
     */
    Attackable(int health, int attack, int numberOfAttacks, int boundID);
    virtual ~Attackable()=default;
    /**
     * @brief getHealth
     * @return Current HP
     */
    int getHealth();
    /**
     * @brief getAttack
     * @return AttackValue
     */
    int getAttack();
    /**
     * @brief getBoundID
     * @return ID of the object this is bound to
     */
    int getBoundID();
    /**
     * @brief Increases the damage of the unit by the mofifier
     * @param AModifier
     */
    void modifyAttack(int AModifier);
    /**
     * @brief getAttacked
     * @return true if he unit has attacked this turn. False otherwise
     */
    bool getAttacked();
    /*!
     * \brief modifyHealth
     * \param hModifier
     * \return true if dead, false if alive
     */
    virtual bool modifyHealth(int hModifier);
    /**
     * @brief setAttacked tries to modify the boolean HasAttacked_;
     * @param hasAttacked
     */
    virtual void setAttacked(bool hasAttacked);

protected:
    int healthValue_;
    int attackValue_;
    int boundID_;
    int numberOfAttacks_;
    int numberOfAttacksDone_=0; //attacks done this round
    bool HasAttacked_=false;
};

}
#endif // ATTACKABLE_H
