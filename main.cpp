#include <iostream>
#include <SDL2/SDL.h>

#include "Game.h"

Game *game = nullptr;

int main( int argc, char* argv[])
{
    game = new Game();

    game->init("Window Title Here", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, false);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return EXIT_SUCCESS;
}

