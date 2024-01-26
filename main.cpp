#include "raylib.h"
#include "src/dimension.h"
#include "raymath.h"
#include "src/Character.h"
#include "src/Prop.h"

int main()
{
    Dimensions window = CreateNewDimension(385, 385);
    InitWindow(window.width, window.height, "Clash TOP DOWN");

    Texture2D map = LoadTexture("../nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPosition{0.00, 0.00};

    Character knight{window.width, window.height};
    const float mapScale = 4.f;

    Prop props[2]
            {
                    Prop{Vector2{600.f, 300.f}, LoadTexture("../nature_tileset/Rock.png")},
                    Prop{Vector2{400.f, 500.f}, LoadTexture("../nature_tileset/Log.png")},
            };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPosition = Vector2Scale(knight.getWorldPosition(), -1.f);

        // drawing map
        DrawTextureEx(map, mapPosition, 0, mapScale, WHITE);
        for (Prop prop: props)
        {
            prop.Render(knight.getWorldPosition());
        }

        // executing character logic
        knight.tick(GetFrameTime());
        if (
                knight.getWorldPosition().x < 0.f || knight.getWorldPosition().y < 0.f ||
                knight.getWorldPosition().x + window.width > map.width * mapScale ||
                knight.getWorldPosition().y + window.height > map.height * mapScale
                )
        {
            knight.undoMovement();
        }

        EndDrawing();
    }
}
