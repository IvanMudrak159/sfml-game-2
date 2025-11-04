#pragma once
#include "Component.h"


class Level;

class PlayerController : public Component
{
public:
	PlayerController(GameObject* owner, Level* level);
	void update(float dt) override;

private:
	sf::Vector2f velocity;
	float speed;
	RigidBody* rigidBody;


	bool wasLeftPressed = false;
	bool wasRightPressed = false;
	Level* level;
	void handleMovement();
	void handleMouseInput();

	void OnLeftMouseButtonPressed();
	void OnRightMouseButtonPressed();
};
