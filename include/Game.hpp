#ifndef Game_h
#define Game_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Game
{
public:
    // Constructor for when opening game class
    Game();
    // Deconstructor for when closing game class
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    static SDL_Renderer *renderer;
    bool running() { return isRunning; };
    static SDL_Event event;
private:
    bool isRunning;
    SDL_Window *window;
};

#endif /* Game */