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

Entity *entity_create(char *name, int life, int strength);
void entity_destory(Entity *entity);

#endif
