#include "Game.h"
#include "Scene_Intro.h"
#include "Scene_Normal.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "GameObject.h"


Game::Game(bool isEditor=false)
    : _window(sf::VideoMode(1280, 720), L"Unveil¢â")
    //, _testCircle()
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
    //_testCircle.setRadius(40.f);
    //_testCircle.setPosition(100.f, 100.f);
    //_testCircle.setFillColor(sf::Color::Cyan);

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
            updateIMGUI_MenuBar();
            updateIMGUI();
            updateIMGUI_SceneEditor();
        }

        update();
        render();
    }

    ImGui::SFML::Shutdown();
}

void Game::updateIMGUI_MenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            //ShowExampleMenuFile();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Window"))
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help"))
        {
            if(ImGui::MenuItem("About SFML Scene Editor")){}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
    /*
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_MenuBar;
    ImGui::Begin("SFML Scene Editor v0.1", 0, window_flags); // begin window

    static bool show_app_about = false;

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File")) 
        { 
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) 
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Window")) 
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) 
        {
            ImGui::MenuItem("About SFML Scene Editor", NULL, &show_app_about);
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    ImGui::End(); // end window
    */
}

void Game::updateIMGUI()
{    
    ImGui::Begin("Project Window"); // begin window

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
        sf::String tempStr = windowTitle;
        tempStr += L"¢â";
        _window.setTitle(tempStr);
    }

    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++)
        ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();


    ImGui::End(); // end window



}

void Game::updateIMGUI_SceneEditor()
{
    ImGui::Begin("Scene Hierarchy"); // begin window

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

    if (ImGui::Button("Create GameObject"))
    {
        if (_currentScene != NULL)
        {
            // test child gameobject
            GameObject* newObject = new GameObject("New Object");
            _currentScene->AddChild(newObject);
        }
    }


    //if (!ImGui::CollapsingHeader("Popups & Modal windows"))
    //    return;

    if (_currentScene != NULL)
    {    
        if (ImGui::TreeNode(_currentScene->getName().c_str()))
        {
            std::vector<Node*> children = _currentScene->GetChildren();
            for (const auto& element : children)
            {
                ImGui::Text(element->getName().c_str());

            }

           /*if (ImGui::BeginPopupContextItem("item context menu"))
            {
                if (ImGui::Selectable("Copy")) {}
                if (ImGui::Selectable("Paste")) {}

                //ImGui::SetNextItemWidth(-1);

                if (ImGui::Button("Close"))
                    ImGui::CloseCurrentPopup();

                ImGui::EndPopup();
            }*/


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

    //_window.draw(_testCircle);
    
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
