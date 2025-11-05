#pragma once
#include "ActionNode.h"
#include <SFML/System/Vector2.hpp>

class AgentAI;

class MoveToPointNode : public ActionNode
{
public:
    MoveToPointNode(AgentAI* agent, const sf::Vector2f& target);

protected:
    void OnStart() override;
    NodeState OnTick(float dt, BlackBoard& bb) override;
    void OnEnd() override;

private:
    AgentAI* m_agent;
    sf::Vector2f m_target;
    bool m_started = false;
};
