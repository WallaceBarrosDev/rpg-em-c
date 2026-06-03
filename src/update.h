#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>

#include "game.h"
#include "input.h"

void update();

void process_command(const char *command);

void update_menu(int value);

#endif
