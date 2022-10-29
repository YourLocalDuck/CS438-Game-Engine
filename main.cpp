#include "Scene.h"

int main(int argc, char *argv[])
{
    //Window
    Scene Game;
    Sprite* cat = Game.newSprite("assets/cat.png");
    cat->setPosition(1,100);
    cat->scale(.1, .1);
    cat->setAccelY(.025);
    cat->setAccelX(.074);

    Sprite* circle = Game.newSprite("assets/circle.png");
    circle->setPosition(300, 300);
    circle->scale(.1,.1);
    circle->setAccelX(.02);
    circle->setAccelY(.001);
    //Game Loop
    while (Game.running())
    {
        Game.update();
        Game.draw();
        std::cout << cat->getXPosition() << " " << cat->getYPosition() << std::endl;

    }
}