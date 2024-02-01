#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 0.016f;
}

void Enemy::tick(float deltaTime)
{
    if(!this->getAlive())
    {
        return;
    }

    // get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if(Vector2Length(velocity) < this->radius)
    {
        velocity = {};
    }

    BaseCharacter::tick(deltaTime);
    if(CheckCollisionRecs(this->target->getCollisionRec(), this->getCollisionRec()))
    {
        this->target->takeDamage(this->damagePerSec * deltaTime);
    }
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}


void Enemy::setIdleAnimations()
{
    this->run = this->idle;
}