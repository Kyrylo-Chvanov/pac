#include <utility>
#include "smanager.hh"
#include "exception.hh"
#include "raylib.h"
#include "scene.hh"
#include "trigger.hh"

void SManager::ChangeScene(const Scenes scene) {
  current_scene_ = std::make_unique<Scene>(Scene{scene, GetSceneBackground(scene), GetSceneExits(scene)});
}

const Texture2D & SManager::GetSceneBackground(const Scenes scene) {
  if (!resources_.TextureLoaded(scene)) {
    switch (scene) {
      case INIT:
        if (!resources_.LoadTexture(scene, INIT_BG_PATH)) {
          throw TextureLoadingException{"failed to load 'init' background"};
        }
        break;
      case WHAT:
        if (!resources_.LoadTexture(scene, WHAT_BG_PATH)) {
          throw TextureLoadingException{"failed to load 'what' background"};
        }
        break;
      case SIZE:
        break;
      }
  }
  return resources_.GetTexture(scene);
}

const Exits SManager::GetSceneExits(const Scenes scene) {
  Exits exits;
  switch (scene) {
    case INIT:
      exits.emplace_back(std::make_pair(Trigger{Rectangle{0, 0, 50, 50}, camera_}, WHAT));
      break;
    case WHAT:
      exits.emplace_back(std::make_pair(Trigger{Rectangle{0, 0, 50, 50}, camera_}, INIT));
      break;
    case SIZE:
      break;
  }
  return exits;
}

void SManager::Update() {
  Scenes next_scene{current_scene_->GetNextSceneIfReady()};
  if (next_scene != Scenes::SIZE) {
    ChangeScene(next_scene);
  }
}