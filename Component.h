#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameObject;

class Component
{

public:
    Component(GameObject* owner) : owner(owner) {}
	virtual ~Component() = default;
    virtual void update(float dt) {}
    virtual void render(sf::RenderWindow& window) {}

    GameObject* owner = nullptr;
};
