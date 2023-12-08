#ifndef __Game__
#define __Game__

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vector2D.hpp"
#include "TextureManager.hpp"
#include "InputHandler.hpp"
#include "GameObject.hpp"
#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Game
{
public:
    bool init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void quit();
    void update();
    void render();
    void clean();

    bool running() { return m_bRunning; }

    int m_currentFrame;

    static Game *Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new Game();
        }

        return s_pInstance;
    }

    SDL_Renderer *getRenderer() const { return m_pRenderer; }

    std::vector<GameObject *> m_gameObjects;

private:
    Game(){};
    static Game *s_pInstance;

    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    bool m_bRunning;
};

typedef Game TheGame;

#endif /* defined (__Game__) */