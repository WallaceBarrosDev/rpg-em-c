#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "entity.h"

typedef struct {
  int left_hand;
  int right_hand;
} Body;

typedef struct {
  char name[20];
  int life;
  int strength;
  Body body;
} Player;

void player_init();
void player_free();

void show_player_stats();
bool player_is_alive();

void player_attack(Entity *entity);
void player_defend(Entity *entity);

#endif
