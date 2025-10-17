#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class CollisionLevel
{
private:
	sf::Vector2f position;

public:
	CollisionLevel(float x, float y);
	~CollisionLevel();

	void render(sf::RenderWindow& window);

};
