#pragma once

#include <memory>
#include "raylib.h"
#include "rmanager.hh"
#include "scene.hh"

constexpr auto INIT_BG_PATH{"scenes/init/background.png"};
constexpr auto WHAT_BG_PATH{"scenes/what/background.png"};

/**
 * @brief Scene manager
 * 
 */
class SManager {
 public:
  SManager(RManager &resources, const Camera2D &camera) : current_scene_{}, resources_{resources}, camera_{camera} {}
  void ChangeScene(const Scenes scene);
  void Draw() const { current_scene_->Draw(); }
  void Update();
 private:
  const Texture2D & GetSceneBackground(const Scenes scene);
  const Exits GetSceneExits(const Scenes scene);
  std::unique_ptr<Scene> current_scene_;
  RManager &resources_;
  const Camera2D &camera_;
};