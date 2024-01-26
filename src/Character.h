//
// Created by Dev ATL on 26/1/24.
//

#ifndef CLASH_CHARACTER_H
#define CLASH_CHARACTER_H


#include <raylib.h>
void HandleDirectionWhenKeyPressed(Vector2 &direction);

class Character
{
public:
    Vector2 getWorldPosition()
    {
        return this->worldPos;
    }

    void setScreenPosition(int width, int height)
    {
        screenPos = {
                ((float) width / 2.0f - ((float) texture.width * 0.5f) / 6.0f),
                ((float) height / 2.0f - ((float) texture.height * 0.5f))
        };
    }

    void tick(float deltaTime)
    {
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
    }

private:
    Texture2D texture = LoadTexture("../characters/knight_idle_spritesheet.png");
    Texture2D idle = LoadTexture("../characters/knight_idle_spritesheet.png");
    Texture2D run = LoadTexture("../characters/knight_run_spritesheet.png");
    Vector2 screenPos{};
    Vector2 worldPos{};
    float runningTime{};
    int frame{};
    const int maxFrame = 6;
    const float updateTime = 1.f / 12.f;
    const float speed = 0.2f;
    float rightLeft = 1.f;

    void updateAnimationFrames(float deltaTime)
    {
        runningTime += deltaTime;
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrame)
                frame = 0;
        }
    }
};

#endif //CLASH_CHARACTER_H
