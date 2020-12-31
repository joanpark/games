#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "Node.h"

class Game;
class Scene : public Node
{
public:
    Scene(Game* game)
        : _game(game)
    {

    }

    ~Scene()
    {

    }


protected:

    void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const override
    {
        Node::onDraw(target, transform);
    }

    //sf::Sprite _bg;
    sf::Music _bgm;
    Game* _game;
};

#endif // SCENE_H