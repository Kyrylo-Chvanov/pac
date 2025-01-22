#include "rmanager.hh"
#include "raylib.h"

/**
 * @brief Load the texture and save it inside the manager.
 * 
 * 
 * @param id 
 * @param path 
 * @return int 0 on success, 1 if id already exists, 2 if failed 
 *         failed to load the texture. 
 */
int RManager::LoadTexture2D(const char *id, const char *path) {
  if (textures_.count(id))
    return 1;
  Texture2D texture{LoadTexture(path)};
  if (texture.id <= 0)
    return 2;
  textures_[id] = texture;
  return 0;
}

Texture2D RManager::GetTexture2D(const char *id) const {
  if (textures_.count(id)) 
    return textures_.at(id);
  return Texture2D{};
}

RManager::~RManager() {
  for (const auto& [id, texture] : textures_) {
    UnloadTexture(texture);
  }
}