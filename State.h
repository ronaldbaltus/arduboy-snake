#pragma once
#include <Arduboy2.h>

class State 
{
  public:
    virtual void setup();
    virtual void input();
    virtual void update();
    virtual void draw();
};
