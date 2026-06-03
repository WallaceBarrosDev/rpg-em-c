#include "update.h"

void update() {
  InputData inputData = get_input();

  if (!inputData.is_number) {
    process_command(inputData.command);
  }

  switch (game_get_current_screen()) {
    case SCREEN_MENU:
      update_menu(inputData.value);
      break;

    case SCREEN_DUNGEON:
      // TODO: Implementar lógica de exploração
      break;

    case SCREEN_COMBAT:
      // TODO: Implementar lógica de combate
      break;
  }

}

void process_command(const char* command) {
  if (strcmp(command, "menu") == 0) {
    game_set_screen(SCREEN_MENU);
  }
  // Adicionar novos comandos aqui no futuro (ex: "inventario", "ajuda")
}

void update_menu(int value) {
  switch (value) {
    case 1:
      printf("embreve ...\n");
      break;

    case 2:
      game_end();
      break;

    default:
      printf("Opção inválida!\n");
      break;
  }
}
