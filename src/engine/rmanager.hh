#pragma once

#include <map>

#include "raylib.h"

// Resource manager
class RManager {
 public:
  int LoadTexture2D(const char *id, const char *path);
  Texture2D GetTexture2D(const char *id) const;
  ~RManager();

 private:
  std::map<const char *, Texture2D> textures_;
};