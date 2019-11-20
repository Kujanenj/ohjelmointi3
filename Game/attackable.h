#ifndef ATTACKABLE_H
#define ATTACKABLE_H

namespace Whiskas {

class Attackable
{
public:
    Attackable(int health, int attack, int boundID);
    virtual ~Attackable()=default;
    int getHealth();
    int getAttack();
    int getBoundID();
     void modifyAttack(int AModifier);
    /*!
     * \brief modifyHealth
     * \param hModifier
     * \return true if dead, false if alive
     */
    virtual bool modifyHealth(int hModifier);
     bool getAttacked();
    virtual void setAttacked(bool setAttacked);

protected:
    int healthValue_;
    int attackValue_;
    int boundID_;
    bool hasAttacked_=false;
};

}
#endif // ATTACKABLE_H
