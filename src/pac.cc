#include <memory>

#include "engine/camera.hh"
#include "engine/global.hh"
#include "engine/rexception.hh"
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
  std::unique_ptr<Scene> LoadScene(const Scenes scene);
  Camera2D camera_;
  RManager resources_;
  std::unique_ptr<Scene> current_scene_;
};

Game::Game(const int width, const int height, const char *title, const int fps)
    : camera_{}, resources_{}, current_scene_{} {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(width, height, title);
  SetTargetFPS(fps);
  current_scene_ = LoadScene(INIT);
}

std::unique_ptr<Scene> Game::LoadScene(const Scenes scene) {
  if (!resources_.BackgroundLoaded(scene)) {
    switch (scene) {
      case INIT:
        if (!resources_.LoadBackground(scene, INIT_BG_PATH))
          throw ResourceLoadingException{"failed to load init background"};
        break;
      case Size:
        break;
    }
  }
  return std::make_unique<Scene>(Scene{resources_.GetBackground(scene)});
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
