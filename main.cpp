#include <iostream>
#include <string>
#include "gameClass.h"
#include "defaults.h"

int main()
{

        elfscapeClass GAME;

        std::cout << "Max HP: " << GAME.getMaxHP() << "\n";
        GAME.printMap();
        std::cout << "a";         
        



    return 0;
}