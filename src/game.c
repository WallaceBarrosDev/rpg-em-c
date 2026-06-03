#include "game.h"

Game *game = NULL;

void game_init() {
  game = malloc(sizeof(Game));
  game->current_screen = SCREEN_MENU;
  game->previous_screen = SCREEN_MENU;
  game->is_running = true;
  game->session_is_run = false;
}

void game_set_screen(ScreenType screen) {
  game->previous_screen = game->current_screen;
  game->current_screen = screen;
}

ScreenType game_get_current_screen() {
  return game->current_screen;
}

ScreenType game_get_previous_screen() {
  return game->previous_screen;
}

void game_end() {
  game->is_running = false;
}

bool game_is_running() {
  return game->is_running;
}

void game_start_new() {
  game->session_is_run = true;
}

void game_end_session() {
  game->session_is_run = false;
}

bool game_session_is_run() {
  return game->session_is_run;
}

void game_free() {
  free(game);
}
