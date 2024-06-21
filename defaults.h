#pragma once
#include "status.h"
#include <string>

typedef uint16_t dT;


const char point = '°';
const char wallSkelet = '#';
const char wallShow = char(219);
const char floorCeilSkelet = '-';
const char floorCeilShow = char(220);
const char fallingHeadSkelet = '^';
const char fallingBody = '|';
const char fallingHead = char(31);

const char HEART = char(3);

const dT defHP = 10;
const dT maxMapYSize = 23;
std::string mapFile = "map.txt";

const char PLAYER = 'P';

const dT TIME_UNTIL_UPDATE = 600;

const dT waitBeforeFall = 300;

void CLEAR() { system("cls"); }

enum{
_MOVE_LEFT = 'a',
_MOVE_RIGHT = 'd',
_JUMP = ' '
};