#include "entities.h"
#include "entity.h"

ListEntities *listEntities = NULL;

bool listEntities_is_null() {
  return listEntities == NULL;
}

void listEntities_creates(int max_size) {
  listEntities = malloc(sizeof(ListEntities));
  listEntities->max_size = max_size;
  listEntities->size = 0;
  listEntities->entityes = calloc(max_size,sizeof(Entity));
}

void listEntities_destory() {
  free(listEntities->entityes);
  free(listEntities);
}

bool array_is_full() {
  return listEntities->size >= listEntities->max_size;
}

void listEntities_add(Entity entity) {
  if(array_is_full()) return;
  listEntities->entityes[listEntities->size] = entity;
  listEntities->size++;
}

Entity listEntities_get_entities(int i) {
  return listEntities->entityes[i];
}
