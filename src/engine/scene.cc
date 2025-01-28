#include "scene.hh"

#include "global.hh"
#include "raylib.h"

void Scene::Draw() const {
  DrawTexturePro(background_, bg_source_, GAME_RECT, Vector2{}, 0, WHITE);
}