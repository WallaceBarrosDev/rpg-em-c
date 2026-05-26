#ifndef CORE_GAME_H
#define CORE_GAME_H

enum game_state {
  GAME_STATE_RUNNING,
  GAME_STATE_OVER
};

typedef struct {
  char output_msg[254];
  char input_msg[254];
  int input;
  int game_state;
} Core_game;

void game_init(void);
void game_loop(void);
void game_end(void);

void input(void);
void update(void);
void render(void);

#endif
