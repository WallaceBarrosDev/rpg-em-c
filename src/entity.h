#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[255];
  int life;
  int strength;
} Entity;

Entity *create_entity(char *name, int life, int strength);
void destroy_entity(Entity *entity);

typedef struct {
  Entity *entitys;
  int size;
  int max_size;
} Entities;

Entities *create_entities(int max_size);
void destroy_entities(Entities *entities);
void add_new_entity(Entities *entities, Entity *entity);

void show_entities(Entities *entities);

#endif
