#include "game.hh"
#include "global.hh"
#include "camera.hh"

/**
 * @brief Construct a new Game::Game object
 * 
 * @param width 
 * @param height 
 * @param title 
 * @param fps 
 */
Game::Game(const int width, const int height, const char *title, const int fps)
    : camera_{}, resources_{}, current_scene_{resources_}, test_{Rectangle{0, 0, 40, 40}, camera_} {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(width, height, title);
  SetWindowMinSize(GAME_WIDTH / 2, GAME_HEIGHT / 2);
  SetTargetFPS(fps);
  current_scene_.ChangeScene(INIT);
}

/**
 * @brief Execute the main loop of the game.
 * 
 */
void Game::Run() {
  while (!WindowShouldClose()) {
    Update();
    Draw();
  }
}

/**
 * @brief Draw the game 
 * 
 */
void Game::Draw() const {
  BeginDrawing();
  ClearBackground(BLACK);
  BeginMode2D(camera_);
  DrawRectangleRec(GAME_RECT, WHITE);
  current_scene_.Draw();
  test_.Draw();
  EndMode2D();
  DrawFPS(0, 0);
  EndDrawing();
}

/**
 * @brief Update the game's state 
 * 
 */
void Game::Update() { 
  UpdateCamera(camera_);
}