#ifndef __Enemy__
#define __Enemy__

#include <iostream>
#include <SDL2/SDL.h>
#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams *pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
private:
};

#endif