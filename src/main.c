#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "player.h"
#include "entity.h"
#include "get_input.h"
#include "combat.h"

/* interfaces */

void dungeon() {
  printf("Você entrou na dungeon!\n");
  printf("Selecione uma opção,\n");
  printf("1, Explorar.\n2, Sair.\n");
  
  switch (get_input()) {
    case -1:
      printf("Abrindo menu ...\n");
    return;

    case 1:
      printf("Explorando...\n");
    break;
    
    case 2:
      printf("Saindo...\n");
      game_set_screen(MENU);
      game_stop();
    return;
    
    default:
      printf("Opção inválida!\n");
    break;
  }
}

void menu() {
  printf("Menu Principal!\n");
  printf("Selecione uma opção,\n");
  if(game_is_play()) {
    printf("1, Continuar jogo.\n2, Sair.\n");
  } else {
    printf("1, Novo jogo.\n2, Sair.\n");
  } 

  switch (get_input()) {
    case -1:
      printf("Abrindo menu ...\n");
    return;

    case 1:
      if(game_is_play()) {
        printf("Jogo carregado!\n");
        game_play();
        game_set_screen(game_get_pause_screen());
        return;
      }

      printf("Novo jogo!\n");
      game_play();
      game_set_screen(COMBAT);
    break;
    
    case 2:
      printf("Saindo...\n");
      game_end();
    return;
    
    default:
      printf("Opção inválida!\n");
    break;
  }
}

void menu_combat() {
  printf("combate.\n");
  show_player_stats();
  printf("inimigos.\n");
  show_enimies();
  next_turn();
}

/* render */

void render() {
  switch (game_get_screen()) {
    case MENU:
      menu();
    break;
    
    case DUNGEON:
      dungeon();
    break;

    case COMBAT:
      if(get_input() == -1) {
        break;        
      };
      if(!combat_is_running()) {
        Entity *zombie = create_entity("zombie", 100, 10);
        Entities *entities = create_entities(1);
        add_new_entity(entities, zombie);
        
        init_combat(entities);
      }
      menu_combat();
    break;
  }
  printf("\n");
}

int main() {
  player_init();
  game_init();

  while (game_is_running()) {
    render();
  }

  player_free();
  game_free();
  return 0;
}
