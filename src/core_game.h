#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <stdbool.h>
#include "render.h"

typedef enum {
  GAME_STATE_RUNNING,
  GAME_STATE_OVER
} Game_state;

typedef struct {
  char input_msg[254];
  int input;
  bool input_is_valid;
  Game_state game_state;
  Interface interface;
} Core_game;

void game_init(void);
Core_game *get_game_core();
Game_state get_game_state();
void set_game_state(Game_state state);
void game_loop(void);
void game_end(void);

// Novas funções getter/setter para desacoplamento
Interface get_interface();
void set_interface(Interface iface);
bool is_input_valid();
void set_input_valid(bool valid);
int get_input();
void set_input(int value);
char* get_input_msg();
void set_input_msg(const char* msg);

#endif
