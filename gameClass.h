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
    dT getXPos() { return movement::getXPos(); }
    dT getYPos() { return movement::getYPos(); }


    void moveLeft() { movement::moveLeft(); }
    void moveRight() { movement::moveRight(); }
    void jump() { movement::jump(); }

    void showCordinates()
    {
        std::cout << "Y - " << movement::getSizeY() -  movement::getYPos() - 1 << ", X - " << movement::getXPos() << std::endl;        
    }

    bool isAlive() { return true; }

    void DEFAULT()
    {
        if (isJumped())
        fall();
    }

    
};