#include "Game.h"
#include "Scene_Intro.h"
#include "Scene_Normal.h"
#include "imgui.h"
#include "imgui-SFML.h"


Game::Game(bool isEditor=false)
    : _window(sf::VideoMode(1280, 720), L"Unveil��")
    , _testCircle()
    , _isEditor(isEditor)
{

    _window.setFramerateLimit(60);

    //_sceneIntro = new Scene_Intro(this);

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

    // imgui
    ImGui::SFML::Init(_window);
}

Game::~Game()
{
    destroyScene();
    //delete _sceneIntro;

}

void Game::run()
{
    while (_window.isOpen())
    {
        processEvents();

        if (_isEditor)
        {
            ImGui::SFML::Update(_window, deltaClock.restart());
            updateIMGUI();
            updateIMGUI_SceneEditor();
        }

        update();
        render();
    }

    ImGui::SFML::Shutdown();
}

void Game::updateIMGUI()
{    
    ImGui::Begin("Sample window"); // begin window

                                   // Background color edit
    if (ImGui::ColorEdit3("Background color", color)) {
        // this code gets called if color value changes, so
        // the background color is upgraded automatically!
        bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
        bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
        bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
    }

    // Window title text edit
    ImGui::InputText("Window title", windowTitle, 255);

    if (ImGui::Button("Update window title")) {
        // this code gets if user clicks on the button
        // yes, you could have written if(ImGui::InputText(...))
        // but I do this to show how buttons work :)
        _window.setTitle(windowTitle);
    }

    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++)
        ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();


    ImGui::End(); // end window



}

void Game::updateIMGUI_SceneEditor()
{
    ImGui::Begin("Scene View"); // begin window

    if (ImGui::Button("New Scene"))
    {
        destroyScene();
        createScene();
    }

    if (ImGui::Button("Remove Scene"))
    {
        destroyScene();

    }

    if (ImGui::Button("Save Scene"))
    {

    }

    //if (!ImGui::CollapsingHeader("Popups & Modal windows"))
    //    return;

    if (_currentScene != NULL)
    {    
        if (ImGui::TreeNode(_currentScene->getName().c_str()))
        {
            ImGui::Text("test1");
            if (ImGui::BeginPopupContextItem("item context menu"))
            {
                if (ImGui::Selectable("Set to zero")) {}
                if (ImGui::Selectable("Set to PI")) {}

                //ImGui::SetNextItemWidth(-1);

                if (ImGui::Button("Close"))
                    ImGui::CloseCurrentPopup();

                ImGui::EndPopup();
            }

            ImGui::TreePop();
        }
    }
    ImGui::End(); // end window
}

void Game::processEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void Game::update()
{
}

void Game::render()
{
    //_window.clear();
    _window.clear(bgColor);

    // draw intro scene
    sf::Transform identityTrans;
    //_sceneIntro->draw(_window, identityTrans);

    if (_currentScene != NULL)
    {
        _currentScene->draw(_window, identityTrans);
    }

    _window.draw(_testCircle);
    
    if (_isEditor) ImGui::SFML::Render(_window);


    _window.display();
}

void Game::createScene()
{
    _currentScene = new Scene_Normal(this);
    _currentScene->setName("Untitled...");
}

void Game::destroyScene()
{
    if (_currentScene != NULL)
    {
        delete _currentScene;
        _currentScene = NULL;
    }
}
