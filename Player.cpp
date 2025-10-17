#include "Player.h"

#include "BoxCollider.h"
#include "SpriteRenderer.h"

Player::Player(sf::Texture tex)
	: velocity(0.f, 0.f), speed(200.f)
{
    addComponent<SpriteRenderer>(tex);
    addComponent <BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(32, 32));

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
    move(velocity * deltaTime);
}

//void Player::render(sf::RenderWindow& window) const
//{
//    window.draw(sprite);
//}
