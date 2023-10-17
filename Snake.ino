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
auto stateManager = new StateManager();

// Initialize GameState
void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(frameRate);
  arduboy.initRandomSeed();

  stateManager->setCurrent(new TitlescreenState(stateManager));
  stateManager->getCurrent()->setup();
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  stateManager->getCurrent()->input(arduboy);

  if (arduboy.frameCount % 30 == 0) {
    stateManager->getCurrent()->update();
  }

  arduboy.clear();
  stateManager->getCurrent()->draw(arduboy);
  arduboy.display();
}



  