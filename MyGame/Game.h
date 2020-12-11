////////////////////////////////////////////////////////////
//
// Copyright (C) 2020 Ken Bak (Dreamnauts)
// 
// definition of Game class
// 
////////////////////////////////////////////////////////////

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow _window;
    sf::CircleShape  _player;
};


#endif //GAME_H