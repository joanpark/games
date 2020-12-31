#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Node.h"

class GameObject : public Node
{
public:

    GameObject();
    GameObject(std::string name);

protected:

    void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const override
    {
        Node::onDraw(target, transform);
    }

private:
    
};


#endif // GAMEOBJECT_H