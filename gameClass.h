#pragma once

#include "status.h"
#include "defaults.h"
#include "movement.h"
#include "colors.h"

#include <iostream>
#include <string>

class elfscapeClass:protected status, movement
{
    public:

    elfscapeClass():status(), movement() {}

    void printMap() { movement::printMap(status::getCurrHP()); }
    void moveLeft() { movement::moveLeft(); }
    void moveRight() { movement::moveRight(); }

    bool isAlive() { return status::isAlive(); }
    
    void RESTART()
    {
        status::restartHP();
        movement::openMap();
    }

    void showCordinates()
    {
        CORDINATE_COLOR();
        std::cout << "Y - " << movement::getSizeY() -  movement::getYPos() - 1 
        << ", X - " << movement::getXPos() << std::endl;
        DEFAULT_COLOR(); 
    }

    void UPDATE()
    {
        dT hp = 0;
        movement::UPDATE(hp);
        status::updateHP(hp);
    }

};