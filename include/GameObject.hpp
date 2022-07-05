#pragma once
#include <Game.hpp>

class GameObject
{
public:
    GameObject(const char *testuresheet, float x, float y);
    ~GameObject();

    void Update();
    void Render();
    // Testing the below
    void setNewPosition(float x, float y);

private:
    float xpos;
    float ypos;

    float velX;
    float velY;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
};