#pragma once

#include "defaults.h"

#include <fstream>
#include <string>
#include <cstdint>
#include <iostream>

class map
{
    private:
    dT mapSizeX, mapSizeY;
    std::string MAP[maxMapYSize];
    
    void makeMap(std::string mapFile)
{
    std::string t;
    std::string mapSizeXS, mapSizeYS, spawnXS, spawnYS;
    std::fstream map;
    map.open(mapFile);

    std::getline(map, t);

    mapSizeYS = t[3];
    mapSizeYS += t[4];
    mapSizeXS = t[0];
    mapSizeXS += t[1];

    mapSizeX = stoi(mapSizeXS);
    mapSizeY = stoi(mapSizeYS);

    for (int i = 0; i <= mapSizeX; i++)
        std::getline(map, MAP[i]);
    
    map.close();
    }
    
    protected:
    map(std::string mapFile)
    {
        makeMap(mapFile);
    }

    public:

    void printMap()
    {
        for(int i =0; i< mapSizeY; i++)
        std::cout << MAP[i] << std::endl;
    }
    
};