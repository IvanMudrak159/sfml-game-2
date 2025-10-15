#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
    float speed;

public:
    Player(sf::Texture texture, float x, float y);
    void handleInput();
    void update(float dt);
    void render(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    sf::FloatRect getBounds() const;

    sf::Sprite getSprite();

};
