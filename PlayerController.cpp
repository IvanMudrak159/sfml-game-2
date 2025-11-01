#include "PlayerController.h"

#include "RigidBody.h"


void PlayerController::handleInput()
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

void PlayerController::update(float dt)
{
	Component::update(dt);

    handleInput();
    rigidBody->setConstForce(velocity);
}

PlayerController::PlayerController(GameObject* owner) : Component(owner), velocity(0.f, 0.f), speed(200.f)
{
    rigidBody = owner->addComponent<RigidBody>();
}
