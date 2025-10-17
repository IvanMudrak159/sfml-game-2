#include "SpriteRenderer.h"

#include "GameObject.h"
#include "GameWorld.h"

SpriteRenderer::SpriteRenderer(GameObject* owner, sf::Texture tex) : Component(owner), texture(tex), sprite(texture)
{
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	sprite.setTextureRect({ {0, 0}, sf::Vector2i(texture.getSize()) });

	owner->getGameWorld()->getRenderSystem().RegisterGameObject(this);
}

SpriteRenderer::~SpriteRenderer()
{
	owner->getGameWorld()->getRenderSystem().UnregisterGameObject(this);
}

void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = owner->getTransform();

	target.draw(sprite, states);

}
