#pragma once
#include "PhysicsSystem.h"
#include "RenderSystem.h"


class GameWorld
{
private:
	PhysicsSystem physicsSystem;
	RenderSystem renderSystem;

public:
	GameWorld(sf::RenderWindow& window);
	~GameWorld();
	void update(float dt);
	void render() const;

	PhysicsSystem& getPhysicsSystem();
	RenderSystem& getRenderSystem();
};
