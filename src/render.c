#include <stdio.h>
#include "core_game.h"
#include "render.h"

void render() {
  Core_game *game = get_game_core();

  if(!game->input_is_valid) {
    printf("Opção inválida. Tente novamente.\n");
    return;
  }

  switch(game->interface) {
    case INTERFACE_MENU:
      menu_interface();
    break;

    case INTERFACE_END:
      printf("Fim do jogo.\n");
    return;
  }

}

void menu_interface() {
  printf("Menu.\n");
  printf("Selecone um opção.\n");
  printf("0 - Sair.\n");
}
