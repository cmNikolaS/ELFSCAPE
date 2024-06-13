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
        deletePartOfMap(xPosition, yPosition);
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

    void moveLeft()
    {
        deletePartOfMap(xPosition, yPosition);
        if(xPosition-1 != 0) { xPosition--; }
        drawPartOfMap(xPosition, yPosition, PLAYER);
    }
    void moveRight()
    {
        deletePartOfMap(xPosition, yPosition);
        if(xPosition + 1 != map::getSizeX()-1) { xPosition++; }
        drawPartOfMap(xPosition, yPosition, PLAYER);
    }
    void jump()
    {   
        if (jumped == false){
        deletePartOfMap(xPosition, yPosition);
        yPosition--;
        drawPartOfMap(xPosition, yPosition, PLAYER);
        jumped = true;
        }
        else{
        fall();}
    }

};