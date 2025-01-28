#pragma once

#include "raylib.h"

inline constexpr int GAME_WIDTH{1280};
inline constexpr int GAME_HEIGHT{720};
inline constexpr int GAME_LEFT_CORNER_X{-GAME_WIDTH / 2};
inline constexpr int GAME_LEFT_CORNER_Y{-GAME_HEIGHT / 2};
inline constexpr Rectangle GAME_RECT{GAME_LEFT_CORNER_X, GAME_LEFT_CORNER_Y,
                                     GAME_WIDTH, GAME_HEIGHT};