#include "prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex) : worldPos(pos), texture(tex)
{
}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPosition = Vector2Subtract(worldPos, knightPos);
    DrawTextureEx(this->texture, screenPosition, 0.f, this->scale, WHITE);
}

Rectangle Prop::GetCollisionRect(Vector2 knightPos)
{
    Vector2 screenPosition = Vector2Subtract(worldPos, knightPos);

    return Rectangle{
            screenPosition.x,
            screenPosition.y,
            texture.width * this->scale,
            texture.height * this->scale
    };
}
