////////////////////////////////////////////////////////////
//
// Copyright (C) 2020 Ken Bak (Dreamnauts)
// 
// Intro Scene
// 
////////////////////////////////////////////////////////////

#ifndef SCENE_INTRO_H
#define SCENE_INTRO_H

#include <SFML/Graphics.hpp>
#include "Node.h"
#include "Game.h"

class Scene_Intro : public Scene
{
public:
    Scene_Intro(Game* game);
    ~Scene_Intro()
    {

    }

protected:

    void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const override;

};


#endif // SCENE_INTRO_H