#include "MoveToPointNode.h"
#include "AgentAI.h"

MoveToPointNode::MoveToPointNode(const std::string& name, AgentAI* agent, const sf::Vector2f& target)
	: ActionNode(name), m_agent(agent), m_target(target)
{
}

void MoveToPointNode::OnStart()
{
    if (m_agent)
    {
        m_agent->SetDestination(m_target);
        m_started = true;
    }
}

NodeState MoveToPointNode::OnTick(float dt, BlackBoard& bb)
{
    if (!m_agent)
    {
        return NodeState::Failure;
    }

    if (!m_started)
    {
        OnStart();
    }

    if (m_agent->HasPath())
        return NodeState::Running;

    return NodeState::Success;
}

void MoveToPointNode::OnEnd()
{
    if (m_agent)
    {
        m_agent->ClearPath();
    }
}
