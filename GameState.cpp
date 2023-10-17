#include "Utils.h"
#include "Images.h"
#include "GameState.h"

GameState::GameState() : snack(0, 0)
{
  
}

void GameState::setup()
{
  spawnSnack(); // Give snack a random position
}

void GameState::input(Arduboy2 & arduboy)
{
  if (arduboy.justReleased(UP_BUTTON) && currentDirection != 2) direction = 0;
  if (arduboy.justReleased(RIGHT_BUTTON) && currentDirection != 3) direction = 1;
  if (arduboy.justReleased(DOWN_BUTTON) && currentDirection != 0) direction = 2;
  if (arduboy.justReleased(LEFT_BUTTON) && currentDirection != 1) direction = 3;
}

void GameState::update()
{
  /**
   * Update snake
   */
  
  // Move
  for (int i = (sizeof(snakeBody) / sizeof(Vector*)) - 1; i>0; i--) {
    Vector*cur=snakeBody[i];
    Vector*next=snakeBody[i-1];
    
    cur->x=next->x;
    cur->y=next->y;
  }
  snakeBody[0]->add(dir2vec(direction));
  currentDirection=direction;

  // Eat
  if (snakeBody[0]->x == snack.x && snakeBody[0]->y == snack.y) {
    for (int i = 0; i < (sizeof(snakeBody) / sizeof(Vector*)); i++) {
      if (snakeBody[i] != NULL) continue;

      snakeBody[i]=new Vector(snack.x, snack.y);
      break;
    }

    spawnSnack();
  }
}

void GameState::draw(Arduboy2 & arduboy)
{
  /**
   * Render snake.
   */
  for (int i = 0; i < sizeof(snakeBody) / sizeof(Vector*); i++) {
    if (snakeBody[i] == NULL) continue;
    if (i == 0) {
      // HEAD
      arduboy.drawBitmap(snakeBody[i]->x * 8, snakeBody[i]->y * 8, Bitmaps::SnakeHead, 8, 8, WHITE);
    } else {
      // TAIL
      arduboy.drawBitmap(snakeBody[i]->x * 8, snakeBody[i]->y * 8, Bitmaps::SnakeBody, 8, 8, WHITE);
    }
  }

  // Render snack
  arduboy.drawBitmap(snack.x * 8, snack.y * 8, Bitmaps::Snack, 8, 8);
}

void GameState::spawnSnack()
{
  snack.x=random(0, columns);
  snack.y=random(0, rows);
}