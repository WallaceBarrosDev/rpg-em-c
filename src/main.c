#include <stdbool.h>

#include "game.h"
#include "player.h"
#include "render.h"
#include "input.h"
#include "update.h"

int main() {
  player_init();
  game_init();

  while (game_is_running()) {
    render();
    input();
    update();
  }

  player_free();
  game_free();
  return 0;
}
