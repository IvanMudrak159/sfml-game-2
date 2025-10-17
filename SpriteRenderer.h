#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Component.h"


class SpriteRenderer : public Component, public sf::Drawable
{
public:
	SpriteRenderer(GameObject* owner, sf::Texture tex);
	~SpriteRenderer() override;

protected:
	sf::Sprite sprite;
	sf::Texture texture;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};