#ifndef ENTITIES_H
#define ENTITIES_H

#include "entity.h"
#include "stdbool.h"

typedef struct {
  Entity *entityes;
  int size;
  int max_size;
} ListEntities;

// Verifica se a lista foi iniciada
bool listEntities_is_null();

// Criar uma nova lista de entidades
void listEntities_creates(int max_size);

// Finalizar uso da lista
void listEntities_destory();

// Adicionar nova entidade a lista
void listEntities_add(Entity entity);

// retorna uma entidades
Entity *listEntities_get_entity(int i);

#endif
