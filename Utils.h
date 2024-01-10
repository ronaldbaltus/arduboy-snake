#pragma once
// #ifndef UTILS_H
// #define UTILS_H
#include <Arduboy2.h>
#include "Vector.h"

extern Arduboy2 arduboy;
extern void drawTile(Arduboy2 & arduboy, int x, int y);
extern Vector dir2vec(int dir);

// #endif