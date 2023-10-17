#pragma once
#include "State.h"

class StateManager
{
  private:
    State*state=NULL;
  public:
    StateManager()
    {}

    State* getCurrent() 
    {
      return state;
    }
    void setCurrent(State*newState)
    {
      if (state != NULL)
      {
        delete state;
      }

      state = newState;
    }
};