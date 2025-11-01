#pragma once
#include "Component.h"


class PlayerController : public Component
{
public:
	PlayerController(GameObject* owner);
	void update(float dt) override;

private:
	sf::Vector2f velocity;
	float speed;
	RigidBody* rigidBody;

	void handleInput();
};
