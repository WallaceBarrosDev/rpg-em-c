#ifndef COMBAT_H
#define COMBAT_H

#include <stdbool.h>

#include "game.h"
#include "player.h"
#include "entity.h"

void init_combat(Entities *new_entities);
void end_combat();
void show_enimies();
bool combat_is_running();
void next_turn();

#endif
