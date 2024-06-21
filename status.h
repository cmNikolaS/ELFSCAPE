#pragma once
#include <cstdint>
#include "defaults.h"

class status
{
    private:
    dT currHP, maxHp;
    bool ALIVE = true;
    protected:
    status(dT hp=0):currHP(hp), maxHp(hp){}

    public:
    void updateHP(int hp)
    {
        currHP+=hp;
        if (currHP < 1)
        ALIVE = false;
    }
    int getCurrHP() { return currHP; }
    dT getMaxHp() { return maxHp; }
    bool isAlive() { return ALIVE; }

};