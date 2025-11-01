#include "GameWorld.h"

#include "GameObject.h"


GameWorld::GameWorld(sf::RenderWindow& window): renderSystem(window)
{
}

void GameWorld::update(float dt)
{
	for (auto& obj : objects) {
		obj->update(dt);
	}

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
