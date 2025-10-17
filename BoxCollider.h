#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Component.h"


class BoxCollider : public Component, public sf::Drawable
{
public:
	BoxCollider(GameObject* owner, sf::Vector2f position, sf::Vector2f size);
	~BoxCollider() override;
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

	sf::FloatRect getWorldBounds() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::FloatRect boundingBox;
	sf::RectangleShape debugRect;
};