#include "Player.h"

Player::Player(sf::Texture tex, float x, float y)
	: texture(tex) ,sprite(texture), velocity(0.f, 0.f), speed(200.f)
{
	//sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f));
    sprite.setTextureRect({ {0, 0}, sf::Vector2i(texture.getSize()) });

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
    sprite.move(velocity * deltaTime);
}

void Player::render(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

sf::Sprite Player::getSprite()
{
    return sprite;
}
