#include "camera.hh"

#include <algorithm>

#include "global.hh"
#include "raylib.h"

void UpdateCamera(Camera2D &camera) {
  const int SCREEN_WIDTH{GetScreenWidth()};
  const int SCREEN_HEIGHT{GetScreenHeight()};
  camera.zoom = std::min(static_cast<float>(SCREEN_WIDTH) / GAME_WIDTH,
                         static_cast<float>(SCREEN_HEIGHT) / GAME_HEIGHT);
  camera.offset = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
}