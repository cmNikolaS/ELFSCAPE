#pragma once
#include <cstdint>
#include "defaults.h"

class status
{
    private:
    dT currHP, maxHp;
    protected:
    status(dT hp=0):currHP(hp), maxHp(hp){}

    dT getMaxHp() { return maxHp; }


};