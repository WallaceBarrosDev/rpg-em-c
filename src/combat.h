#ifndef COMBAT_H
#define COMBAT_H

#include <stdbool.h>

#include "game.h"
#include "player.h"
#include "entity.h"

// Inicia um novo combate
void combat_init(Entities *new_entities);

// Finaliza o combate
void combat_end();

// Mostar todos os inimigos que estão no combate
void comabt_show_enimies();

// Verifica se o combate esta acontecendo
bool combat_is_running();

// Pula para o proximo turno
void combat_next_turn();

#endif
