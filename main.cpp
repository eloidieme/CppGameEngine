// C++ Standard Libraries
#include <iostream>

// Third-party librairies
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// Other files
#include "Game.hpp"

const int WINDOW_WIDTH{1920};
const int WINDOW_HEIGHT{1080};
const int FPS{60};
const int DELAY_TIME{static_cast<int>(1000.0f) / FPS};

int main(int argc, char *argv[])
{
    Uint32 frameStart, frameTime;

    std::cout << "Attempting to initialize game..." << '\n';
    if (TheGame::Instance()->init("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false))
    {
        std::cout << "Game initialized successfully !" << '\n';
        while (TheGame::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }
    else
    {
        std::cout << "Game initialization failed." << '\n';
        return -1;
    }

    std::cout << "Closing game..." << '\n';
    TheGame::Instance()->clean();

    return 0;
}