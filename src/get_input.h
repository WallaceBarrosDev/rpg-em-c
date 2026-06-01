#ifndef GET_INPUT_H
#define GET_INPUT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para retornar tanto o valor numérico quanto comandos de texto
typedef struct {
  int value;          // Valor numérico digitado (ex: 1, 2, 3)
  char command[64];   // Comando textual digitado (ex: "menu", "inventario")
  bool is_number;     // true se o input foi um número, false se foi texto
} InputData;

// Obtém o input do usuário sem alterar estado do jogo
InputData get_input();

#endif
