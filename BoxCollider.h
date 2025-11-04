#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Component.h"

class GameObject;

class BoxCollider : public Component
{
public:
	BoxCollider(GameObject* owner, sf::Vector2f position, sf::Vector2f size);
	~BoxCollider() override;
	void Update(float dt) override;
	void render(sf::RenderWindow& window) override;

	sf::FloatRect getWorldBounds() const;

private:
	sf::FloatRect boundingBox;
};
