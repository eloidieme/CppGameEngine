#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "Vector2D.hpp"

class Game;

class InputHandler
{
public:
    static InputHandler *Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }

        return s_pInstance;
    }

    void initializeJoysticks();
    bool joysticksInitialized()
    {
        return m_bJoysticksInitialized;
    }

    void update();
    void clean();

    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);

    const int m_joystickDeadZone{10000};

private:
    InputHandler() {}
    ~InputHandler() {}

    static InputHandler *s_pInstance;

    bool m_bJoysticksInitialized{false};
    std::vector<SDL_Joystick *> m_joysticks;
    std::vector<std::pair<Vector2D *, Vector2D *>> m_joystickValues;
};

typedef InputHandler TheInputHandler;

#endif