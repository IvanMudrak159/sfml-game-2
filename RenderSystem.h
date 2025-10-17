#pragma once
#include <vector>

#include "GameObject.h"


class RenderSystem
{
private:
	std::vector<sf::Drawable*> drawables;
	sf::RenderWindow& window;

public:
	RenderSystem(sf::RenderWindow& window);
	~RenderSystem();
	void update() const;
	void RegisterGameObject(sf::Drawable* drawable);
	void UnregisterGameObject(sf::Drawable* drawable);
};
