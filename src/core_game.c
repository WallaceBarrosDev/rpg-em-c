#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "core_game.h"

Core_game *game = NULL;

void game_init() {
  game = malloc(sizeof(Core_game));
  game->game_state = GAME_STATE_RUNNING;
  game->input = 0;
}

void game_end() {
  free(game); 
}

void game_loop() {
  while (game->game_state == GAME_STATE_RUNNING) {
    input();
    update();
    render();
  }
}

void input() {
  scanf("%99s", game->input_msg);
}

int validade_input() {
  char *tmp;
  int input = strtol(game->input_msg, &tmp, 10);
  
  if(tmp == game->input_msg || *tmp != '\0') {
    strcpy(game->output_msg, "Input inválido");
    return 0;
  }
  
  game->input = input;
  return 1;
}

void update() {
  if(!validade_input())
    return;

  switch(game->input) {
    case 0:
      game->game_state = GAME_STATE_OVER;
      strcpy(game->output_msg, "Saindo...");
      break;
    default:
      strcpy(game->output_msg, "Caso inválido");
  }
}

void render() {
  printf("%s\n", game->output_msg);
  strcpy(game->output_msg, "");
}
