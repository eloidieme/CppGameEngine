#include "Player.hpp"

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();

    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

    SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->joysticksInitialized())
    {
        if (TheInputHandler::Instance()->xvalue(0, 1) != 0)
        {
            m_velocity.setX(10 * TheInputHandler::Instance()->xvalue(0, 1));
        }
        if (TheInputHandler::Instance()->yvalue(0, 1) != 0)
        {
            m_velocity.setY(10 * TheInputHandler::Instance()->yvalue(0, 1));
        }
        if (TheInputHandler::Instance()->xvalue(0, 2) != 0)
        {
            m_velocity.setX(10 * TheInputHandler::Instance()->xvalue(0, 2));
        }
        if (TheInputHandler::Instance()->yvalue(0, 2) != 0)
        {
            m_velocity.setY(10 * TheInputHandler::Instance()->yvalue(0, 2));
        }
    }
}