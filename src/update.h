#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>

#include "game.h"
#include "input.h"
#include "render.h"

void update();

void process_command(const char *command);

void update_menu(int value);
void update_pause_menu(int value);
void update_dungeon(int value);
void update_combat(int value);

#endif
