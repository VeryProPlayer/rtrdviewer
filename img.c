#include "raylib.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please provide an image path.\n");
    return 1;
  }
  const char *imagePath = argv[1];
  Image image = LoadImage(imagePath);

  if (image.data == NULL) {
    printf("Error: Could not load image '%s'\n", imagePath);
    return 1;
  }
  InitWindow(image.width, image.height, "rtrdviewer");
  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image); 

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();
  }
  UnloadTexture(texture);
  CloseWindow();

  return 0;
}
