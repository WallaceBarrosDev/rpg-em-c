#include "update.h"
#include "entities.h"
#include "entity.h"
#include "game.h"
#include "player.h"
#include "render.h"
#include <strings.h>

void update() {
  InputData inputData = get_input();

  if (!inputData.is_number) {
    process_command(inputData.command);
    return;
  }

  switch (game_get_current_screen()) {
    case SCREEN_MENU:
      update_menu(inputData.value);
      break;

    case SCREEN_PAUSE_MENU:
      update_pause_menu(inputData.value);
      break;

    case SCREEN_DUNGEON:
      update_dungeon(inputData.value);
      break;

    case SCREEN_COMBAT:
      update_combat(inputData.value);
      break;
  }

}

bool command_is_equals(const char* command, const char* option, ScreenType screen) {
  return strcasecmp(command, option) == 0 && game_get_current_screen() != screen;
}

void process_command(const char* command) {
  if (command_is_equals(command, "menu", SCREEN_MENU)) {
    if(game_session_is_run()) {
      game_set_screen(SCREEN_PAUSE_MENU);
      return;
    }
    game_set_screen(SCREEN_MENU);
  }
  // Adicionar novos comandos aqui no futuro (ex: "inventario", "ajuda")
}

void update_menu(int value) {
  switch (value) {
    case 1:
      game_start_new();
      game_set_screen(SCREEN_DUNGEON);
      break;

    case 2:
      game_end();
      render_end_game();
      break;

    default:
      render_invalide_option();
  }
}

void update_pause_menu(int value) {
  switch (value) {
    case 1:
      game_set_screen(game_get_previous_screen());
      break;

    case 2:
      game_end_session();
      game_end();
      render_end_game();
      break;

    default:
      render_invalide_option();
  }
}

void update_dungeon(int value) {
  switch (value) {
    case 1:
      game_set_screen(SCREEN_COMBAT);
      break;

    case 2:
      game_set_screen(SCREEN_MENU);
      break;

    default:
      render_invalide_option();
  }
}

void update_combat(int value) {
  if(listEntities_is_null()) {
    Entity zombie = {"zombie", 60, 5};
    
    listEntities_creates(1);
    listEntities_add(zombie);
  }  

  switch (value) {
    case 1:
      player_attack(listEntities_get_entity(0));
      break;

    case 2:
      //TODO Curar
      break;

    case 3:
      //TODO fugir
      break;

    default:
      render_invalide_option();
  }
}
