#include "SpriteRenderer.h"

#include "GameObject.h"

SpriteRenderer::SpriteRenderer(sf::Texture tex) : texture(tex), sprite(texture)
{
	//sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f));
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	sprite.setTextureRect({ {0, 0}, sf::Vector2i(texture.getSize()) });
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = owner->getTransform();

	target.draw(sprite, states);

}
