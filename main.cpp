#include "raylib.h"
#include "src/dimension.h"
#include "raymath.h"

void HandleDirectionWhenKeyPressed(Vector2 &direction);

int main()
{
    Dimensions window = CreateNewDimension(385, 385);
    InitWindow(window.width, window.height, "Clash TOP DOWN");

    Texture2D map = LoadTexture("../nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPosition{0.00, 0.00};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        HandleDirectionWhenKeyPressed(direction);
        if(Vector2Length(direction) != 0.0)
        {
            Vector2Add(mapPosition, Vector2Normalize(direction));
        }

        // drawing map
        DrawTextureEx(map, mapPosition, 0, 4.0, WHITE);

        EndDrawing();
    }
}

void HandleDirectionWhenKeyPressed(Vector2 &direction)
{
    if (IsKeyDown(KEY_A))
    {
        direction.x -= 1.0;
    }

    if (IsKeyDown(KEY_D))
    {
        direction.x += 1.0;
    }

    if (IsKeyDown(KEY_S))
    {
        direction.y += 1.0;
    }

    if (IsKeyDown(KEY_W))
    {
        direction.y -= 1.0;
    }
}
