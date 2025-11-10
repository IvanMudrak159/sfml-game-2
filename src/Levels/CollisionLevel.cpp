#include "Levels/CollisionLevel.h"
#include "Core/GameWorld.h"
#include "Core/Plane.h"

CollisionLevel::CollisionLevel(GameWorld& gameWorld, float x, float y) : gameWorld(gameWorld)
{
	this->position = sf::Vector2f(x,y);

    Plane* plane = gameWorld.createObject<Plane>("Plane", gameWorld);
	plane->setPosition(this->position);
}

CollisionLevel::~CollisionLevel()
{
}
