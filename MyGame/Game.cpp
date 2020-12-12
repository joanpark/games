#include "Game.h"
#include "Scene_Intro.h"


Game::Game()
    : _window(sf::VideoMode(1280, 720), L"Unveil¢â")
    , _testCircle()
{

    _window.setFramerateLimit(60);

    _sceneIntro = new Scene_Intro(this);

    // init font
    if (!_font.loadFromFile("resources/KoPubWorld Batang Bold.ttf"))
    {
        sf::err() << "font load error!!" << std::endl;
    }


    // player


    // test circle
    _testCircle.setRadius(40.f);
    _testCircle.setPosition(100.f, 100.f);
    _testCircle.setFillColor(sf::Color::Cyan);
}

Game::~Game()
{
    delete _sceneIntro;
}

void Game::run()
{
    while (_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void Game::update()
{
}

void Game::render()
{
    _window.clear();

    
    // draw intro scene
    sf::Transform identityTrans;
    _sceneIntro->draw(_window, identityTrans);

    _window.draw(_testCircle);
    
    
    _window.display();
}