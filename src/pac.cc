#include "engine/camera.hh"
#include "engine/global.hh"
#include "engine/rmanager.hh"
#include "raylib.h"

class Game {
 public:
  Game(const int width, const int height, const char *title,
       const int fps = 60);
  ~Game() { CloseWindow(); }
  void Update();
  void Draw() const;
  void Run();

 private:
  Camera2D camera_;
  RManager resources_;
};

Game::Game(const int width, const int height, const char *title, const int fps)
    : camera_{}, resources_{} {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(width, height, title);
  SetTargetFPS(fps);
  resources_.LoadTexture2D("pepe", "scenes/init/pepe.png");
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
    DrawRectangleRec(Rectangle{WIN_LEFT_CORNER_X, WIN_LEFT_CORNER_Y, WIN_WIDTH, WIN_HEIGHT}, WHITE);
    DrawCircleV(Vector2{}, 20, BLUE);
  EndMode2D();
  DrawFPS(0, 0);
}

void Game::Update() { UpdateCamera(camera_); }

int main() {
  Game game{WIN_WIDTH, WIN_HEIGHT, "pac"};
  game.Run();
  return 0;
}
