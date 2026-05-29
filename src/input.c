#include <stdio.h>
#include "core_game.h"

void input() {
  Core_game *game = get_game_core();
  scanf("%99s", game->input_msg);
}
