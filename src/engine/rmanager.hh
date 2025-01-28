#pragma once

#include <array>

#include "raylib.h"
#include "scene.hh"

// Resource manager
class RManager {
 public:
  RManager() : backgrounds_{} {}
  bool LoadBackground(const Scenes scene, const char *path);
  bool BackgroundLoaded(const Scenes scene) {
    return backgrounds_[scene].id > 0;
  }
  const Texture2D &GetBackground(const Scenes scene) const;
  ~RManager();

 private:
  std::array<Texture2D, Size> backgrounds_;
};