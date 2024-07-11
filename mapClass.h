#pragma once

#include "defaults.h"
#include "colors.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdint>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

class map
{
    private:

    dT mapSizeX, mapSizeY, screenSizeX;
    std::string MAP[maxMapYSize];
    dT lastLocation = 0;

    protected:

    void openMap()
    {
        std::string t, mapSizeXS, mapSizeYS;

        std::fstream map;
        map.open(mapFile);
        assert(map.is_open() == true && "CANT OPEN MAP FILE!");

        std::getline(map, t);

        mapSizeYS = t[4];
        mapSizeYS += t[5];
        mapSizeXS = t[0];
        mapSizeXS += t[1];

        mapSizeX = stoi(mapSizeXS);
        mapSizeY = stoi(mapSizeYS);

        screenSizeX = 0;
        dT mS = 0;

        for (dT i = 0; i < mapSizeY; i++)
        {
            std::getline(map, MAP[i]);
            mS = MAP[i].size();
            if (screenSizeX < mS) { screenSizeX = mS; }
        }

        map.close();
    }

    map()
    {
        openMap();
    }

    void locatePlayerXY(dT &x, dT &y)
    {
        for(dT i = 0; i < mapSizeY; i++)
        {
            for(dT j = 0; j < mapSizeX; j++)
            {
                if(MAP[i][j] == PLAYER_SKELET)
                {
                    x = j, y = i;
                    return;
                }
            }
        }
    }

    protected:
    
    //getters____________________________________________________________________________
    char getPartOfMap(dT Y, dT X) { return MAP[Y][X]; }
    dT getSizeX() { return mapSizeX; }
    dT getSizeY() { return mapSizeY; }
    //delete_draw________________________________________________________________________
    void deletePartOfMap(dT y, dT x) { MAP[y][x] = ' '; }
    void drawPartOfMap(dT x, dT y, char wtd) { MAP[y][x] = wtd; }

    void printMap(dT numOfHP)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        char toPr;
        dT crrHP = 0;
        for(dT i = 0; i < mapSizeY; i++)
        {
            for(dT j = 0; j < screenSizeX; j++)
            {   
                toPr = MAP[i][j];
                switch(toPr)
                {
                    case HEARTSKELET: 
                    {
                        toPr = HEART;
                        if(j > mapSizeX)
                        {
                            crrHP++;
                            if(numOfHP >= crrHP)
                            {
                                HEART_COLOR();
                            }
                            else
                            { 
                                EMPTY_HEART_COLOR(); 
                            }
                        }
                        else
                        {
                            HEART_COLOR();
                        }
                        break;
                    }
                    case fallingHeadSkelet: { FALLING_HEAD_COLOR(); toPr = fallingHead; break; }
                    case fallingBody: { FALLING_BODY_COLOR(); break; }
                    case wallSkelet: { WALL_COLOR(); toPr = wallShow; break; }
                    case floorCeilSkelet: { FLOOR_COLOR(); toPr = floorCeilShow; break; }
                    case PLAYER_SKELET: { PLAYER_COLOR(); toPr = PLAYER; break; }
                    default: { DEFAULT_COLOR(); }
                }
                
                std::cout << toPr << std::flush;

                DEFAULT_COLOR();
            }
            std::cout << std::endl;
        }
    }

    void UPDATE(dT &hp)
    { 
        char last, current; 
        for(dT i = mapSizeY - 1; i > 1; i--)
        {
            for(dT j = 1; j < mapSizeX - 1; j++)
            {   
                last = MAP[i-1][j];
                current = MAP[i][j];

                if(last == fallingHeadSkelet)
                {
                    if(MAP[i-2][j] == fallingBody) { MAP[i-2][j] = ' '; }
                    if(current == floorCeilSkelet || current == PLAYER_SKELET) { last = ' '; if(current == PLAYER_SKELET) { hp--; }}
                    else { current = fallingHeadSkelet; last= fallingBody; }
                }
                else if(last == HEARTSKELET)
                {
                    if(i == 1) { break; }
                    if(current == floorCeilSkelet || current == PLAYER_SKELET) { last = ' '; if(current == PLAYER_SKELET) { hp++; } }
                    else { current = HEARTSKELET; last = ' '; }
                }
                MAP[i][j] = current;
                MAP[i-1][j] = last;
            }
        }

        srand(time(0)+rand());
        
        dT location = 0;

        do { location = (rand()%(mapSizeX-2))+1; } while (location == lastLocation);
        
        lastLocation = location; 

        dT isHeart = rand() % HEART_CHANCE + 1;
        
        if(isHeart == 1) { MAP[1][location] = HEARTSKELET; }
        else { MAP[1][location] = fallingHeadSkelet; }
    }
};