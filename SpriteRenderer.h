#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Component.h"
#include "Drawable.h"


class SpriteRenderer : public Component, public Drawable
{
public:
	SpriteRenderer(GameObject* owner, sf::Texture tex, int layer);
	~SpriteRenderer() override;

protected:
	sf::Sprite sprite;
	sf::Texture texture;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
