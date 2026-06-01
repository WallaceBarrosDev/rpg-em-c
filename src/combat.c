#include "combat.h"
#include "game.h"

Entities *enimies = NULL;
bool combat_running = false;

void init_combat(Entities *new_enimies) {
  enimies = new_enimies;
  combat_running = true;
};

void end_combat() {
  destroy_entities(enimies);
  combat_running = false;
  game_set_screen(MENU);
  game_stop();
}

bool combat_is_running() {
  return combat_running;
}

void show_enimies() { 
  show_entities(enimies);
}

void next_turn() {
  player_attack(&enimies->entitys[0]);
  if(!player_is_alive()) {
    printf("fim do combate, Você morreu.\n");
    end_combat();
    return;
  }

  for (int i = 0; i < enimies->size; i++) {
    player_defend(&enimies->entitys[i]);

    if(enimies->entitys[i].life <= 0) {
      enimies->entitys[i] = enimies->entitys[enimies->size - 1];
      enimies->size--;

      if(enimies->size == 0) {
        printf("fim do combate, Você venceu.\n");
        end_combat();
        return;
      }
    }
  }
}
