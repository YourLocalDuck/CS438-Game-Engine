#ifndef SCENE_H
#define SCENE_H

#include "Player.h"

class Scene
{
    protected:
        sf::RenderWindow* gameWindow;
        sf::Event event;
        int screenSize[1];
        void init();
        std::vector<Sprite*>* sprites;
        void updateSpritePhysics();
        void updatePhysics(Sprite* sprite);
        Player player;
        
    public:
        Scene();
        Scene(int width, int height);
        ~Scene();
        bool running();
        void update();
        void draw();
        Sprite* newSprite(std::string imgName);
};

#endif