////////////////////////////////////////////////////////////
//
// Copyright (C) 2020 Ken Bak (Dreamnauts)
// 
// class definition of Node for sfml Scene Graph
// 
////////////////////////////////////////////////////////////

#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Drawable.hpp>


class Node
{
public:

    virtual ~Node()
    {
        // destruct elements
        for (std::size_t i = 0; i < m_elements.size(); ++i)
            delete m_elements[i];
    }

    // ... functions to transform the node

    // ... functions to manage the node's children

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
    {
        // combine the parent transform with the node's one
        sf::Transform combinedTransform = parentTransform * m_transform;

        // let the node draw itself
        onDraw(target, combinedTransform);

        // draw its children
        for (std::size_t i = 0; i < m_children.size(); ++i)
            m_children[i]->draw(target, combinedTransform);

        // draw elements
        for (std::size_t i = 0; i < m_elements.size(); ++i)
            target.draw(*m_elements[i]);
    }

    void AddElement(sf::Drawable * drawable)
    {
        m_elements.push_back(drawable);
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;

    sf::Transform m_transform;
    std::vector<Node*> m_children;

    std::vector<sf::Drawable*> m_elements;
};

// a simple derived class: a node that draws a sprite
/*
class SpriteNode : public Node
{
public:

    // .. functions to define the sprite

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
        target.draw(m_sprite, transform);
    }

    sf::Sprite m_sprite;
};
*/

#endif // NODE_H