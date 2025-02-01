#include "engine/exception.hh"
#include "engine/global.hh"
#include "engine/game.hh"
#include <iostream>

int main() {
  Game game{GAME_WIDTH, GAME_HEIGHT, "pac"};
  try {
    game.Run();
  } catch (const GameException &error) {
    std::cerr << error.what() << std::endl;
    return 1;
  }
  return 0;
}
