#include "BoxCollider.h"

#include "Debug.h"
#include "DebugHighlighter.h"
#include "GameObject.h"
#include "GameWorld.h"

BoxCollider::BoxCollider(GameObject* owner, sf::Vector2f position, sf::Vector2f size): Component(owner)
{
	sf::Vector2f adjustedPos = sf::Vector2f(position.x - size.x * 0.5f, position.y - size.y * 0.5f);

	boundingBox = sf::FloatRect
	(
		adjustedPos,
		size
	);

	owner->getGameWorld()->getPhysicsSystem().Register(this);

	if (Debug::isEnabled())
	{
		owner->addComponent<DebugHighlighter>(adjustedPos, size, sf::Color::Red);
	}
}

BoxCollider::~BoxCollider()
{
	owner->getGameWorld()->getPhysicsSystem().Unregister(this);
}

sf::FloatRect BoxCollider::getWorldBounds() const
{
	if (!owner) return boundingBox;

	sf::Vector2f ownerPos = owner->getPosition();

	return sf::FloatRect(
		sf::Vector2f(ownerPos.x + boundingBox.position.x, ownerPos.y + boundingBox.position.y),
		boundingBox.size
	);
}
