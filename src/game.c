#include "game.h"

Game *game = NULL;

void game_init() {
  game = malloc(sizeof(Game));
  game->screen = MENU;
  game->is_running = true;
  game->is_play = false;
}

void game_set_screen(Screens screen) {
  game->pause_screen = game->screen;
  game->screen = screen;
}

Screens game_get_screen() {
  return game->screen;
}

Screens game_get_pause_screen() {
  return game->pause_screen;
}

void game_end() {
  game->is_running = false;
}

bool game_is_running() {
  return game->is_running;
}

void game_play() {
  game->is_play = true;
}

void game_stop() {
  game->is_play = false;
}

bool game_is_play() {
  return game->is_play;
}


void game_free() {
  free(game);
}
