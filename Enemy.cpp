#include "Enemy.h"

#include "AgentAI.h"
#include "BehaviourTree.h"
#include "Level.h"
#include "MoveToPointNode.h"
#include "SpriteRenderer.h"
#include "RigidBody.h"
#include "SequenceNode.h"
#include "WaitNode.h"

Enemy::Enemy(std::string name, GameWorld& gameWorld, Level* level): GameObject(name, gameWorld)
{
	this->setPosition(sf::Vector2f(96, 64));

	addComponent<SpriteRenderer>("Sprites/enemy128.png", sf::Vector2i(32, 32), 2);
	addComponent<BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(32, 32));
	addComponent<RigidBody>();

	AgentAI* agentAi = addComponent<AgentAI>(*level->GetMapAI());



	sf::Vector2f startPos = this->getPosition();
	sf::Vector2f targetPos = sf::Vector2f(100.f, 50.f);

	auto wait2 = std::make_shared<WaitNode>(1.f);
	auto moveToTarget = std::make_shared<MoveToPointNode>(agentAi, targetPos);
	auto wait = std::make_shared<WaitNode>(1.f);
	auto moveBack = std::make_shared<MoveToPointNode>(agentAi, startPos);

	auto sequence = std::make_shared<SequenceNode>();

	sequence->AddChild(wait);
	sequence->AddChild(moveToTarget);
	sequence->AddChild(wait);
	sequence->AddChild(moveBack);

	addComponent<BehaviourTree>(sequence);
}
