#pragma once
#include "Config.h"

class Vector {
public:
  int x;
  int y;
  Vector(int _x, int _y) {
    x = _x;
    y = _y;
  }
  add(Vector v){
    x=(x+v.x)%columns;
    y=(y+v.y)%rows;
  }
};