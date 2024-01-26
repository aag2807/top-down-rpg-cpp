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
    Character(int winWidth, int winHeight);

    Vector2 getWorldPosition();

    void tick(float deltaTime);

    void undoMovement();

    Rectangle GetCollisionRect();
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
    float width = 0.f;
    float height = 0.f;
    const float scale = 4.f;
    Vector2 worldPositionLastFrame{};

    void updateAnimationFrames(float deltaTime)
    {
        runningTime += deltaTime;
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrame)
            {
                frame = 0;
            }
        }
    }
};

#endif //CLASH_CHARACTER_H
