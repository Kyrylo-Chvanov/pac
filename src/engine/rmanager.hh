#pragma once

#include <array>

#include "raylib.h"
#include "scene.hh"

/**
 * @brief Resource manager. 
 *        Used for loading and controlling textures, music, etc.
 * 
 */
class RManager {
 public:
  RManager() : textures_{} {}
  ~RManager();
  bool LoadTexture(const Scenes scene, const char *path);
  bool TextureLoaded(const Scenes scene) {
    return textures_[scene].id > 0;
  }
  const Texture2D & GetTexture(const Scenes scene) const;

 private:
  std::array<Texture2D, SIZE> textures_;
};