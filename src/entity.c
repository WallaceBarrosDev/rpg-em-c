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

Entities *create_entities(int max_size) {
  Entities *new_entities = malloc(sizeof(Entities));
  new_entities->entitys = malloc(sizeof(Entity) * max_size);
  new_entities->size = 0;
  new_entities->max_size = max_size;
  return new_entities;
}

void add_new_entity(Entities *entities, Entity *entity) {
  if(entities->size == entities->max_size) {
    printf("GAME: Limite de entidades alcançado.\n");
    return;
  }

  entities->entitys[entities->size] = *entity;
  entities->size++;
}

void show_entities(Entities *entities) {
  if(entities->size == 0) {
    printf("GAME: Nenhum inimigo encontrado.\n");
    return;
  }
  for (int i = 0; i < entities->size; i++) {
    printf("%s, vida, %d.\n", entities->entitys[i].name, entities->entitys[i].life);
  }
}

void destroy_entities(Entities *entities) {
  free(entities->entitys);
  free(entities);
}
