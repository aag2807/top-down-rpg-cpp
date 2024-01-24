#include "raylib.h"
#include "src/dimension.h"

int main()
{
    Dimensions window = CreateNewDimension(800, 450);

    InitWindow(window.width, window.height, "Clash TOP DOWN");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RED);

        EndDrawing();
    }
}
