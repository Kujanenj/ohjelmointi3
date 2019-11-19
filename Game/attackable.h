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


protected:
    int healthValue_;
    int attackValue_;
    int boundID_;
};

}
#endif // ATTACKABLE_H
