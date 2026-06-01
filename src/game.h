#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdbool.h>

// Define as telas disponíveis no jogo
typedef enum {
  SCREEN_MENU,
  SCREEN_DUNGEON,
  SCREEN_COMBAT
} ScreenType;

// Estado global do jogo
typedef struct {
  ScreenType current_screen;
  ScreenType previous_screen; // Tela de onde veio (para retornar após combate/menu)
  bool is_running;
  bool has_saved_game;        // Indica se existe um jogo em andamento para continuar
} Game;

// Inicializa e libera memória do estado do jogo
void game_init();
void game_free();

// Gerenciamento de telas
void game_set_screen(ScreenType screen);
ScreenType game_get_current_screen();
ScreenType game_get_previous_screen();

// Ciclo de vida do aplicativo
void game_end();
bool game_is_running();

// Gerenciamento de estado da partida (Salvar/Carregar logic simplificado)
void game_start_new();      // Inicia nova partida
void game_end_session();    // Termina a sessão atual (volta ao menu)
bool game_has_saved_game(); // Verifica se há partida ativa

#endif
