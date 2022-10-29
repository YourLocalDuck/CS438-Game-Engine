#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Sprite
{
protected:
    sf::Texture image;
    sf::Sprite sfsprite;
    float dx;
    float dy;
    float ddx;
    float ddy;
public:
    Sprite();
    Sprite(std::string imageName);
    ~Sprite();
    void update(sf::RenderWindow* gameWindow);
    void draw(sf::RenderWindow* gameWindow);
    void setImage(std::string imageName);
    void setPosition(int x, int y);
    int getXPosition();
    int getYPosition();
    void scale(float x, float y);
    void setAccelX(float x);
    float getAccelX();
    void setAccelY(float y);
    float getAccelY();
    void setVelX(float x);
    float getVelX();
    void setVelY(float y);
    float getVelY();
    float height();
    float width();
    virtual void bounceX();
    virtual void bounceY();
    bool checkCollision(Sprite* othersprite);
    void suspendSelf();
};

#endif