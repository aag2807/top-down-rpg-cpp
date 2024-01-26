
#ifndef CLASH_PROP_H
#define CLASH_PROP_H

#include <raylib.h>

class Prop
{

public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 knightPos);
    Rectangle GetCollisionRect(Vector2 knightPos);

private:
    Texture2D texture{};
    Vector2 worldPos{};
    float scale = 4.f;
};

#endif //CLASH_PROP_H
