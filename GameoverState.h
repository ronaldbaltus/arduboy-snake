#pragma once
#include "State.h"
#include "Utils.h"
#include "StateManager.h"

class GameoverState : public State
{
  public:
    GameoverState(int _score)
    {
      score = _score;
    }
    virtual void setup();
    virtual void input(Arduboy2 &);
    virtual void update();
    virtual void draw(Arduboy2 &);

  private:
    bool flip = false;
    int score = 0;
};
