#pragma once
#include "State.h"

class StateManager
{
  public:
    static State* getState();
    static void setState(State*newState);
};
