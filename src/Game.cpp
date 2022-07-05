#include <SDL2/SDL_image.h>

#include <Game.hpp>
#include <iostream>
#include <TextureManager.hpp>
#include <GameObject.hpp>

GameObject *player;
GameObject *player_two;
SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem Initialised!... " << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created!.. " << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            // Initialize renderer color
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!..." << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = new GameObject("res/images/red_face.png", 0.0, 0.0);

    player_two = new GameObject("res/images/green_face.png", 40.0, 100.0);
}

void Game::handleEvents()
{
    SDL_Event event;
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

}

void Game::update()
{
    player->Update();
    player_two->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // This is where you add everything that needs to be rendered
    player->Render();
    player_two->Render();
    //
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!... " << std::endl;
}