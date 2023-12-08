#include "Game.hpp"

Game *Game::s_pInstance = nullptr;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        std::cout << "SDL subsystems successfully initialized." << '\n';

        int flags = 0;
        if (fullscreen)
            flags = SDL_WINDOW_FULLSCREEN;

        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (m_pWindow != 0)
        {
            std::cout << "Window successfully created." << '\n';

            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

            if (!m_pRenderer)
            {
                std::cout << "Renderer could not be created:" << SDL_GetError();
                return false;
            }

            std::cout << "Renderer successfully created." << '\n';

            SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        }
        else
        {
            std::cout << "Window could not be created:" << SDL_GetError();
            return false;
        }
    }
    else
    {
        std::cout << "SDL could not be initialized:" << SDL_GetError();
        return false;
    }

    m_bRunning = true;

    if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }

    TheInputHandler::Instance()->initializeJoysticks();

    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
  
    return true;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::quit()
{
    m_bRunning = false;
}

void Game::update()
{
    for (std::vector<GameObject *>::size_type i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    for (std::vector<GameObject *>::size_type i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "Cleaning game." << '\n';
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);

    TheInputHandler::Instance()->clean();

    SDL_Quit();
}
