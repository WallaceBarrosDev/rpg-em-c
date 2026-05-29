#include <stdlib.h>
#include "core_game.h"

int validade_input(Core_game *game) {
  char *tmp;
  int input = strtol(game->input_msg, &tmp, 10);
  game->input_is_valid = true;
  
  if(tmp == game->input_msg || *tmp != '\0') {
    game->input_is_valid = false;
    return 0;
  }
  
  game->input = input;
  return 1;
}

void update() {
  Core_game *game = get_game_core();

  if(!validade_input(game))
    return;

  switch(game->input) {
    case 0:
      game->game_state = GAME_STATE_OVER;
      game->interface = INTERFACE_END;
    break;

    case 1:
      game->interface = INTERFACE_NEW_GAME;
    break;

    default:
      game->input_is_valid = false;
  }
}
