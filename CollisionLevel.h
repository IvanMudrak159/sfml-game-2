#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameWorld.h"

class Plane;

class CollisionLevel
{
private:
	sf::Vector2f position;
	GameWorld& gameWorld;

public:
	CollisionLevel(GameWorld& gameWorld, float x, float y);
	~CollisionLevel();
};
