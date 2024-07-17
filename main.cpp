#include "gameClass.h"
#include "defaults.h"
#include "simpleLibrary.h"
#include "colors.h"
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <mutex>
#include <memory>

using namespace std::chrono;

std::string MENU_file = "MENU.txt";
std::string END_file = "END.txt";

std::mutex screenMutex;
std::mutex windowMutex;

static bool updateWindow = true;
static bool game_is_running = true;

void end_or_continue_program()
{
    while(true){
    if (!game_is_running)
    {
        exit(0);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }}
}
void WINDOW();
void END();
void PAUSE();
void UPDATE(elfscapeClass &GAME, bool &refresh);
void MOVE(elfscapeClass &GAME, bool &refresh);
void SCREEN(elfscapeClass &GAME, bool &refresh);
void MENU();

int main()
{

    simpleLibrary::setTitle("ELFSCAPE - Made by cmNikolaS");
    //faster OUTPUT
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    elfscapeClass GAME;
    bool refresh = true;

    std::thread window(WINDOW);
    std::thread handleProgramRunning(end_or_continue_program);

    do
    {
        refresh = true;

        MENU();
        
        GAME.RESTART();

        SCREEN(GAME, refresh);

        std::thread update(UPDATE, std::ref(GAME), std::ref(refresh));
        while(GAME.isAlive())
        {   
            MOVE(GAME, refresh);
            SCREEN(GAME, refresh);
        }
        update.detach();
        END();
    } while(game_is_running);

    updateWindow = false;
    game_is_running = false;

    window.detach();
    handleProgramRunning.detach();

    return 0;
}

void MOVE(elfscapeClass &GAME, bool &refresh)
{
    if(_kbhit())
    {   
        bool ref = true;
        switch (tolower(getch()))
        {
            case _MOVE_LEFT: GAME.moveLeft(); break;
            case _MOVE_RIGHT: GAME.moveRight(); break;
            case _PAUSE: PAUSE(); break;
            case _EXIT: EXIT(); break;
            default: ref = false; break;
        }
        refresh = ref;
        fflush(stdin);
    }
}

void UPDATE(elfscapeClass &GAME, bool &refresh)
{
    do
    {
        GAME.UPDATE(); 
        refresh = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(TIME_UNTIL_UPDATE));
    } while(GAME.isAlive() && game_is_running);
}

void PAUSE()
{
    PAUSE_MANU_COLOR();
    std::cout << "Press \"p\" to continue!" << std::endl;
    std::cout << "Press \"e\" to EXIT!" << std::endl;
    while(true)
    {
        switch(tolower(getch()))
        {
            case 'e': DEFAULT_COLOR(); exit(0); break;
            case 'p': DEFAULT_COLOR(); return; break;
        }
    }
}

void SCREEN(elfscapeClass &GAME, bool &refresh)
{
    if(refresh)
    {
        CLEAR();
        GAME.printMap();
        refresh = false;
    }
}

void END()
{
    END_COLOR();
    std::cout << "YOU DIED :(" << std::endl;
    simpleLibrary::printFile(END_file);
    simpleLibrary::pause();
    DEFAULT_COLOR();
}

void WINDOW()
{
    do
    {
        if(updateWindow)
        simpleLibrary::setWindowSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);    
    } while(game_is_running);
}

void MENU()
{
    updateWindow = false;

    simpleLibrary::setWindowSize(952, 500);

    MENU_COLOR();
    simpleLibrary::printFile(MENU_file);
    char input;
    do
    {
        input = getch();
        if(input == '1')
        {
            game_is_running = true;
            break;
        }
        else if(input == '2')
        {
            game_is_running = false;
            break;
        }
    } while(true);
    DEFAULT_COLOR();
    updateWindow = true;
}