#pragma once
#include "status.h"
#include <string>

typedef uint16_t dT;

const dT defHP = 100;
const dT maxMapYSize = 23;
std::string mapFile = "map.txt";

const char PLAYER = 'P';

const dT waitBeforeFall = 300;

void CLEAR() { system("cls"); }

enum{
_MOVE_LEFT = 'a',
_MOVE_RIGHT = 'd',
_JUMP = ' '
};