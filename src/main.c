#include "core_game.h"
#include "input.h"
#include "update.h"
#include "render.h"

int main() {
  game_init();

  menu_interface();
  while(get_game_state() == GAME_STATE_RUNNING) {
    input();
    update();
    render();
  }

  game_end();

  return 0;
}
