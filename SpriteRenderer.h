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
	SpriteRenderer(GameObject* owner, std::string texPath, sf::Vector2i size, int layer);
	~SpriteRenderer() override;

protected:
	std::unique_ptr<sf::Sprite> sprite;
	std::unique_ptr<sf::Texture> texture;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
