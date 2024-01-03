#include "Images.h"
#include "GameoverState.h"
#include "GameState.h"
//#include "StateManager.h"

void GameoverState::setup()
{
    // don't think there is much to setup
}

void GameoverState::update()
{
  // Don't think there is much to update.
  flip = !flip;
}

void GameoverState::draw(Arduboy2 & arduboy)
{
  if (flip)
  {
    arduboy.drawBitmap(0, 0, Bitmaps::GameoverScreenFrame0, Bitmaps::GameoverScreenFrame0Width, Bitmaps::GameoverScreenFrame0Height);
  }
  else
  {
    arduboy.drawBitmap(0, 0, Bitmaps::GameoverScreenFrame1, Bitmaps::GameoverScreenFrame1Width, Bitmaps::GameoverScreenFrame1Height);
  }

  // TODO: Print score
  //arduboy.draw
  //arduboy.println()
}

void GameoverState::input(Arduboy2 & arduboy)
{
  if (arduboy.justReleased(A_BUTTON)) 
  {
    StateManager::setState(new GameState());
  }
}