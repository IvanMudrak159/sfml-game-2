#include "CollisionLevel.h"

#include <SFML/Graphics/VertexArray.hpp>

#include "Plane.h"

CollisionLevel::CollisionLevel(float x, float y)
{
	this->position = sf::Vector2f(x,y);
}

CollisionLevel::~CollisionLevel()
{
}

void CollisionLevel::render(sf::RenderWindow& window)
{
	Plane plane = Plane();
	plane.setPosition(this->position);
	window.draw(plane);
}
