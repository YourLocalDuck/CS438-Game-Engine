#include "Scene.h"

Scene::Scene()
    :gameWindow(nullptr)
{
    this->screenSize[0] = 800;
    this->screenSize[1] = 600;
    this->init();
}

Scene::Scene(int width, int height)
    :gameWindow(nullptr)
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
        delete i;
    }
    sprites->clear();
    delete sprites;
}

void Scene::init()
{
    this->gameWindow = new sf::RenderWindow(sf::VideoMode(screenSize[0],screenSize[1]), "Test Game", sf::Style::Titlebar | sf::Style::Close);
    this->gameWindow->setFramerateLimit(30);
    sprites = new std::vector<Sprite*>;
}

bool Scene::running()
{
    return this->gameWindow->isOpen();
}

void Scene::update()
{
    while (this->gameWindow->pollEvent(this->event))
        {
            switch (this->event.type)
            {
                case sf::Event::Closed:
                    this->gameWindow->close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape)
                        this->gameWindow->close();
                    break;
                default:
                    break;
            }
        }
    updateSpritePhysics();
}

void Scene::updateSpritePhysics()
{
    for (auto i : *sprites)
    {
        if (i->getXPosition() <= 0 || i->getXPosition() >= (gameWindow->getSize().x - i->width()))
        {
            i->bounceX();
        }

        if (i->getYPosition() <= 0 || i->getYPosition() >= (gameWindow->getSize().y - i->height()))
        {
            i->bounceY();
        }
        
        i->setVelX(i->getVelX()+i->getAccelX());
        i->setVelY(i->getVelY()+i->getAccelY());
        std::cout << i->getVelY() << std::endl;
        i->setPosition(i->getXPosition()+i->getVelX(), i->getYPosition()+i->getVelY());
    }
    sprites->at(0)->checkCollision(sprites->at(1));
}

void Scene::draw()
{
    this->gameWindow->clear();

    for (auto i : *sprites)
    {
        i->draw(this->gameWindow);
    }

    this->gameWindow->display();
}

Sprite* Scene::newSprite(std::string imgName)
{
    Sprite* createdSprite = new Sprite(imgName);
    this->sprites->push_back(createdSprite);
    return createdSprite;
}
