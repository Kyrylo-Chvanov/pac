#pragma once

#include "raylib.h"

enum Scenes { INIT = 0, Size };

constexpr auto INIT_BG_PATH{"scenes/init/background.png"};

class Scene {
 public:
  Scene(const Texture2D &background)
      : background_{background},
        bg_source_{0, 0, static_cast<float>(background.width),
                   static_cast<float>(background.height)} {}
  void Draw() const;

 private:
  const Texture2D &background_;
  Rectangle bg_source_;
};