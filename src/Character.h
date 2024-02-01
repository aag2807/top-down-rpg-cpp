#ifndef CLASH_CHARACTER_H
#define CLASH_CHARACTER_H

#include <raylib.h>
#include "BaseCharacter.h"

void HandleDirectionWhenKeyPressed(Vector2 &direction);

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);

    virtual void tick(float deltaTime) override;

    virtual Vector2 getScreenPos() override;

    void handlePlayerInputs();

    Rectangle getWeaponCollisionRec() { return this->weaponCollisionRec; };
    float getHealth() const { return this->health; }

    void takeDamage(float damage);

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon = LoadTexture("../characters/weapon_sword.png");
    Rectangle weaponCollisionRec{};
    float health = 100.f;
};


#endif //CLASH_CHARACTER_H
