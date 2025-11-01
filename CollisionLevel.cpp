#include "CollisionLevel.h"

#include "Plane.h"

CollisionLevel::CollisionLevel(GameWorld& gameWorld, float x, float y) : gameWorld(gameWorld)
{
	this->position = sf::Vector2f(x,y);
	plane = new Plane(gameWorld);
	plane->setPosition(this->position);
}

CollisionLevel::~CollisionLevel()
{
	delete plane;
}
