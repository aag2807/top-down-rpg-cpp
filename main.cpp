#include "raylib.h"
#include "src/dimension.h"
#include "raymath.h"
#include "src/Character.h"

int main()
{
    Dimensions window = CreateNewDimension(385, 385);
    InitWindow(window.width, window.height, "Clash TOP DOWN");

    Texture2D map = LoadTexture("../nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPosition{0.00, 0.00};

    Character knight;
    knight.setScreenPosition(window.width, window.height);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPosition = Vector2Scale(knight.getWorldPosition(), -1.f);

        // drawing map
        DrawTextureEx(map, mapPosition, 0, 4.0, WHITE);

        // executing character logic
        knight.tick(GetFrameTime());

        EndDrawing();
    }
}
