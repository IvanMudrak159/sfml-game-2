#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameWorld.h"

class GameObject;

class Component
{

public:
    Component(GameObject* owner) : owner(owner) {}
    virtual ~Component() = default;
    virtual void Update(float dt) {}
    virtual void render(sf::RenderWindow& window) {}

    GameObject* owner;
};
