#include "SpriteRenderer.h"

#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>

#include "GameObject.h"

SpriteRenderer::SpriteRenderer(GameObject* owner, sf::Texture tex, int layer) : Component(owner), Drawable(layer)
{
	texture = std::make_unique<sf::Texture>(std::move(tex));
	sprite = std::make_unique<sf::Sprite>(*texture);

	sprite->setOrigin(sf::Vector2f(texture->getSize().x * 0.5f, texture->getSize().y * 0.5f));
	sprite->setPosition(sf::Vector2f(0.0f, 0.0f));
	sprite->setTextureRect({{0, 0}, sf::Vector2i(texture->getSize())});
}

SpriteRenderer::SpriteRenderer(GameObject* owner, std::string texPath, sf::Vector2i size, int layer): Component(owner), Drawable(layer)
{
	texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(texPath))
	{
		std::cerr << "Error loading texture: " << owner->name << std::endl;
	}

	sprite = std::make_unique<sf::Sprite>(*texture);

	sprite->setOrigin(sf::Vector2f(texture->getSize().x * 0.5f, texture->getSize().y * 0.5f));
	sprite->setPosition(sf::Vector2f(0.0f, 0.0f));
	sprite->setTextureRect({ {0, 0}, sf::Vector2i(texture->getSize()) });
	sf::Vector2u texSize = texture->getSize();

	sprite->setScale(sf::Vector2f(
		size.x / static_cast<float>(texSize.x),
		size.y / static_cast<float>(texSize.y))
	);
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = owner->getTransform();

	target.draw(*sprite, states);

}
