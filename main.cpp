#include "Scene.h"

int main(int argc, char *argv[])
{
    //Window
    Scene Game;

    //Making first cat sprite
    Sprite* cat = Game.newSprite("assets/cat.png");
    srand(time(NULL));
    cat->setPosition(1,100);
    cat->scale(.1, .1);
    cat->setAccelY((float) rand() / (RAND_MAX) / 6);
    cat->setAccelX((float) rand() / (RAND_MAX) / 6);

    //Game Loop
    while (Game.running())
    {
        Game.update();
        Game.draw();
    }
}