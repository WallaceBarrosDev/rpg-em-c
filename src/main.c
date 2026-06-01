#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "player.h"
#include "entity.h"
#include "get_input.h"
#include "combat.h"

/* --- Interfaces de Tela (Screen Handlers) --- */

// Processa comandos de texto (ex: "menu", "inventario")
void process_command(const char* command) {
  if (strcmp(command, "menu") == 0) {
    game_set_screen(SCREEN_MENU);
  }
  // Adicionar novos comandos aqui no futuro (ex: "inventario", "ajuda")
}

// Tela: Masmorra (Dungeon)
void screen_dungeon() {
  printf("Você entrou na dungeon!\n");
  printf("Selecione uma opção:\n");
  printf("1. Explorar\n2. Sair\n");

  InputData input = get_input();

  // Verifica se é um comando textual
  if (!input.is_number) {
    process_command(input.command);
    return;
  }

  switch (input.value) {
    case 1:
      printf("Explorando...\n");
      // TODO: Implementar lógica de exploração
      break;

    case 2:
      printf("Saindo da masmorra...\n");
      game_set_screen(SCREEN_MENU);
      game_end_session(); // Reseta estado do jogo ao sair
      return;

    default:
      printf("Opção inválida!\n");
      break;
  }
}

// Tela: Menu Principal
void screen_menu() {
  printf("Menu Principal\n");
  printf("Selecione uma opção:\n");

  if (game_has_saved_game()) {
    printf("1. Continuar jogo\n2. Sair\n");
  } else {
    printf("1. Novo jogo\n2. Sair\n");
  }

  InputData input = get_input();

  // Verifica se é um comando textual
  if (!input.is_number) {
    process_command(input.command);
    return;
  }

  switch (input.value) {
    case 1:
      if (game_has_saved_game()) {
        printf("Jogo carregado!\n");
        // Retoma jogo existente
        game_set_screen(game_get_previous_screen());
        return;
      }

      printf("Iniciando novo jogo...\n");
      game_start_new();
      game_set_screen(SCREEN_COMBAT);
      break;

    case 2:
      printf("Saindo do jogo...\n");
      game_end();
      return;

    default:
      printf("Opção inválida!\n");
      break;
  }
}

// Tela: Combate
void screen_combat() {
  printf("Combate\n");
  show_player_stats();
  printf("Inimigos:\n");
  show_enimies();
  next_turn();
}

/* --- Renderizador Principal --- */

void render() {
  switch (game_get_current_screen()) {
    case SCREEN_MENU:
      screen_menu();
      break;

    case SCREEN_DUNGEON:
      screen_dungeon();
      break;

    case SCREEN_COMBAT:
      // Inicia combate se não estiver rodando
      if (!combat_is_running()) {
        Entity *zombie = create_entity("zombie", 100, 10);
        Entities *entities = create_entities(1);
        add_new_entity(entities, zombie);

        init_combat(entities);
      }
      screen_combat();
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
