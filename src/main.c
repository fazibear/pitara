#include "pad.h"
#include "screen.h"

#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 480;

  InitWindow(screenWidth, screenHeight, "πtara");

  Screen currentScreen = PAD;

  int framesCounter = 0; // Useful to count frames

  SetTargetFPS(60); // Set desired framerate (frames-per-second)

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    switch (currentScreen) {
    case PAD: {
      framesCounter++; // Count frames

      if (framesCounter > 120) {
        currentScreen = PAD;
      }
    } break;
    default:
      break;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (currentScreen) {
    case PAD:
      pad_draw();
      break;
    default:
      break;
    }

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
