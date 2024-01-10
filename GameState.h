#pragma once
#include "State.h"
#include "Vector.h"
#include "StateManager.h"

class GameState : public State
{
  public:
    GameState();
    virtual void setup();
    virtual void input();
    virtual void update();
    virtual void draw();
    void spawnSnack();
    void gameOver();

  private:
    /**
     * Snaaaaaaaaaake
     */
    Vector* snakeBody[128] = {
      new Vector(columns / 2, rows / 2),
      new Vector((columns / 2)+1, (rows / 2)+0),
      new Vector((columns / 2)+2, (rows / 2)+0)
    };
    
    Vector snack;
    int currentDirection=3;
    int direction=3;
    int score=0;
    bool ledOn=false;
};
