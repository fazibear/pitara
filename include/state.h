#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

typedef enum Screen { PAD = 0 } Screen;

typedef struct Pad {
  int state[15][21];
} Pad;

typedef struct State {
  int current_frame;
  Screen current_screen;
  Pad pad;
} State;
