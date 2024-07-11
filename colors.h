#pragma once
#include <windows.h>
#include <string>
#include <iostream>

#define DEFAULT   "\033[0m"     /* DEFAULT */
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BRIGHT_BLACK   "\033[1m\033[30m"      /* BRIGHT_ Black */
#define BRIGHT_RED     "\033[1m\033[31m"      /* BRIGHT_ Red */
#define BRIGHT_GREEN   "\033[1m\033[32m"      /* BRIGHT_ Green */
#define BRIGHT_YELLOW  "\033[1m\033[33m"      /* BRIGHT_ Yellow */
#define BRIGHT_BLUE    "\033[1m\033[34m"      /* BRIGHT_ Blue */
#define BRIGHT_MAGENTA "\033[1m\033[35m"      /* BRIGHT_ Magenta */
#define BRIGHT_CYAN    "\033[1m\033[36m"      /* BRIGHT_ Cyan */
#define BRIGHT_WHITE   "\033[1m\033[37m"      /* BRIGHT_ White */

void setTextColor(std::string COLOR)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(COLOR == "BLACK")//1
    SetConsoleTextAttribute(hConsole, 0);
    else if(COLOR == "RED")//2
    SetConsoleTextAttribute(hConsole, 4);
    else if(COLOR == "BLUE")//3
    SetConsoleTextAttribute(hConsole, 1);
    else if(COLOR == "GREEN")//4
    SetConsoleTextAttribute(hConsole, 2);
    else if(COLOR == "YELLOW")//5
    SetConsoleTextAttribute(hConsole, 6);
    else if (COLOR == "CYAN")//6
    SetConsoleTextAttribute(hConsole, 3);
    else if(COLOR == "MAGENTA")//7
    SetConsoleTextAttribute(hConsole, 5);
    else if (COLOR == "WHITE")//8
    SetConsoleTextAttribute(hConsole, 15);
    else if(COLOR == "BRIGHT BLACK")//9
    SetConsoleTextAttribute(hConsole, 8);
    else if (COLOR == "BRIGHT BLUE")//10
    SetConsoleTextAttribute(hConsole, 9);
    else if (COLOR == "BRIGHT GREEN")//11
    SetConsoleTextAttribute(hConsole, 10);
    else if (COLOR == "BRIGHT CYAN")//12
    SetConsoleTextAttribute(hConsole, 11);
    else if (COLOR == "BRIGHT RED")//13
    SetConsoleTextAttribute(hConsole, 12);
    else if (COLOR == "BRIGHT MAGENTA")//14
    SetConsoleTextAttribute(hConsole, 13);
    else if (COLOR == "BRIGHT YELLOW")//15
    SetConsoleTextAttribute(hConsole, 14);
    else if (COLOR == "DEFAULT")//0
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void printColorBlock(std::string COLOR)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(COLOR == "BLACK")//1
    SetConsoleTextAttribute(hConsole, 0);
    else if(COLOR == "RED")//2
    SetConsoleTextAttribute(hConsole, 68);
    else if(COLOR == "BLUE")//3
    SetConsoleTextAttribute(hConsole, 17);
    else if(COLOR == "GREEN")//4
    SetConsoleTextAttribute(hConsole, 34);
    else if(COLOR == "YELLOW")//5
    SetConsoleTextAttribute(hConsole, 102);
    else if (COLOR == "CYAN")//6
    SetConsoleTextAttribute(hConsole, 51);
    else if(COLOR == "MAGENTA")//7
    SetConsoleTextAttribute(hConsole, 85);
    else if (COLOR == "WHITE")//8
    SetConsoleTextAttribute(hConsole, 255);
    else if(COLOR == "BRIGHT BLACK")//9
    SetConsoleTextAttribute(hConsole, 136);
    else if (COLOR == "BRIGHT BLUE")//10
    SetConsoleTextAttribute(hConsole, 153);
    else if (COLOR == "BRIGHT GREEN")//11
    SetConsoleTextAttribute(hConsole, 170);
    else if (COLOR == "BRIGHT CYAN")//12
    SetConsoleTextAttribute(hConsole, 187);
    else if (COLOR == "BRIGHT RED")//13
    SetConsoleTextAttribute(hConsole, 204);
    else if (COLOR == "BRIGHT MAGENTA")//14
    SetConsoleTextAttribute(hConsole, 221);
    else if (COLOR == "BRIGHT YELLOW")//15
    SetConsoleTextAttribute(hConsole, 238);

    std::cout << ' ' << std::flush;
    setTextColor("DEFAULT");
}

void printAllColorTexts()
{
    setTextColor("DEFAULT");
    std::cout << "DEFAULT" << std::endl;

    setTextColor("WHITE");
    std::cout << "WHITE" << std::endl;

    setTextColor("BRIGHT YELLOW");
    std::cout << "BRIGHT YELLOW" << std::endl;

    setTextColor("YELLOW");
    std::cout << "YELLOW" << std::endl;

    setTextColor("BRIGHT MAGENTA");
    std::cout << "BRIGHT MAGENTA" << std::endl;

    setTextColor("MAGENTA");
    std::cout << "MAGENTA" << std::endl;

    setTextColor("BRIGHT CYAN");
    std::cout << "BRIGHT CYAN" << std::endl;

    setTextColor("CYAN");
    std::cout << "CYAN" << std::endl;

    setTextColor("BRIGHT GREEN");
    std::cout << "BRIGHT GREEN" << std::endl;

    setTextColor("GREEN");
    std::cout << "GREEN" << std::endl;

    setTextColor("BRIGHT BLUE");
    std::cout << "BRIGHT BLUE" << std::endl;

    setTextColor("BLUE");
    std::cout << "BLUE" << std::endl;

    setTextColor("BRIGHT RED");
    std::cout << "BRIGHT RED" << std::endl;

    setTextColor("RED");
    std::cout << "RED" << std::endl;

    setTextColor("BRIGHT BLACK");
    std::cout << "BRIGHT BLACK" << std::endl;

    setTextColor("BLACK");
    std::cout << "BLACK" << std::endl;

    setTextColor("DEFAULT");
}

void printAllColorBlocks()
{
    printColorBlock("WHITE");
       std::cout << "WHITE" << std::endl;

    printColorBlock("BRIGHT YELLOW");
       std::cout << "BRIGHT YELLOW" << std::endl;

    printColorBlock("YELLOW");
       std::cout << "YELLOW" << std::endl;

    printColorBlock("BRIGHT MAGENTA");
       std::cout << "BRIGHT MAGENTA" << std::endl;

    printColorBlock("MAGENTA");
       std::cout << "MAGENTA" << std::endl;

    printColorBlock("BRIGHT CYAN");
       std::cout << "BRIGHT CYAN" << std::endl;

    printColorBlock("CYAN");
       std::cout << "CYAN" << std::endl;

    printColorBlock("BRIGHT GREEN");
       std::cout << "BRIGHT GREEN" << std::endl;

    printColorBlock("GREEN");
       std::cout << "GREEN" << std::endl;

    printColorBlock("BRIGHT BLUE");
       std::cout << "BRIGHT BLUE" << std::endl;

    printColorBlock("BLUE");
       std::cout << "BLUE" << std::endl;

    printColorBlock("BRIGHT RED");
       std::cout << "BRIGHT RED" << std::endl;

    printColorBlock("RED");
       std::cout << "RED" << std::endl;

    printColorBlock("BRIGHT BLACK");
       std::cout << "BRIGHT BLACK" << std::endl;

    printColorBlock("BLACK");
       std::cout << "BLACK" << std::endl;
}