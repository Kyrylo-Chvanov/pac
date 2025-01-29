#pragma once

#include <array>
#include <memory>

#include "raylib.h"
#include "scene.hh"

/**
 * @brief Resource manager. 
 *        Used for loading and controlling textures, music, etc.
 * 
 */
class RManager {
 public:
  RManager() : backgrounds_{} {}
  ~RManager();
  std::unique_ptr<Scene> LoadScene(const Scenes scene);

 private:
  bool LoadBackground(const Scenes scene, const char *path);
  bool BackgroundLoaded(const Scenes scene) {
    return backgrounds_[scene].id > 0;
  }
  const Texture2D & GetBackground(const Scenes scene) const;
  std::array<Texture2D, Size> backgrounds_;
};