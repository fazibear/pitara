#include "pad.h"
#include "state.h"

#include "raylib.h"

int main(void) {
  struct State state = {
      .current_frame = 0,
      .current_screen = PAD,
      .pad = {0},
      .neck = {{0}},
  };

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "πtara");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    switch (state.current_screen) {
    case PAD: {
      pad_update(&state);
    } break;
    default:
      break;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (state.current_screen) {
    case PAD:
      pad_draw(&state);
      break;
    default:
      break;
    }

    EndDrawing();
    state.current_frame++;
  }

  CloseWindow();
  return 0;
}
