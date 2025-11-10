#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Component.h"
#include "Core/Drawable.h"

class DebugHighlighter : public Component, public Drawable
{
public:
	DebugHighlighter(GameObject* owner, sf::Vector2f position, sf::Vector2f size, sf::Color color);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape debugRect;

};
