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

class Scene_Intro;
class Game
{
public:
    Game();
    ~Game();

    void run();

    sf::Font & GetFont() { return _font;  }

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow _window;
    sf::CircleShape  _testCircle;

    Scene_Intro  * _sceneIntro;
    sf::Font _font;
};


#endif //GAME_H