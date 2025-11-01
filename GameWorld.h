#pragma once

#include <memory>
#include <SFML/System/Vector2.hpp>

#include "PhysicsSystem.h"
#include "RenderSystem.h"

class GameObject;

namespace sf
{
	class RenderWindow;
}

class GameWorld
{
private:
	PhysicsSystem physicsSystem;
	RenderSystem renderSystem;
	std::vector<std::unique_ptr<GameObject>> objects;

public:
	template<typename T, typename... Args>
	T* createObject(Args&&... args) {
		auto obj = std::make_unique<T>(std::forward<Args>(args)...);
		T* ptr = obj.get();
		objects.push_back(std::move(obj));
		return ptr;
	}

	GameWorld(sf::RenderWindow& window);
	PhysicsSystem& getPhysicsSystem();
	RenderSystem& getRenderSystem();

	void update(float dt);
	void render();
	sf::Vector2i getMousePixelPosition() const;
	sf::Vector2f getMouseWorldPosition() const;

};
