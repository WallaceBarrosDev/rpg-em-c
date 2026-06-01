#include "game.h"

Game *game = NULL;

void game_init() {
  game = malloc(sizeof(Game));
  game->current_screen = SCREEN_MENU;
  game->previous_screen = SCREEN_MENU;
  game->is_running = true;
  game->has_saved_game = false;
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
  game->has_saved_game = true;
}

void game_end_session() {
  game->has_saved_game = false;
}

bool game_has_saved_game() {
  return game->has_saved_game;
}

void game_free() {
  free(game);
}
