#include "pad.h"
#include "raylib.h"

void pad_fade_dots(State *state) {
  for (int y = 0; y < PAD_NUM_Y; y++) {
    for (int x = 0; x < PAD_NUM_X; x++) {
      int c = state->pad[y][x].a;
      c -= 5;
      (c < 0) ? c = 0 : c;
      state->pad[y][x].a = c;
    }
  }
}

void pad_put_dot(State *state, int x, int y) {
  if (x >= 0 && x < PAD_NUM_X && y >= 0 && y < PAD_NUM_Y) {
    state->pad[y][x] = state->current_color;
  }
}

void pad_touch(State *state, int pad_x, int pad_y) {
  int x = pad_x / (PAD_WIDTH + 1);
  int y = pad_y / (PAD_HEIGHT + 1);
  pad_put_dot(state, x - 1, y);
  pad_put_dot(state, x + 1, y);
  pad_put_dot(state, x, y - 1);
  pad_put_dot(state, x, y + 1);
}

void pad_handle_input(State *state) {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) ||
      IsGestureDetected(GESTURE_TAP)) {
    state->current_color =
        (Color){rand() % 255, rand() % 255, rand() % 255, 255};
  }
  int x, y;
  if (GetGestureDetected() == GESTURE_HOLD) {
    x = GetTouchX();
    y = GetTouchY();
  }
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    x = GetMouseX();
    y = GetMouseY();
  }
  pad_touch(state, x, y);
}

void pad_update(State *state) {
  pad_fade_dots(state);
  pad_handle_input(state);
}

void pad_draw(State *state) {
  ClearBackground(BLACK);
  for (int y = 0; y < PAD_NUM_Y; y++) {
    for (int x = 0; x < PAD_NUM_X; x++) {
      DrawRectangle(x * (PAD_WIDTH + 1), y * (PAD_HEIGHT + 1), PAD_WIDTH,
                    PAD_HEIGHT, state->pad[y][x]);
    }
  }
}
