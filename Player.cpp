#include "Player.h"

#include <iostream>
#include "BoxCollider.h"
#include "RigidBody.h"
#include "SpriteRenderer.h"

Player::Player(std::string name, GameWorld& gameWorld)
	: velocity(0.f, 0.f), speed(200.f), GameObject(name, gameWorld)
{

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("Sprites/player.png"))
    {
        std::cerr << "Error loading texture: " << "PLAYER TEXTURE" << std::endl;
    }

    addComponent<SpriteRenderer>(playerTexture, 0);
    addComponent<BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(32, 32));
    rigidBody = addComponent<RigidBody>();
}

Player::~Player()
{
}

void Player::handleInput()
{
    velocity = sf::Vector2f(0.0f, 0.0f);

    if (isKeyPressed(sf::Keyboard::Key::W))
        velocity.y = -speed;
    if (isKeyPressed(sf::Keyboard::Key::S))
        velocity.y = speed;
    if (isKeyPressed(sf::Keyboard::Key::A))
        velocity.x = -speed;
    if (isKeyPressed(sf::Keyboard::Key::D))
        velocity.x = speed;
}

void Player::update(float deltaTime)
{
    handleInput();
    rigidBody->setConstForce(velocity);
}

