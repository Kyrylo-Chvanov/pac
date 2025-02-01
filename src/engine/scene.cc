#include "scene.hh"

#include "global.hh"
#include "raylib.h"

void Scene::Draw() const {
  DrawTexturePro(background_, bg_source_, GAME_RECT, Vector2{}, 0, WHITE);
}

Scenes Scene::GetNextSceneIfReady() const {
  for (const auto &exit : exits_) {
    if (exit.first.IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      return exit.second;
    }
  }
  return Scenes::SIZE;
}