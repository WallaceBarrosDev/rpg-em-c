#include "get_input.h"

InputData inputData = {-1, "", false};

void input() {
  char input[254];
  char *temp;
  InputData result;

  // Inicializa o resultado
  result.value = -1;
  result.command[0] = '\0';
  result.is_number = false;

  while (true) {
    scanf("%s", input);

    // Copia o comando para a estrutura
    strncpy(result.command, input, sizeof(result.command) - 1);
    result.command[sizeof(result.command) - 1] = '\0';

    // Tenta converter para número
    result.value = strtol(input, &temp, 10);

    // Se converteu completamente, é um número
    if(*temp == '\0') {
      result.is_number = true;
      inputData = result;
    }

    // Se não é número, retorna como comando textual
    // O caller decide o que fazer com comandos como "menu"
    inputData = result;
  }
}

InputData get_input() {
  return inputData;
}
