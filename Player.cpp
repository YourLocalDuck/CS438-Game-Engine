#include "Player.h"

//Exactly the same as sprite, but the bounce is different

Player::Player(/* args */)
{
    this->sfsprite.setOrigin(sf::Vector2f(0,0));
}

Player::Player(std::string imageName)
{
    this->sfsprite.setOrigin(sf::Vector2f(0,0));
    this->setImage(imageName);
}

Player::~Player()
{
}

void Player::bounceX()
{
    this->dx = this->dx*-1;
    this->ddx = this->ddx*0;
}

void Player::bounceY()
{
    this->dy = this->dy*-1;
    this->ddy = this->ddy*0;
}

