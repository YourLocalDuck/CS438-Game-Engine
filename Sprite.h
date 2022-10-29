#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Sprite
{
private:
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
    void bounceX();
    void bounceY();
    bool checkBounds(Sprite* othersprite);
};

#endif