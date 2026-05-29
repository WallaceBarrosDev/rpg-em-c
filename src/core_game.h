#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <stdbool.h>

typedef enum {
  GAME_STATE_RUNNING,
  GAME_STATE_OVER
} Game_state;

typedef enum {
  INTERFACE_MENU,
  INTERFACE_END
} Interface;

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
void game_loop(void);
void game_end(void);

#endif
