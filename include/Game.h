#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>


class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }

    protected:

    private:
        bool isRunning;
        int counter = 0;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif // GAME_H

