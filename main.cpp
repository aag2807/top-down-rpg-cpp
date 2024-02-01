#include "raylib.h"
#include "src/dimension.h"
#include "raymath.h"
#include "src/Character.h"
#include "src/Enemy.h"
#include "src/Prop.h"
#include <string.h>
#include <string>

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

    auto goblin = Enemy{
        Vector2{700.f, 450.f},
        LoadTexture("../characters/goblin_idle_spritesheet.png"),
        LoadTexture("../characters/goblin_run_spritesheet.png")
    };

    auto slime = Enemy{
        Vector2{400.f, 600.f},
        LoadTexture("../characters/slime_idle_spritesheet.png"),
        LoadTexture("../characters/slime_run_spritesheet.png")
    };

    Enemy enemies[2] = {
        goblin,
        slime
    };

    for (auto &enemy: enemies)
    {
        enemy.setTarget(&knight);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPosition = Vector2Scale(knight.getWorldPos(), -1.f);

        // drawing map
        DrawTextureEx(map, mapPosition, 0, mapScale, WHITE);
        for (Prop prop: props)
        {
            prop.Render(knight.getWorldPos());
        }

        // draw health
        if (knight.getAlive())
        {
            std::string knightsHealth = "Health: ";
            knightsHealth.append(std::to_string(knight.getHealth()), 0, 5);
            DrawText(knightsHealth.c_str(), 55.f, 45.f, 40, RED);
        } else
        {
            DrawText("You died!", 100.f, 45.f, 40, RED);
        }

        // executing character logic
        knight.tick(GetFrameTime());
        if (
            knight.getWorldPos().x < 0.f || knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + window.width > map.width * mapScale ||
            knight.getWorldPos().y + window.height > map.height * mapScale
        )
        {
            knight.undoMovement();
        }

        //checking prop collision
        for (auto prop: props)
        {
            bool is_knight_colliding_prop = CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()),
                                                               knight.getCollisionRec());
            if (is_knight_colliding_prop)
            {
                knight.undoMovement();
            }
        }

        for (auto &enemy: enemies)
        {
            enemy.tick(GetFrameTime());
        }

        for (auto &enemy: enemies)
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && knight.getAlive())
            {
                auto weaponCollisionRec = knight.getCollisionRec();
                auto enemyRec = enemy.getCollisionRec();

                if (CheckCollisionRecs(weaponCollisionRec, enemyRec))
                {
                    enemy.setAlive(false);
                }
            }
        }

        EndDrawing();
    }
}
