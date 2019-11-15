#ifndef ATTACKABLE_H
#define ATTACKABLE_H


class attackable
{
public:
    attackable(int health, int attack);
    virtual ~attackable()=default;
    int getHealth();
    int getAttack();
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
};

#endif // ATTACKABLE_H
