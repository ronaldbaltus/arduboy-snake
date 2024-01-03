#pragma once
#include "State.h"

class StateManager
{
  private:
    static State*state;
  public:
    static State* getState() 
    {
      return state;
    }
    static void setState(State*newState)
    {
      if (state != NULL)
      {
        delete state;
      }

      state = newState;
    }
};
