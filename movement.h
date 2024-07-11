#pragma once

#include "defaults.h"
#include "mapClass.h"
#include <windows.h>

class movement: public map
{
    private:

    dT xPosition, yPosition;

    void removeTrash()
    {
        map::deletePartOfMap(yPosition - 1, xPosition);
        map::deletePartOfMap(yPosition, xPosition);
    }

    void MOVE(bool LEFT, bool RIGHT)
    {
        deletePartOfMap(yPosition, xPosition);//deleting Player
        const char lastBlock = getPartOfMap(yPosition, xPosition+RIGHT-LEFT);
        if(lastBlock != wallSkelet && lastBlock != floorCeilSkelet) { xPosition += RIGHT-LEFT; }
        if(lastBlock == fallingHeadSkelet) { removeTrash(); }
        map::drawPartOfMap(xPosition, yPosition, PLAYER_SKELET);
    }

    protected:
    void openMap()
    {
        map::openMap();
        locatePlayerXY(xPosition, yPosition);
    }
    movement():map()
    {
        locatePlayerXY(xPosition, yPosition);
    }
    dT getYPos() { return yPosition; }
    dT getXPos() { return xPosition; }

    void printMap(dT numOfHP) { map::printMap(numOfHP); }
    void UPDATE(dT &hp) { map::UPDATE(hp); }
    
    void moveLeft()
    {
        MOVE(true, false);
    }

    void moveRight()
    {
        MOVE(false, true);
    }
};