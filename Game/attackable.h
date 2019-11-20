#ifndef ATTACKABLE_H
#define ATTACKABLE_H

namespace Whiskas {

class Attackable
{
public:
    Attackable(int health, int attack, int numberOfAttacks, int boundID);
    virtual ~Attackable()=default;
    int getHealth();
    int getAttack();
    int getBoundID();
    void modifyAttack(int AModifier);
    bool getAttacked();
    /*!
     * \brief modifyHealth
     * \param hModifier
     * \return true if dead, false if alive
     */
    virtual bool modifyHealth(int hModifier);
    virtual void setAttacked(bool hasAttacked);

protected:
    int healthValue_;
    int attackValue_;
    int boundID_;
    int numberOfAttacks_;
    int numberOfAttacksDone_=0;
    bool HasAttacked_=false;
};

}
#endif // ATTACKABLE_H
