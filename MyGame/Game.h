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
class Scene_Normal;
class Game
{
public:
    Game(bool isEditor);
    ~Game();

    void run();

    sf::Font & GetFont() { return _font;  }

    bool IsWindowOpen() { return _window.isOpen(); }

    void updateIMGUI_MenuBar();
    void updateIMGUI();
    void updateIMGUI_SceneEditor();

private:
    void processEvents();
    void update();
    void render();

    void createScene();
    void destroyScene();

private:
    sf::RenderWindow _window;
   // sf::CircleShape  _testCircle;

    //Scene_Intro  * _sceneIntro;
    Scene_Normal* _currentScene;
    sf::Font _font;

    bool _isEditor = false;

    // for imgui
    sf::Color bgColor;
    float color[3] = { 0.f, 0.f, 0.f };
    char windowTitle[255] = "Unveil";
    sf::Clock deltaClock;
};


#endif //GAME_H