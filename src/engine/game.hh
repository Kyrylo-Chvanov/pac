#pragma once

#include "raylib.h"
#include "scene.hh"
#include "rmanager.hh"
#include "smanager.hh"
#include "trigger.hh"

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
  SManager current_scene_;
  Trigger test_;
};