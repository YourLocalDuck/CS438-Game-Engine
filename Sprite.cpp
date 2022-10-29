#include "Sprite.h"
#include <math.h>

Sprite::Sprite()
    :dx(0),dy(0),ddx(0),ddy(0)
{
    this->sfsprite.setPosition(sf::Vector2f(0,0));
}

Sprite::Sprite(std::string imageName)
{
    this->sfsprite.setPosition(sf::Vector2f(0,0));
    setImage(imageName);
}

Sprite::~Sprite()
{
}

void Sprite::setImage(std::string imageName)
{
    if (!this->image.loadFromFile(imageName))
    {
        std::cout << "Error: Image not found" << std::endl;
    }
    this->sfsprite.setTexture(image);
}

void Sprite::update(sf::RenderWindow* gameWindow)
{

}

void Sprite::draw(sf::RenderWindow* gameWindow)
{
    gameWindow->draw(this->sfsprite);
}

void Sprite::setPosition(int x, int y)
{
    this->sfsprite.setPosition(sf::Vector2f(x,y));
}

int Sprite::getXPosition()
{
    return this->sfsprite.getPosition().x;
}

int Sprite::getYPosition()
{
    return this->sfsprite.getPosition().y;
}

void Sprite::scale(float x, float y)
{
    this->sfsprite.setScale(sf::Vector2f(x,y));
}

void Sprite::setAccelX(float x)
{
    this->ddx = x;
}

float Sprite::getAccelX()
{
    return this->ddx;
}

void Sprite::setAccelY(float y)
{
    this->ddy = y;
}

float Sprite::getAccelY()
{
    return this->ddy;
}

void Sprite::setVelX(float x)
{
    this->dx = x;
}

float Sprite::getVelX()
{
    return this->dx;
}

void Sprite::setVelY(float y)
{
    this->dy = y;
}

float Sprite::getVelY()
{
    return this->dy;
}

float Sprite::height()
{
    return this->sfsprite.getGlobalBounds().height;
}

float Sprite::width()
{
    return this->sfsprite.getGlobalBounds().width;
}

void Sprite::bounceX()
{
    this->dx = this->dx*-1;
    this->ddx = this->ddx*-1;
}

void Sprite::bounceY()
{
    this->dy = this->dy*-1;
    this->ddy = this->ddy*-1;
}