#include "GameWorld.h"

#include "CollisionLevel.h"
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

std::vector<GameObject*> GameWorld::GetObjectsInRadius(const sf::Vector2f& center, float radius) const
{
	std::vector<GameObject*> result;
	float r2 = radius * radius;

	for (auto& obj : objects)
	{
		sf::Vector2f diff = obj->getPosition() - center;
		float dist2 = diff.x * diff.x + diff.y * diff.y;

		if (dist2 <= r2)
			result.push_back(obj.get());
	}
	return result;
}
