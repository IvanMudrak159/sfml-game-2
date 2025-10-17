#include "BoxCollider.h"

#include "GameObject.h"

BoxCollider::BoxCollider(sf::Vector2f position, sf::Vector2f size)
{
	boundingBox = sf::FloatRect(position, size);

	debugRect.setSize(size);
	debugRect.setFillColor(sf::Color::Transparent); // прозорий всередині
	debugRect.setOutlineColor(sf::Color::Green);      // червоний контур
	debugRect.setOutlineThickness(1.f);
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::update(float dt)
{
	Component::update(dt);
}

void BoxCollider::render(sf::RenderWindow& window)
{
	Component::render(window);
}

void BoxCollider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = owner->getTransform();

	target.draw(debugRect, states);
}
