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
  game = NULL; // evitar dangling pointer
}

Game_state get_game_state() {
  return game->game_state;
}

void set_game_state(Game_state state) {
  game->game_state = state;
}

// Implementação das novas funções

Interface get_interface() {
  return game->interface;
}

void set_interface(Interface iface) {
  game->interface = iface;
}

bool is_input_valid() {
  return game->input_is_valid;
}

void set_input_valid(bool valid) {
  game->input_is_valid = valid;
}

int get_input() {
  return game->input;
}

void set_input(int value) {
  game->input = value;
}

char* get_input_msg() {
  return game->input_msg;
}

void set_input_msg(const char* msg) {
  strncpy(game->input_msg, msg, sizeof(game->input_msg) - 1);
  game->input_msg[sizeof(game->input_msg) - 1] = '\0';
}
