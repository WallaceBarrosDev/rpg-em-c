#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdbool.h>

typedef enum {
  MENU,
  DUNGEON,
  COMBAT
} Screens;

typedef struct {
  Screens screen;
  Screens pause_screen;
  bool is_running;
  bool is_play;
} Game;

void game_init();
void game_free();

void game_set_screen(Screens screen);
Screens game_get_screen();
Screens game_get_pause_screen();

void game_end();
bool game_is_running();

void game_play();
void game_stop();
bool game_is_play();


#endif
