#include "player.h"

Player *player = NULL;

void player_init() {
  player = malloc(sizeof(Player));
  strcpy(player->name, "Wallace");
  player->life = 100;
  player->strength = 10;
}

void player_free() {
  free(player);
}

void show_player_stats() {
  printf("%s, %d, %d.\n", player->name, player->life, player->strength);
}

bool player_is_alive() {
  return player->life > 0;
}

void player_attack(Entity *entity) {
  entity->life -= player->strength;
};

void player_defend(Entity *entity) {
  player->life -= entity->strength;
};
