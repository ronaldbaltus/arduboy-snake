#include "Images.h"
#include "TitlescreenState.h"
#include "GameState.h"

void TitlescreenState::setup()
{
  
}

void TitlescreenState::input(Arduboy2 & arduboy)
{
  if (arduboy.justReleased(A_BUTTON)) 
  {
    stateManager->setCurrent(new GameState());
    //setState(new GameState());
  }
}

void TitlescreenState::update()
{
 
}

void TitlescreenState::draw(Arduboy2 & arduboy)
{
  arduboy.drawBitmap(0, 0, Bitmaps::Titlescreen, 128, 64);
}