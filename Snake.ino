#include <Arduboy2.h>
#include "Config.h"
#include "Images.h"
#include "GameState.h"
#include "TitlescreenState.h"
#include "StateManager.h"

// Specs
// 128x64
// 8x8 tiles?
Arduboy2 arduboy;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(frameRate);
  arduboy.initRandomSeed();

  StateManager::setState(new TitlescreenState());
  StateManager::getState()->setup();
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  StateManager::getState()->input(arduboy);

  if (arduboy.frameCount % 30 == 0) {
    StateManager::getState()->update();
  }

  arduboy.clear();
  StateManager::getState()->draw(arduboy);
  arduboy.display();
}



  