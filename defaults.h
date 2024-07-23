#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "colors.h"
#include <cstdint>
#include <cstdlib>

typedef uint16_t dT;

std::string mapFile = "map.txt";

const dT DEFAULT_WIDTH = 390;
const dT DEFAULT_HEIGHT = 390; 

const char AIR = ' ';
const char wallSkelet = '#';
const char wallShow = char(219);
const char floorCeilSkelet = '_';
const char floorCeilShow = char(220);
const char fallingHeadSkelet = '^';
const char fallingBody = '|';
const char fallingHead = char(31);
const char HEARTSKELET = '*';
const char HEART = char(3);

const dT defHP = 4;
const dT maxMapYSize = 23;
const dT HEART_CHANCE = 12;//1 in 12

const char PLAYER = 'P';
const char PLAYER_SKELET = '~'; 

dT TIME_UNTIL_UPDATE = 400;
const dT TIME_UNTIL_MOVE = 200;
const dT TIME_UNTIL_WINDOW_FIX = 200;

//default colors
inline void MENU_COLOR() { setTextColor("BRIGHT GREEN"); }
inline void DEFAULT_COLOR() { setTextColor("YELLOW"); }
inline void PAUSE_MANU_COLOR() { setTextColor("GRAY"); }
inline void CORDINATE_COLOR() { setTextColor("GRAY"); }
inline void END_COLOR() { setTextColor("RED"); }
//program colors
inline void EMPTY_HEART_COLOR() { setTextColor("WHITE"); }
inline void HEART_COLOR() {setTextColor("RED"); }
inline void FALLING_HEAD_COLOR() { setTextColor("BRIGHT BLACK"); }
inline void FALLING_BODY_COLOR() { FALLING_HEAD_COLOR(); }
inline void WALL_COLOR() { setTextColor("GREEN"); }
inline void FLOOR_COLOR() { setTextColor("GREEN"); }
inline void CEILING_COLOR() { setTextColor("GREEN"); }
inline void PLAYER_COLOR() { setTextColor("BRIGHT GREEN"); }

//functions
inline void EXIT() { exit(0); } 
inline void CLEAR() { system("cls"); }

enum{
_MOVE_LEFT = 'a',
_MOVE_RIGHT = 'd',
_PAUSE = 'p',
_EXIT = 'e'
};