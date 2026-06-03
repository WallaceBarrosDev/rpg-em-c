#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdbool.h>

// Define as telas disponíveis no jogo
typedef enum {
  SCREEN_MENU,
  SCREEN_PAUSE_MENU,
  SCREEN_DUNGEON,
  SCREEN_COMBAT
} ScreenType;

// Estado global do jogo
typedef struct {
  ScreenType current_screen;
  ScreenType previous_screen;
  bool is_running;
  bool session_is_run;
} Game;

// Inicializa e libera memória do estado do jogo
void game_init();
void game_free();

// Gerenciamento de telas
void game_set_screen(ScreenType screen);
ScreenType game_get_current_screen();
ScreenType game_get_previous_screen();

//--- Ciclo de vida do aplicativo ---//

// Finaliza o game
void game_end();

// Verifica se o game ta rodando
bool game_is_running();

//--- Gerenciamento de estado da partida (Salvar/Carregar logic simplificado) ---//

// Inicia nova partida
void game_start_new();

// Indica se uma seção essa em andamento
bool game_session_is_run();

// Termina a sessão atual (volta ao menu)
void game_end_session();

#endif
