#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include "GameObject.h"

class Player : public GameObject
{
private:
    sf::Vector2f velocity;
    float speed;

public:
    Player(sf::Texture texture);
    void handleInput();
    void update(float dt);
};
