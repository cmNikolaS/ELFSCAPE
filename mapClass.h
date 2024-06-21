#pragma once

#include "defaults.h"

#include <fstream>
#include <string>
#include <cstdint>
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <ctime>

class map
{
    private:
    dT mapSizeX, mapSizeY;
    std::string MAP[maxMapYSize];
    dT lastLocation = 0;
    
    void makeMap(std::string mapFile)
{
    std::string t;
    std::string mapSizeXS, mapSizeYS;
    std::fstream map;
    map.open(mapFile);
    assert(map.is_open() == true && "CANT OPEN MAP FILE!");

    std::getline(map, t);

    mapSizeYS = t[3];
    mapSizeYS += t[4];
    mapSizeXS = t[0];
    mapSizeXS += t[1];

    mapSizeX = stoi(mapSizeXS);
    mapSizeY = stoi(mapSizeYS);

    for (int i = 0; i < mapSizeY; i++)
        std::getline(map, MAP[i]);
    
    map.close();
    }
    
    protected:
    map(std::string mapFile)
    {
        makeMap(mapFile);
    }
    void locatePlayerXY(dT &x, dT &y)
    {
        for(int i =0; i< mapSizeY; i++)
        {
            for(int j=0;j<mapSizeX;j++)
            {
                if(MAP[i][j] == PLAYER)
                x = j, y = i;
            }
        }
    }

    public:
    
    char getPartOfMap(int Y, int X) { return MAP[Y][X]; }

    dT getSizeX() { return mapSizeX; }
    dT getSizeY() { return mapSizeY; }
    void printMap()
    {
        for(int i =0; i< mapSizeY; i++)
        {
            for(int j = 0; j < mapSizeX; j++)
            {
                if(MAP[i][j] == wallSkelet)
                {
                    std::cout << wallShow;
                }
                else if(MAP[i][j] == floorCeilSkelet)
                {
                    std::cout << floorCeilShow;
                }
                else
                {
                    std::cout << MAP[i][j];
                }
            }
            std::cout << std::endl;
        }

    }
    void UPDATE(int &hp)
    { 
        srand(time(0)+rand());
        dT location = 0;
        do
        {
            location = (rand()%(mapSizeX-2))+1;
        }while (location == lastLocation);

        lastLocation = location; 

        MAP[1][location] = fallingHead;

        for(int i = mapSizeY-1; i > 1; i--)
        {
            for(int j=1;j<mapSizeX-1;j++)
            {
                if(MAP[i-1][j] == fallingHead)
                {
                    if(MAP[i-2][j] == fallingBody) { MAP[i-2][j] = ' '; }
                    if(MAP[i][j] == floorCeilSkelet || MAP[i][j] == PLAYER) { MAP[i-1][j] = ' '; if(MAP[i][j] == PLAYER) { hp--; }}
                    else
                    {
                    MAP[i][j] = fallingHead; MAP[i-1][j]= fallingBody;
                    }
                }
            }
        }
       
    }

    void deletePartOfMap(dT y, dT x) { MAP[y][x] = ' '; }
    void drawPartOfMap(dT x, dT y, char wtd) { MAP[y][x] = wtd; }
    
};