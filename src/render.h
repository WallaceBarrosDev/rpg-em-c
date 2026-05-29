#ifndef RENDER_H
#define RENDER_H

typedef enum {
  INTERFACE_MENU,
  INTERFACE_NEW_GAME,
  INTERFACE_END
} Interface;

void render(void);
void menu_interface();

#endif
