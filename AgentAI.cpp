#include "AgentAI.h"

#include "AStar.h"
#include "RigidBody.h"

AgentAI::AgentAI(GameObject* owner, MapAI& map): Component(owner), mapAI(map)
{
}

void AgentAI::SetDestination(const sf::Vector2f& targetPos)
{
    sf::Vector2f playerPos = owner->getPosition();
    auto getTileFromPosition = [&](sf::Vector2f pos) -> sf::Vector2i {
        return sf::Vector2i(
            static_cast<int>(pos.x) / mapAI.GetTileSize().x,
            static_cast<int>(pos.y) / mapAI.GetTileSize().y
        );
        };

    sf::Vector2i playerTile = getTileFromPosition(playerPos);
    sf::Vector2i mouseTile = getTileFromPosition(targetPos);

    if (mouseTile.x >= 0 && mouseTile.x < mapAI.GetLevelSize().x &&
        mouseTile.y >= 0 && mouseTile.y < mapAI.GetLevelSize().y)
    {
        mapAI.ClearPath();

        NodeAI* startNode = mapAI.GetNode(playerTile);
        NodeAI* goalNode = mapAI.GetNode(mouseTile);


        AStar astar;
        auto path = astar.findPath(startNode, goalNode);

        for (NodeAI* node : path)
        {
            node->isInPath = true;
            pathPositions.push_back(node->getPosition());
        }
    }
}

void AgentAI::ClearPath()
{
	mapAI.ClearPath();
	pathPositions.clear();
    currentTargetIndex = 0;

    if (RigidBody* rb = owner->getComponent<RigidBody>())
    {
        rb->setConstForce(sf::Vector2f(0.f, 0.f));
    }
}

void AgentAI::Update(float dt)
{
    Component::Update(dt);

    if (pathPositions.empty() || currentTargetIndex >= pathPositions.size())
    {
        ClearPath();
        return;
    }

    sf::Vector2f currentPos = owner->getPosition();
    sf::Vector2f targetPos = pathPositions[currentTargetIndex];

    sf::Vector2f direction = targetPos - currentPos;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 1.0f)
    {
        currentTargetIndex++;
        if (currentTargetIndex >= pathPositions.size())
        {
            ClearPath();
        	return;
        }
        targetPos = pathPositions[currentTargetIndex];
        direction = targetPos - currentPos;
        distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    }

    sf::Vector2f velocity = (direction / distance) * moveSpeed;

    RigidBody* rb = owner->getComponent<RigidBody>();
    if (rb)
    {
        rb->setConstForce(velocity);
    }
}
