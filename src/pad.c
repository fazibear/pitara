#include "raylib.h"
#include "state.h"

#define PAD_WIDTH 36
#define PAD_HEIGHT 30
#define PAD_NUM_X 21
#define PAD_NUM_Y 15
#define PAD_RED 255
#define PAD_GREEN 34
#define PAD_BLUE 255

void pad_fade_dots(State *state) {
  for (int y = 0; y < PAD_NUM_Y; y++) {
    for (int x = 0; x < PAD_NUM_X; x++) {
      if (state->pad.state[y][x] > 0) {
        state->pad.state[y][x]--;
      }
    }
  }
}

void pad_put_dot(State *state, int x, int y) {
  if (x >= 0 && x < PAD_NUM_X && y >= 0 && y < PAD_NUM_Y) {
    state->pad.state[y][x] = 100;
  }
}

void pad_handle_input(State *state) {
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    int x = GetMouseX();
    int y = GetMouseY();
    int pad_x = (x - 11) / (PAD_WIDTH + 1);
    int pad_y = (y - 6) / (PAD_HEIGHT + 1);
    if (pad_x >= 0 && pad_x < PAD_NUM_X && pad_y >= 0 && pad_y < PAD_NUM_Y) {
      pad_put_dot(state, pad_x - 1, pad_y);
      pad_put_dot(state, pad_x + 1, pad_y);
      pad_put_dot(state, pad_x, pad_y - 1);
      pad_put_dot(state, pad_x, pad_y + 1);
    }
  }
}

void pad_update(State *state) {
  pad_fade_dots(state);
  pad_handle_input(state);
}

void pad_draw(State *state) {
  ClearBackground(BLACK);
  for (int y = 0; y < PAD_NUM_Y; y++) {
    for (int x = 0; x < PAD_NUM_X; x++) {
      DrawRectangle(
          11 + x * (PAD_WIDTH + 1), 6 + y * (PAD_HEIGHT + 1), PAD_WIDTH,
          PAD_HEIGHT,
          (Color){PAD_RED, PAD_GREEN, PAD_BLUE, state->pad.state[y][x]});
    }
  }
}
