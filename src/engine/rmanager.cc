#include "rmanager.hh"

#include "raylib.h"
#include "rexception.hh"
#include "scene.hh"

bool RManager::LoadBackground(const Scenes scene, const char *path) {
  if (scene >= Size) return false;
  if (BackgroundLoaded(scene)) UnloadTexture(backgrounds_[scene]);
  backgrounds_[scene] = LoadTexture(path);
  if (backgrounds_[scene].id <= 0) return false;
  return true;
}

const Texture2D &RManager::GetBackground(const Scenes scene) const {
  return backgrounds_[scene];
}

RManager::~RManager() {
  for (const auto &texture : backgrounds_) {
    UnloadTexture(texture);
  }
}

std::unique_ptr<Scene> RManager::LoadScene(const Scenes scene) {
  if (!BackgroundLoaded(scene)) {
    switch (scene) {
      case INIT:
        if (!LoadBackground(scene, INIT_BG_PATH))
          throw ResourceLoadingException{"failed to load init background"};
        break;
      case Size:
        break;
    }
  }
  return std::make_unique<Scene>(Scene{GetBackground(scene)});
}