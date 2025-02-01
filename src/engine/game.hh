#pragma once

#include "raylib.h"
#include "rmanager.hh"
#include "smanager.hh"

/**
 * @brief Main game class
 *
 */
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
  SManager scene_manager_;
};