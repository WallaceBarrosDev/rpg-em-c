#include "get_input.h"

int get_input() {
  char input[254];
  char *temp;
  int result = -1;
  
  while (true) {
    scanf("%s", input);

    if(strcmp(input, "menu") == 0) {
      game_set_screen(MENU);
      return result;
    }

    result = strtol(input, &temp, 10);
    
    if(*temp == '\0') {
      return result;
    }
    
    printf("Opção inválida!\n");
  }
}
