#include "combat.h"
#include "game.h"

Entities *enimies = NULL;
bool combat_running = false;

void combat_init(Entities *new_enimies) {
  enimies = new_enimies;
  combat_running = true;
};

void combat_end() {
  destroy_entities(enimies);
  combat_running = false;
  game_set_screen(SCREEN_MENU);
  game_end_session();
}

bool combat_is_running() {
  return combat_running;
}

void combat_show_enimies() { 
  show_entities(enimies);
}

void combat_next_turn() {
  player_attack(&enimies->entitys[0]);
  if(!player_is_alive()) {
    printf("fim do combate, Você morreu.\n");
    combat_end();
    return;
  }

  for (int i = 0; i < enimies->size; i++) {
    player_defend(&enimies->entitys[i]);

    if(enimies->entitys[i].life <= 0) {
      enimies->entitys[i] = enimies->entitys[enimies->size - 1];
      enimies->size--;

      if(enimies->size == 0) {
        printf("fim do combate, Você venceu.\n");
        combat_end();
        return;
      }
    }
  }
}
