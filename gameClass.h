#pragma once

#include "status.h"
#include "defaults.h"
#include "movement.h"

#include <iostream>
#include <string>

class elfscapeClass:protected status, movement
{
    private:

    public:
    elfscapeClass():status(defHP), movement(mapFile)
    {
    }
    dT getMaxHP() { return status::getMaxHp(); }
    void printMap() { movement::printMap(); }





};

