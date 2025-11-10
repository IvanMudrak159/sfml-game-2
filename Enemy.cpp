#include "Enemy.h"

#include "AgentAI.h"
#include "BehaviourTree.h"
#include "ConditionNode.h"
#include "Level.h"
#include "MoveToPointNode.h"
#include "ParallelNode.h"
#include "SpriteRenderer.h"
#include "RigidBody.h"
#include "SequenceNode.h"
#include "WaitNode.h"
#include "Player.h"
#include "ScriptNode.h"
#include "SelectorNode.h"

Enemy::Enemy(const std::string& name, GameWorld& gameWorld, const Level* level): GameObject(name, gameWorld)
{
	this->setPosition(sf::Vector2f(96, 64));

	addComponent<SpriteRenderer>("Sprites/enemy128.png", sf::Vector2i(32, 32), 2);
	addComponent<BoxCollider>(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(32, 32));
	addComponent<RigidBody>();

	AgentAI* agentAi = addComponent<AgentAI>(*level->GetMapAI());

	sf::Vector2f startPos = this->getPosition();
	sf::Vector2f targetPos = sf::Vector2f(100.f, 50.f);

	// Patrol Sequence
	auto moveToTarget = std::make_shared<MoveToPointNode>("MoveToTarget", agentAi, targetPos);
	auto moveBack = std::make_shared<MoveToPointNode>("MoveBack", agentAi, startPos);

	auto patrolSequence = std::make_shared<SequenceNode>("patrolSequence");

	patrolSequence->AddChild(moveToTarget);
	patrolSequence->AddChild(std::make_shared<WaitNode>("Wait", 1.f));
	patrolSequence->AddChild(moveBack);
	patrolSequence->AddChild(std::make_shared<WaitNode>("Wait", 1.f));

	// ------

	// Search Lambdas
	auto searchPlayerLambda = [&gameWorld, this](BlackBoard& bb) -> bool
		{
			int radius = 64;
			auto objects = gameWorld.GetObjectsInRadius(this->getPosition(), radius);

			for (auto* obj : objects)
			{
				if (dynamic_cast<Player*>(obj))
				{
					bb.Set("target", obj);
					return true;
				}
			}

			return false;
		};
	auto searchDebug = [&gameWorld, this](sf::RenderTarget& target, const sf::RenderStates& states, BlackBoard&) -> void
		{
			int radius = 64;

			sf::Vector2f pos = this->getPosition();

			sf::CircleShape shape(radius);
			shape.setOrigin(sf::Vector2f(radius, radius));
			shape.setPosition(pos);

			shape.setFillColor(sf::Color(255, 0, 0, 50));

			target.draw(shape, states);
		};

	// ------

	// DestroyScheduledObjects Sequence

	auto destroyNode = std::make_shared<ScriptNode>("DestroyNode",
		[this](float dt, BlackBoard& bb) -> NodeState {
		Destroy();
		return NodeState::Success;
		}
	);

	auto destroySequence = std::make_shared<SequenceNode>("DestroySequence");

	destroySequence->AddChild(std::make_shared<WaitNode>("DestroyWait", 3.f));
	destroySequence->AddChild(destroyNode);

	// ------


	// Selector Node
	auto selector = std::make_shared<SelectorNode>("SelectorNode");
	auto SearchForPlayerNode = std::make_shared<ConditionNode>("SearchForPlayerNode", searchPlayerLambda, destroySequence, searchDebug);
	auto PatrolConditionNode = std::make_shared<ConditionNode>("PatrolConditionNode", [](BlackBoard& bb) { return true; }, patrolSequence);
	// --------------

	selector->AddChild(SearchForPlayerNode);
	selector->AddChild(PatrolConditionNode);

	BehaviourTree* tree = addComponent<BehaviourTree>(selector);
}
