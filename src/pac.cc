#include "engine/global.hh"
#include "engine/game.hh"

int main() {
  Game game{GAME_WIDTH, GAME_HEIGHT, "pac"};
  game.Run();
  return 0;
}
