#include "PlayerController.h"

#include "Level.h"
#include "RigidBody.h"
#include "Tile.h"

void PlayerController::update(float dt)
{
    Component::update(dt);

    handleMovement();
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

    rigidBody->setConstForce(velocity);
}

void PlayerController::handleMouseInput()
{
    bool isPressed = isButtonPressed(sf::Mouse::Button::Left);

    if (isPressed && !wasLeftPressed)
    {
		sf::Vector2f worldPos = owner->getGameWorld()->getMouseWorldPosition();

        int tileX = static_cast<int>(worldPos.x) / level->GetTileSize().x;
        int tileY = static_cast<int>(worldPos.y) / level->GetTileSize().y;

        if (tileX >= 0 && tileX < level->GetLevelSize().x && tileY >= 0 && tileY < level->GetLevelSize().y)
        {
            Tile& tile = level->getTile(tileX, tileY);
            tile.setHighlight();
        }
    }
	wasLeftPressed = isPressed;
}


PlayerController::PlayerController(GameObject* owner, Level* level) : Component(owner), velocity(0.f, 0.f), speed(200.f), level(level)
{
    rigidBody = owner->addComponent<RigidBody>();
}
