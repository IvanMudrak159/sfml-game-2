#pragma once
#include <SFML/System/Vector2.hpp>

#include "Components/Component.h"

class AgentAI;
class RigidBody;
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
