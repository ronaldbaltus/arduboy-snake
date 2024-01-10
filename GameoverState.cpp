#include "Images.h"
#include "GameoverState.h"
#include "GameState.h"
//#include "StateManager.h"

void GameoverState::setup()
{
    // don't think there is much to setup
    arduboy.setRGBled(RED_LED, 100);
}

void GameoverState::update()
{
  // Don't think there is much to update.
  flip = !flip;
}

void GameoverState::draw()
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


  arduboy.setCursor(56, 31);
  arduboy.setTextSize(1);
  arduboy.print(score);
}

void GameoverState::input()
{
  if (arduboy.justReleased(A_BUTTON)) 
  {
    arduboy.setRGBled(RED_LED, 0);
    StateManager::setState(new GameState());
  }
}