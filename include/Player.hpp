#ifndef __Player__
#define __Player__

#include <iostream>
#include <SDL2/SDL.h>
#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"
#include "InputHandler.hpp"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams *pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
private:
    void handleInput();
};

#endif