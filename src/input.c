#include <stdio.h>
#include "core_game.h"

void input() {
  char buffer[100];
  scanf("%99s", buffer);
  set_input_msg(buffer);
}
