#include <stdlib.h>
#include "core_game.h"

int validate_input() {
  char *tmp;
  const char* msg = get_input_msg();
  int input = strtol(msg, &tmp, 10);
  set_input_valid(true);
  
  if(tmp == msg || *tmp != '\0') {
    set_input_valid(false);
    return 0;
  }
  
  set_input(input);
  return 1;
}

void update() {
  if(!validate_input())
    return;

  switch(get_input()) {
    case 0:
      set_game_state(GAME_STATE_OVER);
      set_interface(INTERFACE_END);
    break;

    case 1:
      set_interface(INTERFACE_NEW_GAME);
    break;

    default:
      set_input_valid(false);
  }
}
