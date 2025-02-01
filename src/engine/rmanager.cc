#include "rmanager.hh"

#include "raylib.h"
#include "scene.hh"

bool RManager::LoadTexture(const Scenes scene, const char *path) {
  if (scene >= SIZE) return false;
  if (TextureLoaded(scene)) UnloadTexture(textures_[scene]);
  textures_[scene] = ::LoadTexture(path);
  if (textures_[scene].id <= 0) return false;
  return true;
}

const Texture2D &RManager::GetTexture(const Scenes scene) const {
  return textures_[scene];
}

RManager::~RManager() {
  for (const auto &texture : textures_) {
    UnloadTexture(texture);
  }
}