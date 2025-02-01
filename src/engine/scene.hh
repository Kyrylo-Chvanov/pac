#pragma once

#include <vector>
#include "raylib.h"
#include "trigger.hh"

enum Scenes { INIT = 0, WHAT, SIZE };

using Exits = std::vector<std::pair<Trigger, Scenes>>;

/**
 * @brief Scene class that holds references to objects from RManager.
 * 
 */
class Scene {
 public:
  /**
   * @brief Construct a new Scene object
   * 
   * @param scene 
   * @param background 
   */
  Scene(const Scenes scene, const Texture2D &background, const Exits &exits)
      : scene_{scene},
        bg_source_{0, 0, static_cast<float>(background.width),
                   static_cast<float>(background.height)},
        exits_{exits},
        background_{background} {}
  
  /**
   * @brief Draw scene to the screen 
   * 
   */
  void Draw() const;

  /**
   * @brief Check if player tries to exit the current scene
   *        and return the next scene.
   *        Return Scenes::SIZE otherwise.
   *        
   * 
   * @return Scenes 
   */
  Scenes GetNextSceneIfReady() const;

 private:
  Scenes scene_; // current scene
  Rectangle bg_source_;
  Exits exits_; // exits to other scenes
  const Texture2D &background_;
};