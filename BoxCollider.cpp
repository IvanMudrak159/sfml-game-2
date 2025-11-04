#include "BoxCollider.h"

#include "DebugHighlighter.h"
#include "GameObject.h"
#include "GameWorld.h"

BoxCollider::BoxCollider(GameObject* owner, sf::Vector2f position, sf::Vector2f size): Component(owner)
{
	boundingBox = sf::FloatRect(position, size);

	owner->getGameWorld()->getPhysicsSystem().Register(this);

	//owner->addComponent<DebugHighlighter>(position, size, sf::Color::Red);
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
