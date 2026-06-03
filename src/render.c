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
