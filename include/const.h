#pragma once

#include "raylib.h"
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define PAD_WIDTH 10
#define PAD_HEIGHT 10
#define PAD_NUM_X (SCREEN_WIDTH / PAD_WIDTH)
#define PAD_NUM_Y (SCREEN_HEIGHT / PAD_HEIGHT)

typedef enum Screen { PAD = 0 } Screen;

typedef struct State {
  int current_frame;
  Screen current_screen;
  Color pad[PAD_NUM_Y][PAD_NUM_X];
  Color current_color;
  bool neck[6][24];
} State;
