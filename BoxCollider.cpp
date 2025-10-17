#include "BoxCollider.h"
#include "GameObject.h"
#include "GameWorld.h"

BoxCollider::BoxCollider(GameObject* owner, sf::Vector2f position, sf::Vector2f size): Component(owner)
{
	boundingBox = sf::FloatRect(position, size);

	debugRect.setSize(size);
	debugRect.setFillColor(sf::Color::Transparent);
	debugRect.setOutlineColor(sf::Color::Green);
	debugRect.setOutlineThickness(1.f);

	owner->getGameWorld()->getPhysicsSystem().Register(this);
}

BoxCollider::~BoxCollider()
{
	owner->getGameWorld()->getPhysicsSystem().Unregister(this);
}

void BoxCollider::update(float dt)
{
	Component::update(dt);
}

void BoxCollider::render(sf::RenderWindow& window)
{
	Component::render(window);
}

sf::FloatRect BoxCollider::getWorldBounds() const
{
	if (owner)
		return sf::FloatRect(owner->getPosition() + sf::Vector2f(boundingBox.position.x, boundingBox.position.y),
			sf::Vector2f(boundingBox.size.x, boundingBox.size.y));
	return boundingBox;
}

void BoxCollider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = owner->getTransform();

	target.draw(debugRect, states);
}
