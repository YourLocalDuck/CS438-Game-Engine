#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player : public Sprite
{
private:
    /* data */
public:
    Player(/* args */);
    Player(std::string imageName);
    ~Player();
    void bounceX();
    void bounceY();
};

#endif