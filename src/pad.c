#include "raylib.h"
#include "screen.h"

void pad_update(int *current_screen) { *current_screen = PAD; }

void pad_draw(void) {
  DrawText("PiTARA", 20, 20, 40, LIGHTGRAY);
  DrawText("qweqweWAIT for 2 SECONDS...", 290, 220, 20, GRAY);
}
