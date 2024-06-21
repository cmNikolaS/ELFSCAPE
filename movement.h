#pragma once

#include <windows.h>
#include "defaults.h"
#include "mapClass.h"


class movement:public map
{
    private:
    dT xPosition, yPosition;
    bool jumped = false;
    protected:
    movement(std::string mf):map(mf)
    {
        locatePlayerXY(xPosition, yPosition); jumped = false;
    }
    void fall()
    {
        Sleep(waitBeforeFall);
        deletePartOfMap(yPosition, xPosition);
        yPosition++; 
        drawPartOfMap(xPosition, yPosition, PLAYER);
        jumped = false;
    }
    public:
    void printMap() { map::printMap(); }
    dT getYPos() { return yPosition; }
    dT getXPos() { return xPosition; }
    bool isJumped() { return jumped; }
    void setIsJumped(bool iJ) { jumped = iJ; }
    void UPDATE(int &hp) { map::UPDATE(hp); }
    void removeTrash()
    {
        if(getPartOfMap(yPosition, xPosition) == fallingHead)
        {
            map::deletePartOfMap(yPosition-1, xPosition);
        }
    }
    void moveLeft()
    {
        deletePartOfMap(yPosition, xPosition);
        if(xPosition-1 != 0) { xPosition--; }
        removeTrash();
        drawPartOfMap(xPosition, yPosition, PLAYER);
    }
    void moveRight()
    {
        deletePartOfMap(yPosition, xPosition);
        if(xPosition + 1 != map::getSizeX()-1) { xPosition++; }
        removeTrash();
        drawPartOfMap(xPosition, yPosition, PLAYER);
    }
    void jump()
    {   
        if (jumped == false){
        deletePartOfMap(yPosition, xPosition);
        yPosition--;
        drawPartOfMap(xPosition, yPosition, PLAYER);
        jumped = true;
        }
        else{
        fall();}
    }

};