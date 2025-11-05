#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

#include "MapAI.h"
#include "GameObject.h"

class AgentAI : public Component
{
public:
    AgentAI(GameObject* owner, MapAI& map, bool canPaintMap = false);

    void SetDestination(const sf::Vector2f& targetPos);
    void ClearPath();
	void SetMoveSpeed(float speed) { moveSpeed = speed; }
	void Update(float dt) override;
    bool HasPath() const;

private:
    MapAI& mapAI;
	bool m_canPaintMap;

    std::vector<sf::Vector2f> pathPositions;
    size_t currentTargetIndex = 0;
    float moveSpeed = 100.f;
};
