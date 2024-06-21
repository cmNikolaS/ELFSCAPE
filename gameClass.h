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

    bool isAlive() { return status::isAlive(); }

    void printHP() { for(int i = 0; i <status::getCurrHP(); i++) { std::cout << HEART; } std::cout << std::endl; }

    void UPDATE()
    {
        int hp = 0;
        movement::UPDATE(hp);
        status::updateHP(hp);

    }

    
};