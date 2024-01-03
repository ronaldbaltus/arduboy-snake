#pragma once
#include "State.h"
#include "Vector.h"
#include "StateManager.h"

class TitlescreenState : public State
{
  public:
    TitlescreenState()
    {
    }
    virtual void setup();
    virtual void input(Arduboy2 &);
    virtual void update();
    virtual void draw(Arduboy2 &);
};