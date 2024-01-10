#include "Images.h"
#include "TitlescreenState.h"
#include "GameState.h"

void TitlescreenState::setup()
{
  
}

void TitlescreenState::input()
{
  if (arduboy.justReleased(A_BUTTON)) 
  {
    StateManager::setState(new GameState());
  }
}

void TitlescreenState::update()
{
 
}

void TitlescreenState::draw()
{
  //arduboy.drawSlowXYBitmap(0, 0, Bitmaps::Titlescreen, 128, 64);
  arduboy.drawBitmap(0, 0, Bitmaps::Titlescreen, Bitmaps::TitlescreenWidth, Bitmaps::TitlescreenHeight);
}