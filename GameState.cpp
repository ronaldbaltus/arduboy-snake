#include "Utils.h"
#include "Config.h"
#include "Images.h"
#include "GameState.h"
#include "GameoverState.h"

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

  // Check collision of the head.
  if (snakeBody[0]->x < 0 || snakeBody[0]->x >= columns || snakeBody[0]->y < 0 || snakeBody[0]->y >= rows) {
    // Snake ran into a wall.
    gameOver();
    return;
  }

  // check collision with tail
  for (int i = 1; i < (sizeof(snakeBody) / sizeof(Vector*)); i++) {
    if (snakeBody[0]->x == snakeBody[i]->x && snakeBody[0]->y == snakeBody[i]->y) {
      // Snake ran into itself.
      gameOver();
      return;
    }
  }

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
      arduboy.drawBitmap(snakeBody[i]->x * 8, snakeBody[i]->y * 8, Bitmaps::SnakeHead, Bitmaps::SnakeHeadWidth, Bitmaps::SnakeHeadHeight, WHITE);
    } else {
      // TAIL
      arduboy.drawBitmap(snakeBody[i]->x * 8, snakeBody[i]->y * 8, Bitmaps::SnakeBody, Bitmaps::SnakeBodyWidth, Bitmaps::SnakeBodyHeight, WHITE);
    }
  }

  // Render snack
  arduboy.drawBitmap(snack.x * 8, snack.y * 8, Bitmaps::Snack, Bitmaps::SnackWidth, Bitmaps::SnackHeight);
}

void GameState::spawnSnack()
{
  snack.x=random(0, columns);
  snack.y=random(0, rows);
}

void GameState::gameOver()
{
  StateManager::setState(new GameoverState(1337));
}