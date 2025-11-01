#include "GameWorld.h"


GameWorld::GameWorld(sf::RenderWindow& window): renderSystem(window)
{
}

GameWorld::~GameWorld()
{
}

void GameWorld::update(float dt)
{
	physicsSystem.update(dt);
}

void GameWorld::render()
{
	renderSystem.update();
}

PhysicsSystem& GameWorld::getPhysicsSystem()
{
	return physicsSystem;
}

RenderSystem& GameWorld::getRenderSystem()
{
	return renderSystem;
}
