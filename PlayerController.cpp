#include "PlayerController.h"
#include "Level.h"
#include "RigidBody.h"

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
	OnLeftMouseButtonPressed();
	OnRightMouseButtonPressed();
}

void PlayerController::OnLeftMouseButtonPressed()
{
    bool isPressed = isButtonPressed(sf::Mouse::Button::Left);

    if (isPressed && !wasLeftPressed)
    {
        sf::Vector2f mouseWorldPos = owner->getGameWorld()->getMouseWorldPosition();
        sf::Vector2f playerPos = owner->getPosition();

        auto getTileFromPosition = [&](sf::Vector2f pos) -> sf::Vector2i {
            return sf::Vector2i(
                static_cast<int>(pos.x) / level->GetTileSize().x,
                static_cast<int>(pos.y) / level->GetTileSize().y
            );
            };

        sf::Vector2i playerTile = getTileFromPosition(playerPos);
        sf::Vector2i mouseTile = getTileFromPosition(mouseWorldPos);

        //std::cout << "Player Tile: (" << playerTile.x << ", " << playerTile.y << ")\n";
        //std::cout << "Player pos: (" << playerPos.x << ", " << playerPos.y << ")\n";

        //std::cout << "Mouse Tile: (" << mouseTile.x << ", " << mouseTile.y << ")\n";
        //std::cout << "Mouse world pos: (" << mouseWorldPos.x << ", " << mouseWorldPos.y << ")\n";

        if (mouseTile.x >= 0 && mouseTile.x < level->GetLevelSize().x &&
            mouseTile.y >= 0 && mouseTile.y < level->GetLevelSize().y)
        {
            level->GoToTile(playerTile, mouseTile);
        }
    }
    wasLeftPressed = isPressed;
}

void PlayerController::OnRightMouseButtonPressed()
{
    bool isPressed = isButtonPressed(sf::Mouse::Button::Right);

    if (isPressed && !wasRightPressed)
    {
        level->ClearPath();
    }
    wasRightPressed = isPressed;
}

PlayerController::PlayerController(GameObject* owner, Level* level) : Component(owner), velocity(0.f, 0.f), speed(200.f), level(level)
{
    rigidBody = owner->addComponent<RigidBody>();
}
