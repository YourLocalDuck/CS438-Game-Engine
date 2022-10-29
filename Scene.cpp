#include "Scene.h"

Scene::Scene()
    : gameWindow(nullptr)
{
    this->screenSize[0] = 800;
    this->screenSize[1] = 600;
    this->init();
}

Scene::Scene(int width, int height)
    : gameWindow(nullptr)
{
    this->screenSize[0] = width;
    this->screenSize[1] = height;
    this->init();
}

Scene::~Scene()
{
    if (this->gameWindow != nullptr)
        delete this->gameWindow;
    for (auto i : *sprites)
    {
        if (i != nullptr)
            delete i;
    }
    sprites->clear();
    delete sprites;
}

void Scene::init() // Extention to the constructors to initialize the player and the game window
{
    this->gameWindow = new sf::RenderWindow(sf::VideoMode(screenSize[0], screenSize[1]), "Test Game", sf::Style::Titlebar | sf::Style::Close);
    this->gameWindow->setFramerateLimit(60);
    sprites = new std::vector<Sprite *>;
    player.setImage("assets/platform.png");
    player.scale(.05, .1);
    player.setPosition(300, 500);
}

bool Scene::running()
{
    return this->gameWindow->isOpen();
}

void Scene::update() // react to any poll events.
{
    while (this->gameWindow->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->gameWindow->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                this->gameWindow->close();
            else if (event.key.code == sf::Keyboard::D)
                player.setAccelX(1);
            else if (event.key.code == sf::Keyboard::A)
                player.setAccelX(-1);
            else if (event.key.code == sf::Keyboard::W)
                player.setAccelY(-1);
            else if (event.key.code == sf::Keyboard::S)
                player.setAccelY(1);
            else
            {
                Sprite *cat = new Sprite("assets/cat.png");
                cat->setPosition(1, 100);
                cat->scale(.1, .1);
                cat->setAccelY((float)rand() / (RAND_MAX) / 6);
                cat->setAccelX((float)rand() / (RAND_MAX) / 6);
                sprites->push_back(cat);
            }
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
            {
                player.setAccelX(0);
                player.setVelX(0);
            }
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)
            {
                player.setAccelY(0);
                player.setVelY(0);
            }
            break;
        default:
            break;
        }
    }
    updateSpritePhysics();
}

void Scene::updateSpritePhysics() // Iterate through every sprite to calculate position
{
    int ctr = 0;
    for (auto i : *sprites)
    {
        if (i != nullptr)
            updatePhysics(i);
    }
    updatePhysics(&player);
    for (auto i : *sprites)
    {
        if (i != nullptr)
        {
            if (player.checkCollision(i))
            {
                updatePhysics(i);
            }
            if (!i->onScreen())
            {
                i->~Sprite();
                sprites->at(ctr) = nullptr;
            }
        }
        ctr++;
    }
}

void Scene::updatePhysics(Sprite *sprite) // Use dx, dy, ddx, and ddy to caluclate new position for sprite.
{
    if (sprite->getXPosition() <= 0 || sprite->getXPosition() >= (gameWindow->getSize().x - sprite->width()))
    {
        sprite->bounceX();
    }

    if (sprite->getYPosition() <= 0) // || sprite->getYPosition() >= (gameWindow->getSize().y - sprite->height()))
    {
        sprite->bounceY();
    }

    if (sprite->getYPosition() >= (2*gameWindow->getSize().y - sprite->height()))
    {
        sprite->outOfBounds();
    }

    sprite->setVelX(sprite->getVelX() + sprite->getAccelX());
    sprite->setVelY(sprite->getVelY() + sprite->getAccelY());
    sprite->setPosition(sprite->getXPosition() + sprite->getVelX(), sprite->getYPosition() + sprite->getVelY());
}

void Scene::draw() // Draw the screen after the new positions have been updated.
{
    this->gameWindow->clear();

    for (auto i : *sprites)
    {
        if (i != nullptr)
            i->draw(this->gameWindow);
    }
    player.draw(this->gameWindow);
    this->gameWindow->display();
}

Sprite *Scene::newSprite(std::string imgName) // Create a new sprite on the canvas.
{
    Sprite *createdSprite = new Sprite(imgName);
    this->sprites->push_back(createdSprite);
    return createdSprite;
}
