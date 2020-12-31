////////////////////////////////////////////////////////////
//
// Copyright (C) 2020 Ken Bak (Dreamnauts)
// 
// Normal Scene
// 
////////////////////////////////////////////////////////////

#ifndef SCENE_NORMAL_H
#define SCENE_NORMAL_H

#include <SFML/Graphics.hpp>
#include "Node.h"
#include "Game.h"

class Scene_Normal : public Scene
{
public:
    Scene_Normal(Game* game);
    ~Scene_Normal()
    {

    }

protected:

    void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const override;

};


#endif // SCENE_NORMAL_H