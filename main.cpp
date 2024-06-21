#include <iostream>
#include <chrono>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "gameClass.h"
#include "defaults.h"
using namespace std::chrono;

void UPDATE(elfscapeClass &GAME, high_resolution_clock::time_point &TIME, bool &refresh)
{
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(stop - TIME);
    if(time.count()%TIME_UNTIL_UPDATE < 20){
        GAME.UPDATE(); 
        refresh = true;}
     
}

void MOVE(elfscapeClass &GAME, bool &refresh, high_resolution_clock::time_point &TIME)
{
    refresh = false;
            if(_kbhit())
            { 
                UPDATE(GAME, TIME, refresh);
                refresh = true;
                switch (getch())
                {
                case _MOVE_LEFT: GAME.moveLeft(); break;
                case _MOVE_RIGHT: GAME.moveRight(); break;
                // case _JUMP: GAME.jump(); break;
                default: refresh =  false; break;
                }
                UPDATE(GAME, TIME, refresh);
                if(refresh == true)
                {
                    return;
                }
                char kb = ' ';
                char l = ' ';
                while (kbhit())
                {
         		    UPDATE(GAME, TIME, refresh);
                    if(refresh)
                    {
                        return;
                    }
                }
            }

}


void SCREEN(elfscapeClass GAME, bool refresh)
{
    if(refresh){
    CLEAR();
    GAME.printMap();
    GAME.showCordinates();
    GAME.printHP();
    refresh = false;}
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        auto TIME = high_resolution_clock::now();
        elfscapeClass GAME;
        bool refresh = true;
        SCREEN(GAME, refresh);
        refresh = false;        
        while(GAME.isAlive())
        {
            SCREEN(GAME, refresh);
            MOVE(GAME, refresh, TIME);
		    UPDATE(GAME, TIME, refresh);
        }
        std::cout << "RIP" << std::endl;
        system("pause");



    return 0;
}