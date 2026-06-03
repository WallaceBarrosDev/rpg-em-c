#include "entity.h"

Entity *create_entity(char *name, int life, int strength) {
  Entity *new_entity = malloc(sizeof(Entity));
  strcpy(new_entity->name, name);
  new_entity->life = life;
  new_entity->strength = strength;
  return new_entity;
}

void destroy_entity(Entity *entity) {
  free(entity);
}
