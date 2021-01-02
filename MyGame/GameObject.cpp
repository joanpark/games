#include "GameObject.h"



GameObject::GameObject() :
	Node()
{

}

GameObject::GameObject(std::string name) :
	Node(name)
{

	sf::CircleShape* defaultDrawable = new sf::CircleShape();
	defaultDrawable->setRadius(40.f);
	defaultDrawable->setPosition(100.f, 100.f);
	defaultDrawable->setFillColor(sf::Color::Cyan);

	AddElement(defaultDrawable);
}