#include "GameWorld.h"

#include "GameObject.h"


GameObject* GameWorld::createGameObject(const std::string& name)
{
	auto obj = std::make_unique<GameObject>(name, *this);
	GameObject* ptr = obj.get();
	objects.push_back(std::move(obj));
	return ptr;
}

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

sf::Vector2i GameWorld::getMousePixelPosition() const
{
	return sf::Mouse::getPosition(renderSystem.getWindow());
}

sf::Vector2f GameWorld::getMouseWorldPosition() const
{
	return renderSystem.getWindow().mapPixelToCoords(sf::Mouse::getPosition(renderSystem.getWindow()));
}


PhysicsSystem& GameWorld::getPhysicsSystem()
{
	return physicsSystem;
}

RenderSystem& GameWorld::getRenderSystem()
{
	return renderSystem;
}
