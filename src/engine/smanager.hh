#pragma once

#include <memory>
#include "rmanager.hh"

/**
 * @brief Scene manager
 * 
 */
class SManager {
 public:
  SManager(RManager &resources) : current_scene_{}, resources_{resources} {}
  void ChangeScene(const Scenes scene);
  void Draw() const { current_scene_->Draw(); }
 private:
  std::unique_ptr<Scene> current_scene_;
  RManager &resources_;
};