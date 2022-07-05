#pragma once
#include <iostream>
#include <SDL2/SDL_image.h>
#include "GameObject.hpp"

class KeyboardManager {

    public:
    KeyboardManager(GameObject &playerObject) {
        player = &playerObject;
    };
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            isRunning = false;
            break;
        }
        if (event.key.keysym.sym == SDLK_UP)
        {
            std::cout << "Up key pressed" << std::endl;
            player->setNewPosition(0, -5);
            break;
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
            std::cout << "Down key pressed" << std::endl;
            player->setNewPosition(0, 5);
            break;
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            std::cout << "Left key pressed" << std::endl;
            player->setNewPosition(-5, 0);
            break;
        }
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
            std::cout << "Right key pressed" << std::endl;
            player->setNewPosition(5, 0);
            break;
        }
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_UP)
        {
            player->setNewPosition(0, 0);
            std::cout << "Key is now up test" << std::endl;
            break;
        }
        if (event.key.keysym.sym == SDLK_DOWN)
        {
            player->setNewPosition(0, 0);
            std::cout << "Key is now up test" << std::endl;
            break;
        }
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            player->setNewPosition(0, 0);
            std::cout << "Key is now up test" << std::endl;
            break;
        }
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
            player->setNewPosition(0, 0);
            std::cout << "Key is now up test" << std::endl;
            break;
        }
    default:
        break;
    }
   
    private:
    SDL_Event event;
    GameObject* player;
    
};

