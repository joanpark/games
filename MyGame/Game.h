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
    Game(bool isEditor);
    ~Game();

    void run();

    sf::Font & GetFont() { return _font;  }

    bool IsWindowOpen() { return _window.isOpen(); }

    void updateIMGUI();
    void updateIMGUI_SceneEditor();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow _window;
    sf::CircleShape  _testCircle;

    Scene_Intro  * _sceneIntro;
    sf::Font _font;

    bool _isEditor = false;

    // for imgui
    sf::Color bgColor;
    float color[3] = { 0.f, 0.f, 0.f };
    char windowTitle[255] = "ImGui + SFML = <3";
    sf::Clock deltaClock;
};


#endif //GAME_H