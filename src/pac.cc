#include <memory>

#include "engine/camera.hh"
#include "engine/global.hh"
#include "engine/rmanager.hh"
#include "engine/scene.hh"
#include "raylib.h"

class Game {
 public:
  Game(const int width, const int height, const char *title,
       const int fps = 60);
  ~Game() { CloseWindow(); }
  void Run();

 private:
  void Update();
  void Draw() const;
  Camera2D camera_;
  RManager resources_;
  std::unique_ptr<Scene> current_scene_;
};

Game::Game(const int width, const int height, const char *title, const int fps)
    : camera_{}, resources_{}, current_scene_{} {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(width, height, title);
  SetTargetFPS(fps);
  current_scene_ = resources_.LoadScene(INIT);
}

void Game::Run() {
  while (!WindowShouldClose()) {
    Update();
    BeginDrawing();
    Draw();
    EndDrawing();
  }
}

void Game::Draw() const {
  ClearBackground(BLACK);
  BeginMode2D(camera_);
  DrawRectangleRec(GAME_RECT, WHITE);
  current_scene_->Draw();
  EndMode2D();
  DrawFPS(0, 0);
}

void Game::Update() { UpdateCamera(camera_); }

int main() {
  Game game{GAME_WIDTH, GAME_HEIGHT, "pac"};
  game.Run();
  return 0;
}
