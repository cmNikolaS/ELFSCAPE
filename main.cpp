#include <iostream>
#include <chrono>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "gameClass.h"
#include "defaults.h"

void MOVE(elfscapeClass &GAME, bool &refresh)
{
    refresh = false;
            if(_kbhit())
            { 
                bool isValid = true;
                switch (getch())
                {
                case _MOVE_LEFT: GAME.moveLeft(); break;
                case _MOVE_RIGHT: GAME.moveRight(); break;
                // case _JUMP: GAME.jump(); break;
                default:  isValid = refresh =  false; break;
                }
            if(isValid == true){
            while (kbhit()) { getch(); } }
            }
}


void SCREEN(elfscapeClass GAME)
{
    CLEAR();
    GAME.printMap();
    GAME.showCordinates();
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        elfscapeClass GAME;
        bool refresh = true;        
        while(GAME.isAlive())
        {
            if(refresh) { SCREEN(GAME); }
            MOVE(GAME, refresh);
            GAME.DEFAULT();
        }


    return 0;
}