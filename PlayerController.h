#pragma once
#include "AgentAI.h"
#include "Component.h"

class Level;

class PlayerController : public Component
{
public:
	PlayerController(GameObject* owner, RigidBody& rb, Level* level);
	void Update(float dt) override;

private:
	sf::Vector2f velocity;
	float speed;
	RigidBody& rigidBody;


	bool wasLeftPressed = false;
	bool wasRightPressed = false;
	Level* level;
	AgentAI* agentAI;

	void handleMovement();
	void handleMouseInput();

	void OnLeftMouseButtonPressed();
	void OnRightMouseButtonPressed();
};
