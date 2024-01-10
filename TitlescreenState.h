#pragma once
#include "Utils.h"
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
    virtual void input();
    virtual void update();
    virtual void draw();
};