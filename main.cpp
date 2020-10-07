#include <iostream>

#include "Game.h"

Game *game = nullptr;

int main( int argc, char* argv[])
{

    ///game's frame rate - Frames Per Second
    const int FPS = 60;

    ///how long a frame is supposed to take - time between frames
    const int frameDelay = 1000/FPS;

    ///this is a really big integer
    Uint32 frameStart;
    int frameTime;


    game = new Game();

    game->init("Window Title Here", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, false);


    ///cada frame é uma execução desse while
    while (game->running())
    {
        ///this function returns the number of milliseconds passed since the initialization of the SDL library
        frameStart = SDL_GetTicks();


        game->handleEvents();
        game->update();
        game->render();


        ///tempo de execução dos três comandos acima (tempo de 1 frame)
        frameTime = SDL_GetTicks() - frameStart;



        ///this is supposed to delay the duration of each frame only if it's too fast
        if (frameDelay > frameTime)
        {
            SDL_Delay (frameDelay - frameTime);
        }
    }

    game->clean();

    return EXIT_SUCCESS;
}

