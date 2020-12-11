#include "Game.h"



Game::Game()
    : _window(sf::VideoMode(640, 480), "SFML Application")
    , _player()
{
    _player.setRadius(40.f);
    _player.setPosition(100.f, 100.f);
    _player.setFillColor(sf::Color::Cyan);
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