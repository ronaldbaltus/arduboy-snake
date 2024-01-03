#include "Utils.h"

void drawTile(Arduboy2 & arduboy, int x, int y) {
  arduboy.drawRect(x * 8, y * 8, 8, 8);
}

Vector dir2vec(int dir) {
  switch (dir) {
    case 0: return Vector(0, -1);
    case 1: return Vector(1, 0);
    case 2: return Vector(0, 1);
    case 3: return Vector(-1, 0);
  }
}