#include "render.h"

void render() {
  switch (game_get_current_screen()) {
    case SCREEN_MENU:
      render_menu();
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

void render_combat() {
  printf("Combate\n");
}

void render_dungeon() {
  printf("Dungeon\n");
}

void render_invalide_option() {
  printf("Opção inválida!\n");
}
