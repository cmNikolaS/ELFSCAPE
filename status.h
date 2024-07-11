#pragma once
#include <cstdint>
#include "defaults.h"

class status
{
    private:

    dT currHP, maxHp;
    bool ALIVE = true;

    protected:

    void restartHP()
    {
        currHP = maxHp = defHP;
        ALIVE = true;
    }

    status()
    {
        restartHP();
    }

    public:

    void updateHP(dT hp)
    {
        currHP+=hp;

        if(currHP > maxHp)
            currHP = maxHp;
            
        if (currHP < 1)
        ALIVE = false;
    }

    dT getCurrHP() { return currHP; }
    dT getMaxHp() { return maxHp; }
    bool isAlive() { return ALIVE; }

};