#include "render.h"
#include <stdio.h>

void render() {
  switch (game_get_current_screen()) {
    case SCREEN_MENU:
      render_menu();
      break;

    case SCREEN_PAUSE_MENU:
      render_pause_menu();
      break;

    case SCREEN_COMBAT:
      render_combat();
      break;

    case SCREEN_DUNGEON:
      render_dungeon();
      break;

    default:
      render_invalide_option();
  }
}

void render_menu() {
  printf("Menu Principal\n");
  printf("Selecione uma opção:\n");
  printf("1. Novo jogo\n2. Sair\n");
}

void render_pause_menu() {
  printf("Jogo pausado\n");
  printf("Selecione uma opção:\n");
  printf("1. Continuar jogo\n2. Finalizar jogo\n");
}

void render_dungeon() {
  printf("Dungeon\n");
  printf("Selecione uma opção:\n");
  printf("1. explorar.\n2. sair.\n");
}

void render_combat() {
  printf("Combate\n");
  printf("Selecione uma opção:\n");
  printf("1. Atacar.\n2. Curar.\n3. Fugir do combate.\n");
}

void render_invalide_option() {
  printf("Opção inválida!\n");
}

void render_message(const char *msg) {
  printf("%s\n", msg);
}

void render_end_game() {
    render_message("Finalizando jogo ...");
}
