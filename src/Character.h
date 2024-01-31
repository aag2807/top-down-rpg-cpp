//
// Created by Dev ATL on 26/1/24.
//

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

private:
    int windowWidth{};
    int windowHeight{};
};


#endif //CLASH_CHARACTER_H
