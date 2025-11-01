#include "RigidBody.h"

#include "GameWorld.h"

RigidBody::RigidBody(GameObject* owner, RigidbodyType t, float m): Component(owner), type(t), mass(m)
{
	owner->getGameWorld()->getPhysicsSystem().Register(this);
}

RigidBody::~RigidBody()
{
	owner->getGameWorld()->getPhysicsSystem().Unregister(this);
}

void RigidBody::applyForce(const sf::Vector2f& force)
{
	if (type == RigidbodyType::Dynamic)
	{
		velocity += force / mass;
	}
}

void RigidBody::setConstForce(const sf::Vector2f& force)
{
	if (type == RigidbodyType::Dynamic)
	{
		velocity = force;
	}
}


void RigidBody::update(float dt)
{
	Component::update(dt);

	if (type == RigidbodyType::Dynamic && owner)
	{
		owner->move(velocity * dt);
	}
}
