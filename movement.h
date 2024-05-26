#pragma once

#include "defaults.h"
#include "mapClass.h"


class movement:public map
{
    private:
    dT xPosition, yPosition;
    protected:
    movement(std::string mf):map(mf)
    {
        
    }
    public:
    void printMap() { map::printMap(); }
    void moveLeft()
    {

    }
    void moveRight()
    {

    }
};