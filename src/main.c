#include "raylib.h"

#define WIDTH 900
#define HEIGHT 600

#define FPS 120

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "cecosystem");
    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
