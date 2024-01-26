#include <raylib.h>
#include <raymath.h>
#include "Character.h"

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

void Character::tick(float deltaTime)
{
    this->worldPositionLastFrame = worldPos;
    Vector2 direction{};
    HandleDirectionWhenKeyPressed(direction);
    float directionMagnitude = Vector2Length(direction);
    if (directionMagnitude != 0.0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
    }
    texture = directionMagnitude != 0.0 ? run : idle;
    updateAnimationFrames(deltaTime);

    //drawing Character
    Rectangle source{frame * (float) texture.width / 6.f, 0.f, rightLeft * (float) texture.width / 6.f,
                     (float) texture.height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float) texture.width / 6.0f, 4.0f * (float) texture.height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
};

Character::Character(int winWidth, int winHeight)
{
    this->width = texture.width / maxFrame;
    this->height = texture.height;

    screenPos = {
            static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
            static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)
    };
}

Vector2 Character::getWorldPosition()
{
    return this->worldPos;
}

void Character::undoMovement()
{
    this->worldPos = this->worldPositionLastFrame;
}


Rectangle Character::GetCollisionRect()
{
    return Rectangle{
            this->screenPos.x,
            this->screenPos.y,
            this->width * scale,
            this->height * scale
    };
}