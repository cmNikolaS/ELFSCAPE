#pragma once

#include "defaults.h"

#include <fstream>
#include <string>
#include <cstdint>
#include <iostream>
#include <assert.h>

class map
{
    private:
    dT mapSizeX, mapSizeY;
    std::string MAP[maxMapYSize];
    
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

    dT getSizeX() { return mapSizeX; }
    dT getSizeY() { return mapSizeY; }
    void printMap()
    {
        for(int i =0; i< mapSizeY; i++)
        std::cout << MAP[i] << std::endl;
    }

    void deletePartOfMap(dT x, dT y) { MAP[y][x] = ' '; }
    void drawPartOfMap(dT x, dT y, char wtd) { MAP[y][x] = wtd; }
    
};