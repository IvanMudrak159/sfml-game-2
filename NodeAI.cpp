#include "NodeAI.h"

float NodeAI::fCost() const
{
	return gCost + hCost;
}

NodeAI::NodeAI(const sf::Vector2f& pos, bool isWalkable) : position(pos), walkable(isWalkable)
{
}