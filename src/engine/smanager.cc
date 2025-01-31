#include "smanager.hh"
#include "rexception.hh"

void SManager::ChangeScene(const Scenes scene) {
  if (!resources_.BackgroundLoaded(scene)) {
    switch (scene) {
      case INIT:
        if (!resources_.LoadBackground(scene, INIT_BG_PATH))
          throw ResourceLoadingException{"failed to load init background"};
        break;
      case Size:
        break;
    }
  }
  current_scene_ = std::make_unique<Scene>(Scene{scene, resources_.GetBackground(scene)});
}