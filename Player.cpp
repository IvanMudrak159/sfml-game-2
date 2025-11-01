#include "Player.h"

#include <iostream>
#include "BoxCollider.h"
#include "PlayerController.h"
#include "RigidBody.h"
#include "SpriteRenderer.h"

Player::Player(std::string name, GameWorld& gameWorld, Level* level)
	: GameObject(name, gameWorld)
{

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("Sprites/player.png"))
    {
        std::cerr << "Error loading texture: " << "PLAYER TEXTURE" << std::endl;
    }

    addComponent<SpriteRenderer>(playerTexture, 1);
    addComponent<BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(32, 32));
    addComponent<PlayerController>(level);
}