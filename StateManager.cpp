#include "StateManager.h"

static State*state;

State*StateManager::getState()
{
  return state;
}

void StateManager::setState(State*newState)
{
  if (state != NULL)
  {
    delete state;
  }

  state = newState;
}