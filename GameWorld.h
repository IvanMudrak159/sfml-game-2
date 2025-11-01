#pragma once

#include "PhysicsSystem.h"
#include "RenderSystem.h"

namespace sf
{
	class RenderWindow;
}

class GameWorld
{
private:
	PhysicsSystem physicsSystem;
	RenderSystem renderSystem;

public:
	GameWorld(sf::RenderWindow& window);
	~GameWorld();
	PhysicsSystem& getPhysicsSystem();
	RenderSystem& getRenderSystem();

	void update(float dt);
	void render();

};
