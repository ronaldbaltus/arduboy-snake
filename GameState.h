#pragma once
#include "State.h"
#include "Vector.h"
#include "StateManager.h"

class GameState : public State
{
  public:
    GameState();
    virtual void setup();
    virtual void input(Arduboy2 &);
    virtual void update();
    virtual void draw(Arduboy2 &);
    void spawnSnack();
    void gameOver();

  private:
    /**
     * Snaaaaaaaaaake
     */
    Vector* snakeBody[30] = {
      new Vector(columns / 2, rows / 2),
      new Vector((columns / 2)+1, (rows / 2)+0),
      new Vector((columns / 2)+2, (rows / 2)+0),
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    };
    
    Vector snack;
    int currentDirection=3;
    int direction=3;
};
