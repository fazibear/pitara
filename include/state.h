#pragma once

#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

typedef enum Screen { PAD = 0 } Screen;

typedef struct State {
  int current_frame;
  Screen current_screen;
  int pad[15][21];
  bool neck[6][24];
} State;
