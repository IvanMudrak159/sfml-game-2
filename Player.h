#pragma once

#include <SFML/System/Vector2.hpp>

#include "GameObject.h"

class RigidBody;

class Player : public GameObject
{
private:
    sf::Vector2f velocity;
    float speed;

    RigidBody* rigidBody;

public:
    Player(std::string name, GameWorld& gameWorld);
    ~Player();
    void handleInput();
    void update(float dt);
};
