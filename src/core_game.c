#include <stdlib.h>
#include <string.h>
#include "core_game.h"

Core_game *game = NULL;

void game_init() {
  game = malloc(sizeof(Core_game));
  game->game_state = GAME_STATE_RUNNING;
  game->interface = INTERFACE_MENU;
  game->input_is_valid = true;
  game->input = 0;
}

Core_game *get_game_core() {
  return game;
}

void game_end() {
  free(game); 
}

Game_state get_game_state() {
  return game->game_state;
}
