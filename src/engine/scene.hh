#pragma once

#include "raylib.h"

enum Scenes { INIT = 0, Size };

constexpr auto INIT_BG_PATH{"scenes/init/background.png"};

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
  Scene(const Scenes scene, const Texture2D &background)
      : scene_{scene},
        background_{background},
        bg_source_{0, 0, static_cast<float>(background.width),
                   static_cast<float>(background.height)} {}
  
  /**
   * @brief Draw scene to the screen 
   * 
   */
  void Draw() const;

 private:
  Scenes scene_;
  const Texture2D &background_;
  Rectangle bg_source_;
};