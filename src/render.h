#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>

#include "game.h"

void render();

void render_menu();
void render_pause_menu();
void render_combat();
void render_dungeon();
void render_combat();

void render_invalide_option();
void render_end_game();
void render_message(const char *mesg);

#endif
