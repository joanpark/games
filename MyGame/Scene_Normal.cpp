#include "Scene_Normal.h"

using namespace sf;

Scene_Normal::Scene_Normal(Game* game) :
	Scene(game)
{
	// Background
	Texture t1;
	t1.loadFromFile("images/Background_white.png");

	Sprite* bg = new Sprite();
	bg->setTexture(t1);
	AddElement(bg);


	// BGM
	if (!_bgm.openFromFile("resources/17 Blackwell Academy.ogg"))
	{
		sf::err() << "bgm open error!!" << std::endl;
	}
	else
	{
		// Play the music
		_bgm.play();
	}

	Text* text = new Text();
	text->setFont(_game->GetFont());
	text->setCharacterSize(40);
	text->setPosition(170.f, 150.f);
	text->setFillColor(sf::Color::Black);
	sf::String s = L"당신의 이름은 무엇입니까?";
	text->setString(s);
	AddElement(text);
}


void Scene_Normal::onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
{
	Scene::onDraw(target, transform);

	//target.draw(_bg);
}