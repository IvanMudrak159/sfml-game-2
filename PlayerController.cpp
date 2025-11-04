#include "PlayerController.h"

#include "Level.h"
#include "RigidBody.h"

PlayerController::PlayerController(GameObject* owner, RigidBody& rb, Level* level) : Component(owner), velocity(0.f, 0.f),
speed(200.f), rigidBody(rb), level(level)
{
    agentAI = owner->getComponent<AgentAI>();
}

void PlayerController::Update(float dt)
{
    Component::Update(dt);

    //handleMovement();
    handleMouseInput();
}

void PlayerController::handleMovement()
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

    rigidBody.setConstForce(velocity);
}

void PlayerController::handleMouseInput()
{
	OnLeftMouseButtonPressed();
	OnRightMouseButtonPressed();
}

void PlayerController::OnLeftMouseButtonPressed()
{
    bool isPressed = isButtonPressed(sf::Mouse::Button::Left);

    if (isPressed && !wasLeftPressed)
    {
        sf::Vector2f mouseWorldPos = owner->getGameWorld()->getMouseWorldPosition();

        agentAI->SetDestination(mouseWorldPos);
    }
    wasLeftPressed = isPressed;
}

void PlayerController::OnRightMouseButtonPressed()
{
    bool isPressed = isButtonPressed(sf::Mouse::Button::Right);

    if (isPressed && !wasRightPressed)
    {
        agentAI->ClearPath();
    }
    wasRightPressed = isPressed;
}
