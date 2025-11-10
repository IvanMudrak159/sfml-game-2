#pragma once
#include <vector>

#include "Components/BoxCollider.h"
#include "Components/RigidBody.h"


class PhysicsSystem
{
private:
	std::vector<BoxCollider*> colliders;
	std::vector<RigidBody*> rigidBodies;
	void resolveCollision(BoxCollider* a, BoxCollider* b);

public:
	PhysicsSystem();
	~PhysicsSystem();
	void update(float dt);

	void Register(BoxCollider* collider);
	void Unregister(BoxCollider* collider);

	void Register(RigidBody* rigidBody);
	void Unregister(RigidBody* rigidBody);
};
