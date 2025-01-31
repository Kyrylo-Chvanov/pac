#pragma once

#include "raylib.h"

/**
 * @brief Clickable area.
 * 
 */
class Trigger {
 public:
  Trigger(const Rectangle &area, const Camera2D &camera) : area_{area}, camera_{camera} {}
  virtual ~Trigger() = default;
  bool IsMouseButtonDown(int button) { return IsMouseInsideArea() && ::IsMouseButtonDown(button); }
  bool IsMouseButtonPressed(int button) { return IsMouseInsideArea() && ::IsMouseButtonPressed(button); }
  bool IsMouseButtonReleased(int button) { return IsMouseInsideArea() && ::IsMouseButtonReleased(button); }
  bool IsMouseButtonUp(int button) { return IsMouseInsideArea() && ::IsMouseButtonUp(button); }
  bool IsMouseInsideArea() { return CheckCollisionPointRec(GetScreenToWorld2D(GetMousePosition(), camera_), area_); }
  virtual void Draw() const { DrawRectangleRec(area_, Color{255, 0, 0, 100}); }
 private:
  Rectangle area_;
  const Camera2D &camera_;
};