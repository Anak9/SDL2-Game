#include "Game.h"

SDL_Texture* playerTexture;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }



    if ( SDL_Init(SDL_INIT_EVERYTHING) == 0 )
    {
        std::cout << "SDL initialized..." << std::endl;

        this->window = SDL_CreateWindow (title, xpos, ypos, width, height, flags);
        if(this->window)
        {
            std::cout << "window created" << std::endl;
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (this->renderer)
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255); //white
            std::cout << "renderer created" << std::endl;
        }

        this->isRunning = true;

    }
    else
    {
        this->isRunning = false;
    }


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

    default:
        break;
    }
}

void Game::update()
{
    this->counter++;
    std::cout << "counter: " << this->counter << std::endl;
}

void Game::render()
{
    SDL_RenderClear(this->renderer);

    ///this is where we would add stuff to render


    SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
