#include <GameObject.hpp>
#include <TextureManager.hpp>
GameObject::GameObject(const char *texturesheet, float x, float y)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
    // Testing Below for velocity
    velX = 0;
    velY = 0;
}
void GameObject::Update()
{

    // Set the height and width pixels
    srcRect.h = 32;
    srcRect.w = 32;
    //
    srcRect.x = 0;
    srcRect.y = 0;

    // Destination
    destRect.x = xpos += velX;
    destRect.y = ypos += velY;
    destRect.w = srcRect.w * 1;
    destRect.h = srcRect.h * 1;
}
// Below for testing purpose
void GameObject::setNewPosition(float x, float y)
{
    velX = x;
    velY = y;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}